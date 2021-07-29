
// ПЗ1-3 + ИПЗ
/*
#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include <conio.h>
#include <string.h>
// Блохнов Сергей

// Структура остановки
struct Stop {
	char *stopName;
	int ticketCost; // Цена билета до этой остановки
	int occSeats; // Занятые места 
	int date; // Дата остановки
	int time; // Время остановки
	struct Stop *next, *prev;
};
typedef struct Stop *PStop;

// Структура маршрута
typedef struct {
	PStop Head, Tail;
}Route;

// Структура рейса 
typedef struct
{
	char *company;
	int busNumber;
	int seatAmount;
	Route route;
}BusFlight;

// Структура билета
typedef struct
{
	char *stopStart; // Станция посадки
	char *stopFin; // Станция схода
	int ticketCost; // Цена билета
}Ticket;

// Структура клиента 
typedef struct
{
	char *fullName; // ФИО клиента
	char *adress;
	char *phoneNumber;
	char *eMail;
	Ticket *tickets; 
	int ticketsAm;
}Client;

// Динамический массив клиентов
typedef struct {
	Client *clients;
	int clientsAm;
}ClientsDB;

// Динамический массив рейсов
typedef struct {
	BusFlight *flights;
	int flightsAm;
}BusFDB;


// Получает новые рейсы из input.txt
void GetNewData(BusFDB *flightsDB)
{
	// В целом эта функция работает аналогично GetDataFromFile, 
	// Единственное отличие в том, что новые рейсы сразу добавляются в нужное место списка 

	printf("Считывание данных из input.txt...\n");
	char buffer[512];
	FILE *file;
	errno_t err;
	// Пытаемся открыть файл
	err = fopen_s(&file, "input.txt", "r");
	if (err != 0)
	{
		printf("Ошибка. Файл input.txt не найден.\nСоздание файла...");
		// Если файл не найден - создаём его
		err = fopen_s(&file, "input.txt", "w+t");
		if (err != 0)
			printf("\nОшибка. Файл не может быть создан.");
		else
			if (file)
			{
				err = fclose(file);
				if (err != 0)
					printf("\nОшибка при закрытии только что созданного файла\n");
				else
					printf("\nФайл input.txt успешно создан\n");
			}
	}
	else
	{
		fseek(file, 0, SEEK_END);
		long pos = ftell(file);
		rewind(file);
		while (!feof(file) && pos > 0)
		{
			// Создание нового массива и перенос данных в него перенесено в конец, 
			// так как при заполнении необходимо сравнение нового рейса с только что считанным

			BusFlight newFlight = { NULL }; // создаём переменную рейса
			fgets(buffer, 511, file); // Берем строку из файла
			char *token = NULL;
			char *temp = strtok_s(buffer, ";", &token); // "Отрезаем" от строки первую переменную по разделителю(;)
			// Выделяем память под строку и сохраняем её в переменную рейса как имя компании.
			char *compName = (char*)malloc(30 * sizeof(char));
			strcpy_s(compName, 30, temp);
			newFlight.company = compName;
			// Отрезаем, переводим в int, сохраняем
			int busNumber = atoi(strtok_s(token, ";", &token));
			newFlight.busNumber = busNumber;
			// То же самое
			int seatsAmount = atoi(strtok_s(token, ";", &token));
			newFlight.seatAmount = seatsAmount;
			// Создаём переменную маршрута
			Route busRoute = { NULL };
			int dataType = 0;
			// Извлекаем и создаём маршрут автобуса
			while (token[0] != 0 && token != NULL && token[0] != 10) // Так как по формату после данных остановок никаких более данных нет, мы считываем их, пока строка не закончится
			{
				PStop newStop = malloc(sizeof(struct Stop)); // Выделение памяти под новую остановку
				while (dataType != 4 && token[0] != 10 && token != 0)
				{
					switch (dataType)
					{
					case 0: // Извлечение названия остановки из строки данных и сохранение в структуре остановки
						temp = strtok_s(token, ";", &token);
						char *stopName = (char*)malloc(30 * sizeof(char));
						strcpy_s(stopName, 30, temp);
						newStop->stopName = stopName;
						break;
					case 1: // Извлечение и сохранение цены билета
						temp = strtok_s(token, ";", &token);
						int ticketCost = atoi(temp);
						newStop->ticketCost = ticketCost;
						break;
					case 2: // Извлечение и сохранение даты остановки
						temp = strtok_s(token, ";", &token);
						int date = atoi(temp);
						newStop->date = date;
						break;
					case 3: // Извлечение и сохранение времени остановки
						temp = strtok_s(token, ";", &token);
						int time = atoi(temp);
						newStop->time = time;
						newStop->occSeats = 0;
						break;
					}
					dataType++;
				}
				// Если это первая остановка, то делаем зациклинность и назначаем её и как "голову" и как "хвост".
				if (busRoute.Tail == NULL)
				{
					newStop->next = newStop;
					newStop->prev = newStop;
					busRoute.Head = newStop;
					busRoute.Tail = newStop;
				}
				else
				{
					if (busRoute.Tail == busRoute.Head) // Если это вторая остановка, то сначала необходимо убрать зациклинность первой
						busRoute.Head->prev = NULL;
					// Добавление остановки в конец
					newStop->next = NULL;
					newStop->prev = busRoute.Tail;
					busRoute.Tail->next = newStop;
					busRoute.Tail = newStop;
				}
				dataType = 0;
			}
			// Сохраняем маршрут в переменную рейса
			newFlight.route = busRoute;

			// Создаём новый массив рейсов
			int n = flightsDB->flightsAm;
			BusFlight *NewFlights;
			NewFlights = malloc((n + 1) * sizeof(BusFlight));
			int added = 0;
			if (n != 0) // Если в старом массиве уже были данные - переносим их в новый
				for (int i = 0, j = 0; i < (int)n; i++, j++)
				{
					// Новый рейс занимает место первого же, что больше его и сдвигает все рейсы в массиве на 1
					if (flightsDB->flights[i].busNumber > newFlight.busNumber && added == 0)
					{
						NewFlights[j] = newFlight; 
						i--;
						added = 1; // Своеобразная "bool" переменная, чтобы условие сработало лишь единожды. 
					}
					else
						NewFlights[j] = flightsDB->flights[i];
				}
			free(flightsDB->flights); // Удаляем старый массив из памяти
			if(added == 0) // Если новый рейс имеет самый большой номер или старый массив был путым
				NewFlights[n] = newFlight;
			// Обновляем базу
			flightsDB->flightsAm = flightsDB->flightsAm + 1;
			flightsDB->flights = NewFlights;
		}
		// Закрываем файл
		if (file)
		{
			err = fclose(file);
			if (err != 0)
			{
				printf("\nThe file was not closed\n");
			}
			else
			{
				printf("\nДанные успешно считаны.\n");
			}
		}
	}
}

// Сохранение данных из программы в файл data.txt 
void SaveDataToFile(BusFDB *flightsDB, ClientsDB *clientsDB)
{
	// Данные рейсов сохраняются в файле data.txt в формате:
	// CompanyName;busNumber;seatAmount;stop Name 1;ticketCost1;date1;time1;stop Name2;ticketCost2;date2;time2;...
	// Название Компании;Номер автобуса;Количество мест;Название остановки1;Цена билета до остановки1;Дата остановки1;Время остановки1;Название остановки2;...
	// ; - разделитель между данными
	// Один рейс - одна строка.

	printf("\nСохранение данных в data.txt...\n");
	FILE *file;
	errno_t err;
	// Создаём(открываем) файл с правами записи текста
	err = fopen_s(&file, "data.txt", "w+t");
	if (err != 0) // В случае возникновения проблем - выводим сообщение об ошибке
		printf("\nОшибка записи\n");
	else
	{
		// Перебираем массив рейсов
		for (int i = 0; i < flightsDB->flightsAm; i++)
		{
			if(i!=0)
				fprintf(file, "\n"); // Ставим "энтер", так как следующий рейс должен быть написан на следующей строке
			//Печатаем название компании, номер автобуса и количество мест в автобусе
			fprintf(file, "%s;%d;%d;", flightsDB->flights[i].company, flightsDB->flights[i].busNumber, flightsDB->flights[i].seatAmount);
			PStop stop = flightsDB->flights[i].route.Head;
			// Перебераем маршрут, записываем информацию о каждой остановке
			do
			{
				fprintf(file, "%s;%d;%d;%d;", stop->stopName, stop->ticketCost, stop->date, stop->time);
				stop = stop->next;
			}while (stop != NULL && stop->next != stop->prev);
		}
	}
	// Закрываем файл
	if (file)
	{
		err = fclose(file);
		if (err != 0)
		{
			printf("\nThe file was not closed\n");
		}
	}
	

	// Данные клиентов сохраняются в файле clientdata.txt в формате:
	// ФИО;адрес;номер телефона;электронная почта;количество билетов;Станция посадки 1;Станция схода 1;Цена билета 1; Станция посадки 2;...
	// Данный формат подобен формату по которому хранятся рейсы. ; - разделитель. 1 строка - 1 клиент.


	printf("\nСохранение данных в clientdata.txt...\n");
	// Создаём(открываем) файл с правами записи текста
	err = fopen_s(&file, "clientdata.txt", "w+t");
	if (err != 0) // В случае возникновения проблем - выводим сообщение об ошибке
		printf("\nОшибка записи\n");
	else
	{
		// Перебираем массив клиентов
		for (int j = 0; j < clientsDB->clientsAm; j++)
		{
			if (j != 0)
				fprintf(file, "\n"); // Ставим "энтер", так как следующий клиент должен быть написан на следующей строке
			//Печатаем ФИО, адрес, номер телефона, адрес электронной почты и количество билетов
			fprintf(file, "%s;%s;%s;%s;%d;", clientsDB->clients[j].fullName, clientsDB->clients[j].adress, clientsDB->clients[j].phoneNumber, clientsDB->clients[j].eMail, clientsDB->clients[j].ticketsAm);
			for (int k = 0; k < clientsDB->clients[j].ticketsAm; k++)
			{
				fprintf(file, "%s;%s;%d;", clientsDB->clients[j].tickets[k].stopStart, clientsDB->clients[j].tickets[k].stopFin, clientsDB->clients[j].tickets[k].ticketCost);
			}
		}
	}
	// Закрываем файл
	if (file)
	{
		err = fclose(file);
		if (err != 0)
		{
			printf("\nThe file was not closed\n");
		}
	}
}

// Получение данных из файла data.txt
void GetDataFromFile(BusFDB *flightsDB, ClientsDB *clientsDB)
{
	// Данные каждого рейса сохранены в файле data.txt в формате:
	// CompanyName;busNumber;seatAmount;stop Name 1;ticketCost1;date1;time1;stop Name2;ticketCost2;date2;time2;...
	// Название Компании;Номер автобуса;Количество мест;Название остановки1;Цена билета до остановки1;Дата остановки1;Время остановки1;Название остановки2;...
	// ; - разделитель между переменными

	printf("Считывание данных из data.txt...");
	char buffer[512];
	FILE *file;
	errno_t err;
	err = fopen_s(&file, "data.txt", "r");
	if (err != 0)
	{
		printf("Ошибка. Файл data.txt не найден.\nСоздание файла...");
		err = fopen_s(&file, "data.txt", "w+t");
		if (err != 0)
			printf("\nОшибка. Файл не может быть создан.");
		else
			if (file)
			{
				err = fclose(file);
				if (err != 0)
					printf("\nОшибка при закрытии только что созданного файла\n");
				else
					printf("\nФайл data.txt успешно создан\n");
			}
	}
	else
	{
		fseek(file, 0, SEEK_END);
		long pos = ftell(file);
		rewind(file);
		while (!feof(file) && pos>0)
		{
			// Создаём новый массив рейсов
			int n = flightsDB->flightsAm;
			BusFlight *NewFlights;
			NewFlights = malloc((n + 1) * sizeof(BusFlight));
			if (n != 0) // Если в старом массиве уже были данные - переносим их в новый
				for (int i = 0; i < (int)n; i++)
					NewFlights[i] = flightsDB->flights[i];
			free(flightsDB->flights); // Удаляем старый массив из памяти
			BusFlight newFlight = { NULL }; // создаём переменную рейса
			fgets(buffer, 511, file); // Берем строку из файла
			char *token = NULL;
			char *temp = strtok_s(buffer, ";", &token); // "Отрезаем" от строки первую переменную по разделителю(;)
			// Выделяем память под строку и сохраняем её в переменную рейса как имя компании.
			char *compName = (char*)malloc(30 * sizeof(char));
			strcpy_s(compName, 30, temp);
			newFlight.company = compName;
			// Отрезаем, переводим в int, сохраняем
			int busNumber = atoi(strtok_s(token, ";", &token));
			newFlight.busNumber = busNumber;
			// То же самое
			int seatsAmount = atoi(strtok_s(token, ";", &token));
			newFlight.seatAmount = seatsAmount;
			// Создаём переменную маршрута
			Route busRoute = { NULL };
			int dataType = 0;
			// Извлекаем и создаём маршрут автобуса
			while (token[0] != 0 && token != NULL && token[0] != 10) // Так как по формату после данных остановок никаких более данных нет, мы считываем их, пока строка не закончится
			{
				PStop newStop = malloc(sizeof(struct Stop)); // Выделение памяти под новую остановку
				while (dataType != 4 && token[0] != 10 && token != 0)
				{
					switch (dataType)
					{
					case 0: // Извлечение названия остановки из строки данных и сохранение в структуре остановки
						temp = strtok_s(token, ";", &token);
						char *stopName = (char*)malloc(30 * sizeof(char));
						strcpy_s(stopName, 30,temp);
						newStop->stopName = stopName;
						break;
					case 1: // Извлечение и сохранение цены билета
						temp = strtok_s(token, ";", &token);
						int ticketCost = atoi(temp);
						newStop->ticketCost = ticketCost;
						break;
					case 2: // Извлечение и сохранение даты остановки
						temp = strtok_s(token, ";", &token);
						int date = atoi(temp);
						newStop->date = date;
						break;
					case 3: // Извлечение и сохранение времени остановки
						temp = strtok_s(token, ";", &token);
						int time = atoi(temp);
						newStop->time = time;
						newStop->occSeats = 0;
						break;
					}
					dataType++;
				}
				// Если это первая остановка, то делаем зациклинность и назначаем её и как "голову" и как "хвост".
				if (busRoute.Tail == NULL)
				{
					newStop->next = newStop;
					newStop->prev = newStop;
					busRoute.Head = newStop;
					busRoute.Tail = newStop;
				}
				else
				{
					if (busRoute.Tail == busRoute.Head) // Если это вторая остановка, то сначала необходимо убрать зациклинность первой
						busRoute.Head->prev = NULL;
					// Добавление остановки в конец
					newStop->next = NULL;
					newStop->prev = busRoute.Tail;
					busRoute.Tail->next = newStop;
					busRoute.Tail = newStop;
				}
				dataType = 0;
			}
			// Сохраняем маршрут в переменную рейса
			newFlight.route = busRoute;

			// Сохраняем рейс в массив рейсов и обновляем базу
			NewFlights[n] = newFlight;
			flightsDB->flightsAm = flightsDB->flightsAm + 1;
			flightsDB->flights = NewFlights;
		}
		// Закрываем файл
		if (file)
		{
			err = fclose(file);
			if (err != 0)
			{
				printf("\nThe file was not closed\n");
			}
			else
			{
				printf("\nДанные успешно считаны.");
			}
		}
	}

	// Данные каждого клиента сохранены в файле clientdata.txt в формате:
	// ФИО;адрес;номер телефона;электронная почта;количество билетов;Станция посадки 1;Станция схода 1;Цена билета 1; Станция посадки 2;...
	// Данный формат подобен формату по которому хранятся рейсы. ; - разделитель. 1 строка - 1 клиент.

	printf("\nСчитывание данных из clientdata.txt...\n");
	err = fopen_s(&file, "clientdata.txt", "r");
	if (err != 0)
	{
		printf("Ошибка. Файл clientdata.txt не найден.\nСоздание файла...");
		err = fopen_s(&file, "clientdata.txt", "w+t");
		if (err != 0)
			printf("\nОшибка. Файл не может быть создан.");
		else
			if (file)
			{
				err = fclose(file);
				if (err != 0)
					printf("\nОшибка при закрытии только что созданного файла\n");
				else
					printf("\nФайл clientdata.txt успешно создан\n");
			}
	}
	else
	{
		fseek(file, 0, SEEK_END);
		long pos = ftell(file);
		rewind(file);
		while (!feof(file) && pos > 0)
		{
			// Создаём новый массив клиентов
			int n = clientsDB->clientsAm;
			Client *newClients;
			newClients = malloc((n + 1) * sizeof(Client));
			if (n != 0) // Если в старом массиве уже были данные - переносим их в новый
				for (int i = 0; i < (int)n; i++)
					newClients[i] = clientsDB->clients[i];
			free(clientsDB->clients); // Удаляем старый массив из памяти
			Client newClient = { NULL }; // создаём переменную клиента
			fgets(buffer, 511, file); // Берем строку из файла
			char *token = NULL;
			char *temp = strtok_s(buffer, ";", &token); // "Отрезаем" от строки первую переменную по разделителю(;)
			// Выделяем память под строку и сохраняем её в переменную клиента как его ФИО.
			char *fullName = (char*)malloc(60 * sizeof(char));
			strcpy_s(fullName, 60, temp);
			newClient.fullName = fullName;

			temp = strtok_s(token, ";", &token); // "Отрезаем" от строки первую переменную по разделителю(;)
			// Выделяем память под строку и сохраняем её в переменную клиента как его адрес.
			char *adress = (char*)malloc(128 * sizeof(char));
			strcpy_s(adress, 128, temp);
			newClient.adress = adress;

			// Выделяем память под строку и сохраняем её в переменную клиента как его номер телефона.
			temp = strtok_s(token, ";", &token);
			char *phoneNumber = (char*)malloc(15 * sizeof(char));
			strcpy_s(phoneNumber, 15, temp);
			newClient.phoneNumber = phoneNumber;
			// Выделяем память под строку и сохраняем её в переменную клиента как его EMail.
			temp = strtok_s(token, ";", &token);
			char *EMail = (char*)malloc(254 * sizeof(char));
			strcpy_s(EMail, 254, temp);
			newClient.eMail = EMail;
			// Отрезаем, переводим в int, сохраняем
			int ticketsAm = atoi(strtok_s(token, ";", &token));
			newClient.ticketsAm = ticketsAm;
			// Создаём переменную билета
			Ticket *tickets = malloc((ticketsAm) * sizeof(Client));
			int dataType = 0;
			// Извлекаем и заполняем массив билетов клиента
			for (int j = 0; j < ticketsAm; j++)
			{
				while (dataType != 4)
				{
					switch (dataType)
					{
					case 0:
						temp = strtok_s(token, ";", &token);
						char *startStopName = (char*)malloc(30 * sizeof(char));
						strcpy_s(startStopName, 30, temp);
						tickets[j].stopStart = startStopName;
						break;
					case 1: 
						temp = strtok_s(token, ";", &token);
						char *finStopName = (char*)malloc(30 * sizeof(char));
						strcpy_s(finStopName, 30, temp);
						tickets[j].stopFin = finStopName;
						break;
					case 3: 
						temp = strtok_s(token, ";", &token);
						int ticketCost = atoi(temp);
						tickets[j].ticketCost = ticketCost;
						break;
					}
					dataType++;
				}
				dataType = 0;
			}
			// Сохраняем массив билетов в клиента в переменную рейса
			newClient.tickets = tickets;

			// Сохраняем клиента в массив клиентов и обновляем базу
			newClients[n] = newClient;
			clientsDB->clientsAm = clientsDB->clientsAm + 1;
			clientsDB->clients = newClients;
		}
		// Закрываем файл
		if (file)
		{
			err = fclose(file);
			if (err != 0)
			{
				printf("\nThe file was not closed\n");
			}
			else
			{
				printf("Данные успешно считаны.\n");
			}
		}
	}
}

// Сортировка маршрутов прямым выбором по номеру автобуса
void SortFlights(BusFDB *flightsDB)
{
	int min;
	for (int i = 0; i < (flightsDB->flightsAm - 1); i++)
	{
		min = i;
		BusFlight temp;
		for (int j = i + 1; j < flightsDB->flightsAm; j++)
			if (flightsDB->flights[j].busNumber < flightsDB->flights[min].busNumber)
				min = j;
		temp = flightsDB->flights[i];
		flightsDB->flights[i] = flightsDB->flights[min];
		flightsDB->flights[min] = temp;
	}
}

// Отображение всего маршрута
int PrintRoute(Route *route)
{
	PStop stop = route->Head;
	int stopCounter = 0;
	do
	{
		if (stopCounter == 0)
			printf("%s ", stop->stopName);
		else
			printf("(%d) %s ", stopCounter, stop->stopName);
		stopCounter++;
		stop = stop->next;
	} while (stop != NULL && stop->next != stop->prev);

	return stopCounter;
}

// Отображение всего маршрута с подробной информацией о каждой остановке
int PrintStops(Route *route)
{
	PStop stop = route->Head;
	int stopCounter = 0;
	do
	{
		if (stopCounter == 0)
			printf("%d)\"%s\". Дата прибытия: %d. Время прибытия: %d. Занятые места: %d ", stopCounter + 1, stop->stopName, stop->date, stop->time, stop->occSeats);
		else
			printf("\n%d)\"%s\". Дата прибытия: %d. Время прибытия: %d. Занятых мест: %d. Цена билета: %d ", stopCounter + 1, stop->stopName, stop->date, stop->time, stop->occSeats, stop->ticketCost);
		stopCounter++;
		stop = stop->next;
	} while (stop != NULL && stop->next != stop->prev);

	return stopCounter;
}

// Вывод на экран списка рейсов
void PrintFlightsList(BusFDB *flightsDB)
{
	int n = flightsDB->flightsAm;
	if (n == 0)
		printf("\nСписок рейсов пуст\n");
	else
	{
		for (int i = 0; i < (int)n; i++)
			printf("Рейс #%d) Компания \"%s\", %s - %s. \nЗадействован автобус №%d\n", i + 1, flightsDB->flights[i].company, flightsDB->flights[i].route.Head->stopName, flightsDB->flights[i].route.Tail->stopName, flightsDB->flights[i].busNumber);
	}
}

// Вывод на экран данных о рейсе
void PrintFlight(BusFDB *flightsDB, int flightNumber)
{
	printf("\nКомпания: \"%s\". \nНомер автобуса: %d. \nМаксимальное количество мест: %d. \nПолный маршрут автобуса:\n", flightsDB->flights[flightNumber].company, flightsDB->flights[flightNumber].busNumber, flightsDB->flights[flightNumber].seatAmount);
	int n = PrintRoute(&(flightsDB->flights[flightNumber].route));
	printf("\nАвтобус совершает остановок: %d\n", n);
}

// Вывод на экран списка клиентов
void PrintClientsList(ClientsDB *clientsDB)
{
	printf("\nСписок клиентов:");
	if (clientsDB->clientsAm == 0)
		printf("\nСписок клиентов пуст\n");
	else
	{
		for (int i = 0; i < clientsDB->clientsAm; i++)
		{
			printf("\n%d) %s, адрес: %s\nКонтактная информация:\nНомер телефона: %s\nАдрес электронной почты: %s", i + 1, clientsDB->clients[i].fullName, clientsDB->clients[i].adress, clientsDB->clients[i].phoneNumber, clientsDB->clients[i].eMail);
			printf("\nИстория приобретенных билетов: ");
			if (clientsDB->clients[i].ticketsAm != 0)
				for (int j = 0; j < clientsDB->clients[i].ticketsAm; j++)
					printf("\n%d. %s - %s. Цена: %d р.", j + 1, clientsDB->clients[i].tickets[j].stopStart, clientsDB->clients[i].tickets[j].stopFin, clientsDB->clients[i].tickets[j].ticketCost);
			else
				printf("\nКлиент ещё не приобретал билетов");
		}
	}
}

// Добавление первой остановки маршрута
void AddStopFirst(Route *route)
{
	PStop newStop = malloc(sizeof(struct Stop));
	printf("\nВведите название остановки: ");
	char *stopName1 = (char*)malloc(30 * sizeof(char));
	scanf_s("%s", stopName1, 30);
	newStop->stopName = stopName1;
	printf("Введите дату посадки: ");
	int dateStop = 0;
	scanf_s("%d", &dateStop);
	newStop->date = dateStop;
	printf("Введите время посадки: ");
	int timeStop = 0;
	scanf_s("%d", &timeStop);
	newStop->time = timeStop;
	newStop->occSeats = 0;
	newStop->ticketCost = 0;
	if (route->Head != NULL)
	{
		newStop->prev = NULL;
		newStop->next = route->Head;
		route->Head = newStop;
	}
	else
	{
		newStop->next = newStop;
		newStop->prev = newStop;
		route->Head = newStop;
		route->Tail = newStop;
	}
	printf("\nПункт отправления назначен успешно.");
}

// Добавление последней остановки маршрута
void AddStopLast(Route *route)
{
	PStop newStop = malloc(sizeof(struct Stop));
	printf("\nВведите название остановки: ");
	char *stopName2 = (char*)malloc(30 * sizeof(char));
	scanf_s("%s", stopName2, 30);
	newStop->stopName = stopName2;
	printf("Введите дату прибытия: ");
	int dateStop = 0;
	scanf_s("%d", &dateStop);
	newStop->date = dateStop;
	printf("Введите время прибытия: ");
	int timeStop = 0;
	scanf_s("%d", &timeStop);
	newStop->time = timeStop;
	printf("Введите цену билета до этой остановки: ");
	int ticketCost = 0;
	scanf_s("%d", &ticketCost);
	newStop->ticketCost = ticketCost;
	newStop->occSeats = 0;
	if (route->Tail != NULL)
	{
		newStop->next = NULL;
		newStop->prev = route->Tail;
		route->Tail->next = newStop;
		route->Tail = newStop;
	}
	else
	{
		newStop->next = newStop;
		newStop->prev = newStop;
		route->Head = newStop;
		route->Tail = newStop;
	}

	printf("\nПункт прибытия назначен успешно.");
}

// Добавление промежуточной остановки
void AddStopMid(Route *route)
{
	int stopsAmount = PrintRoute(route);
	printf("\nВведите куда хотите вставить промежуточную остановку.");
	int slot = 0;
	scanf_s("%d", &slot);
	if (slot < stopsAmount)
	{
		PStop stop = route->Head;
		for(int i = 0; (slot-1) > i; i++)
		{
			stop = stop->next;
		}
		printf("\nЗаполните информацию о промежуточной остановке. ");
		
		PStop newStop = malloc(sizeof(struct Stop));
		printf("\nВведите название остановки: ");
		char *stopName = (char*)malloc(30 * sizeof(char));
		scanf_s("%s", stopName, 30);
		newStop->stopName = stopName;
		printf("Введите дату посадки: ");
		int dateStop = 0;
		scanf_s("%d", &dateStop);
		newStop->date = dateStop;
		printf("Введите время посадки: ");
		int timeStop = 0;
		scanf_s("%d", &timeStop);
		newStop->time = timeStop;
		printf("Введите цену билета: ");
		int ticketCost = 0;
		scanf_s("%d", &ticketCost);
		newStop->ticketCost = ticketCost;
		newStop->occSeats = 0;
		newStop->next = stop->next;
		newStop->prev = stop;
		stop->next->prev = newStop;
		stop->next = newStop;
		printf("\nПромежуточная остановка успешно добавлена");
	}
	else
	{
		printf("\nERROR\n");
	}
}

// Редактирование данных остановки
void EditStop(Route *route)
{
	printf("\nСписок остановок этого маршрута:\n");
	PrintStops(route);
	printf("\nВведите номер остановки: ");
	int userAnsw = 0;
	scanf_s("%d", &userAnsw);
	PStop stop = route->Head;
	for (int i = 1; i < userAnsw; i++)
	{
		stop = stop->next;
	}
	printf("\n1)Изменить название остановки\n2)Изменить дату прибытия\n3)Изменить время прибытия\n4)Изменить цену билета\n5)Удалить остановку\n0)Выход");
	printf("\n_____________________________________________\nВвод: ");
	userAnsw = 0;
	scanf_s("%d", &userAnsw);
	switch (userAnsw)
	{
	case 1:
		printf("\nВведите новое название: ");
		char *newName = (char*)malloc(30 * sizeof(char));
		scanf_s("%s", newName, 30);
		if (stop->stopName != "Неизвестно")
			free(stop->stopName);
		stop->stopName = newName;
		break;
	case 2:
		printf("\nВведите новую дату прибытия: ");
		int newDate = 0;
		scanf_s("%d", &newDate);
		stop->date = newDate;
		break;
	case 3:
		printf("\nВведите новое время прибытия: ");
		int newTime = 0;
		scanf_s("%d", &newTime);
		stop->time = newTime;
		break;
	case 4:
		printf("\nВведите новую цену билета: ");
		int newCost = 0;
		scanf_s("%d", &newCost);
		stop->ticketCost = newCost;
		break;
	case 5:
		printf("\nВы уверены? \n1)Да \n2)Нет");
		printf("\n_____________________________________________\nВвод: ");
		int userAnsw = 0;
		scanf_s("%d", &userAnsw);
		if (userAnsw==1)
		{
			if (stop->prev != NULL && stop->next!=NULL && stop->next != stop->prev)
			{
				stop->prev->next = stop->next;
				stop->next->prev = stop->prev;
				free(stop);
			}
			else if (stop->prev == NULL)
			{
				stop->next->prev = NULL;
				route->Head = stop->next;
				free(stop);
			}
			else if (stop->next == NULL)
			{
				stop->prev->next = NULL;
				route->Tail = stop->prev;
				free(stop);
			}
			else
			{
				printf("\nНевозможно удалить единственную остановку на маршруте\n");
			}
		}
		break;
	case 0:
		// Выход
		break;
	default:
		userAnsw = 11;
		break;
	}
}

// Добавление рейса
void AddFlights(BusFDB *flightsDB)
{
	int n = flightsDB->flightsAm;
	BusFlight *NewFlights;
	NewFlights = malloc((n + 1) * sizeof(BusFlight));
	if (n != 0)
		for (int i = 0; i < (int)n; i++)
		{
			NewFlights[i] = flightsDB->flights[i];
		}
	free(flightsDB->flights);
	printf("\nВы желаете заполнить данные рейса сейчас или позже?\n1) Сейчас\n2) Позже\n");
	printf("\n_____________________________________________\nВвод: ");
	int userAnsw = 0;
	scanf_s("%d", &userAnsw);
	BusFlight newFlight = { NULL };
	switch (userAnsw)
	{
	case 1:
		printf("\nЗаполнение данных рейса.");
		printf("\nВведите название компании-перевозчика: ");
		char *compName = (char*)malloc(30 * sizeof(char));
		scanf_s("%s", compName, 30);
		newFlight.company = compName;
		printf("Введите номер автобуса: ");
		int busNum = 0;
		scanf_s("%d", &busNum);
		newFlight.busNumber = busNum;
		printf("Введите количество мест в автобусе: ");
		int seatsAm = 0;
		scanf_s("%d", &seatsAm);
		newFlight.seatAmount = seatsAm;
		printf("\nЗаполнение маршрута.");
		Route busRoute = { NULL };
		printf("\nЗаполните информацию о отправлении.");
		AddStopFirst(&busRoute);
		printf("\n\nЗаполните информацию о прибытии.");
		AddStopLast(&busRoute);
		printf("\n\nДобавить промежуточные остановки? \n1) Да\n2) Нет\n");
		do {
			userAnsw = 0;
			scanf_s("%d", &userAnsw);
			switch (userAnsw)
			{
			case 1:
				AddStopMid(&busRoute);
				printf("\nДобавить ещё промежуточных остановок? \n1) Да\n2) Нет\n");
				break;

			default:
				printf("\nПри необходимости вы можете добавить промежуточные остановки рейса в меню изменения данных рейса.\n");
				break;
			}
		} while (userAnsw == 1);
		newFlight.route = busRoute;
		break;
	default:
		printf("\nВы можете заполнить данные рейса в меню изменения данных рейса.\n");
		// Заполняем данные рейса плейсхолдерами
		newFlight.company = "Неизвестно";
		newFlight.busNumber = 0;
		PStop newStop = malloc(sizeof(struct Stop));
		newStop->stopName = "Неизвестно";
		newStop->ticketCost = 0;
		newStop->time = 0;
		newStop->date = 0;
		newStop->next = newStop;
		newStop->prev = newStop;
		newStop->occSeats = 0;
		Route nullRoute = { newStop, newStop };
		newFlight.route = nullRoute;
		newFlight.seatAmount = 0;
		break;
	}

	printf("\nНовый рейс успешно добавлен.\n");
	NewFlights[n] = newFlight;
	flightsDB->flightsAm = flightsDB->flightsAm + 1;
	flightsDB->flights = NewFlights;
}

// Редактор списка рейсов
void FlightsEditor(BusFDB *flightsDB)
{
	int userAnsw = 11;
	do{
	printf("\nРедактирование списка рейсов.");
	printf("\n1)Изменить данные существующего рейса\n2)Добавить новый рейс\n0)Выход");
	printf("\n_____________________________________________\nВвод: ");
	userAnsw = 11;
	scanf_s("%d", &userAnsw);
	switch (userAnsw)
	{
	case 1:
		do {
		PrintFlightsList(flightsDB);
		if (flightsDB->flightsAm == 0)
		{
			printf("\n0)Выход");
			printf("\n_____________________________________________\nВвод: ");
			userAnsw = 0;
			scanf_s("%d", &userAnsw);
		}
		else
		{
			printf("\nВведите номер рейса, что хотите изменить");
			printf("\n_____________________________________________\nВвод: ");
			userAnsw = 0;
			scanf_s("%d", &userAnsw);
			if (userAnsw <= flightsDB->flightsAm && userAnsw > 0)
			{
				int n = userAnsw-1;
				do {
					PrintFlight(flightsDB, n);
					printf("\n1)Изменить название компании-перевозчика\n2)Изменить номер автобуса\n3)Изменить количество мест в автобусе\n4)Редактировать маршрут\n0)Выход");
					printf("\n_____________________________________________\nВвод: ");
					userAnsw = 0;
					scanf_s("%d", &userAnsw);
					switch (userAnsw)
					{
					case 1:
						printf("\nВведите новое название: ");
						char *newName = (char*)malloc(30 * sizeof(char));
						scanf_s("%s", newName, 30);
						if(flightsDB->flights[n].company != "Неизвестно")
							free(flightsDB->flights[n].company);
						flightsDB->flights[n].company = newName;
					break;
					case 2:
						printf("\nВведите новый номер: ");
						int newNum = 0;
						scanf_s("%d", &newNum);
						flightsDB->flights[n].busNumber = newNum;
						break;
					case 3:
						printf("\nВведите новое количество мест: ");
						int newAm = 0;
						scanf_s("%d", &newAm);
						flightsDB->flights[n].seatAmount = newAm;
						break;
					case 4:
						do{
						printf("\n1)Добавить остановку в начале пути\n2)Добавить остановку в конце пути\n3)Добавить промежуточную остановку\n4)Изменить данные одной из остановок\n0)Выход");
						printf("\n_____________________________________________\nВвод: ");
						userAnsw = 0;
						scanf_s("%d", &userAnsw);
						switch (userAnsw)
						{
						case 1:
							AddStopFirst(&flightsDB->flights[n].route);
							break;
						case 2:
							AddStopLast(&flightsDB->flights[n].route);
							break;
						case 3:
							AddStopMid(&flightsDB->flights[n].route);
							break;
						case 4:
							EditStop(&flightsDB->flights[n].route);
							break;
						case 0:
							// Выход
							break;
						default:
							userAnsw = 11;
							break;
						}
						} while (userAnsw != 0);
						break;
					case 0: 
						// Выход
						break;
					default:
						userAnsw = 11;
						break;
					}
				} while (userAnsw != 0);
			}
			else
				printf("\nРейса под таким номером не существует");
		}
		} while (userAnsw !=0);
		break;
	case 2:
		AddFlights(flightsDB);
		break;
	default:
		userAnsw = 11;
		break;
	case 0:
		// Выход
		break;
	}
	} while (userAnsw != 0);
}

// Редактор информации о клиенте
void ClientEditor(ClientsDB *clientsDB, BusFDB *flightsDB)
{
	int userAnswer = 11;
	printf("\nВведите номер клиента, информацию о котором хотите изменить: ");
	PrintClientsList(clientsDB);
	scanf_s("%d", &userAnswer);
	if (userAnswer > clientsDB->clientsAm)
	{
		printf("\nТакого клиента не существует");
	}
	else {
	Client *client = &clientsDB->clients[userAnswer];
	printf("\nИзменение данных клиента.");
	int userAnsw = 0;
	printf("\nМеню:\n1)Изменить ФИО\n2)Изменить адрес проживания\n3)Изменить номер телефона\n4)Изменить e-mail\n5)Назначить билет\n0)Выход");
	printf("\n_____________________________________________\nВвод: ");
	scanf_s("%d", &userAnsw);
	switch (userAnsw)
	{
	case 1:
		printf("\nВведите новое ФИО: ");
		char *newData = (char*)malloc(60 * sizeof(char));
		scanf_s("%s", newData, 60);
		free(client->fullName);
		client->fullName = newData;
		break;
	case 2:
		printf("\nВведите новый адрес: ");
		char *newData1 = (char*)malloc(60 * sizeof(char));
		scanf_s("%s", newData1, 60);
		free(client->adress);
		client->adress = newData1;
		break;
	case 3:
		printf("\nВведите новый номер телефона: ");
		char *newData2 = (char*)malloc(20 * sizeof(char));
		scanf_s("%s", newData2, 20);
		free(client->phoneNumber);
		client->phoneNumber = newData2;
		break;
	case 4:
		printf("\nВведите новый e-mail: ");
		char *newData3 = (char*)malloc(60 * sizeof(char));
		scanf_s("%s", newData3, 60);
		free(client->phoneNumber);
		client->phoneNumber = newData3;
		break;
	case 5:
		printf("\nВыберите рейс на который приобретён билет(0 - выход):\n");
		PrintFlightsList(flightsDB);
		userAnsw = 11;
		scanf_s("%d", &userAnsw);
		switch (userAnsw)
		{
		case 0:
			// выход
			break;
		default:
			if (userAnsw > flightsDB->flightsAm)
				printf("\nТакого рейса не существует\n");
			else
			{
				printf("\nВыберите остановку до которой приобретён билет:\n");
				int stopAm = PrintStops(&flightsDB->flights[userAnsw-1].route);
				int temp = userAnsw-1;
				printf("\n");
				scanf_s("%d", &userAnsw);
				if (userAnsw > stopAm)
					printf("\nТакой остановки не существует");
				else
				{
					PStop stop = flightsDB->flights[temp].route.Head;
					for (int i = 0; i < userAnsw-1; i++)
					{
						stop = stop->next;
					}
					Ticket newTicket = {flightsDB->flights[temp].route.Head->stopName, stop->stopName, stop->ticketCost};
					int n = client->ticketsAm;
					Ticket *newTickets;
					newTickets = malloc((n + 1) * sizeof(Ticket));
					if (n != 0)
						for (int i = 0; i < (int)n; i++)
						{
							newTickets[i] = client->tickets[i];
						}
					free(client->tickets);
					printf("\nБилет успешно добавлен клиенту\n");
					newTickets[n] = newTicket;
					client->tickets = newTickets;
					client->ticketsAm = client->ticketsAm+1;
				}
			}
			break;
		}
		break;
	case 0:
		// Выход
		break;
	default:
		userAnsw = 11;
		break;
	}
	}
}

void main()
{
	setlocale(LC_ALL, "RUS");
	BusFlight *flights = { NULL };
	BusFDB flightsDB = { flights, 0 };
	Client *client = { NULL };
	ClientsDB clientsDB = { client, 0 };
	GetDataFromFile(&flightsDB, &clientsDB);
	SortFlights(&flightsDB);
	int userAnsw = 11;
	do{
	userAnsw = 11;
	printf("\nДобро пожаловать в систему информации о автобусных рейсах и билетах.");
	printf("\nМеню:\n1)Получение списка рейсов\n2)Получение информации о клиенте\n3)Редактирование данных\n0)Выход");
	printf("\n_____________________________________________\nВвод: ");
	scanf_s("%d", &userAnsw);
	switch (userAnsw)
	{
	case 1:
		PrintFlightsList(&flightsDB);
		userAnsw = 11;
		printf("\nВведите номер рейса для получения подробной информации или 0 для выхода.\n_____________________________________________\nВвод: ");
		scanf_s("%d", &userAnsw);
		if (userAnsw != 0 && userAnsw <= flightsDB.flightsAm)
			PrintFlight(&flightsDB, userAnsw - 1);
		else
			userAnsw = 11;
		break;
	case 2:
		PrintClientsList(&clientsDB);
		break;
	case 3:
		printf("\n1)Редактирование данных клиента\n2)Редактирование рейсов\n3)Обновить данные из data.txt и clientdata.txt\n4)Отсортировать список рейсов по номеру автобуса\n5)Сохранить список рейсов в файл data.txt и список клиентов в clientdata.txt\n6)Получить новые рейсы из input.txt\n0)Выход");
		printf("\n_____________________________________________\nВвод: ");
		userAnsw = 11;
		scanf_s("%d", &userAnsw);
		switch (userAnsw)
		{
		case 1:
			ClientEditor(&clientsDB, &flightsDB);
			break;
		case 2:
			FlightsEditor(&flightsDB);
			break;
		case 3:
			GetDataFromFile(&flightsDB, &clientsDB);
			break;
		case 4:
			SortFlights(&flightsDB);
			break;
		case 5:
			SaveDataToFile(&flightsDB, &clientsDB);
			break;
		case 6:
			GetNewData(&flightsDB);
			break;
		case 0: 
			// Выход
			break;
		default:
			userAnsw = 11;
			break;
		}
		break;
	case 0:
		printf("\n\nЗавершение работы...\n\n");
		break;
	default:
		userAnsw = 11;
		break;
	}
	}while (userAnsw!=0);
}
*/

