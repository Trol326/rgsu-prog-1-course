
// ��1-3 + ���
/*
#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include <conio.h>
#include <string.h>
// ������� ������

// ��������� ���������
struct Stop {
	char *stopName;
	int ticketCost; // ���� ������ �� ���� ���������
	int occSeats; // ������� ����� 
	int date; // ���� ���������
	int time; // ����� ���������
	struct Stop *next, *prev;
};
typedef struct Stop *PStop;

// ��������� ��������
typedef struct {
	PStop Head, Tail;
}Route;

// ��������� ����� 
typedef struct
{
	char *company;
	int busNumber;
	int seatAmount;
	Route route;
}BusFlight;

// ��������� ������
typedef struct
{
	char *stopStart; // ������� �������
	char *stopFin; // ������� �����
	int ticketCost; // ���� ������
}Ticket;

// ��������� ������� 
typedef struct
{
	char *fullName; // ��� �������
	char *adress;
	char *phoneNumber;
	char *eMail;
	Ticket *tickets; 
	int ticketsAm;
}Client;

// ������������ ������ ��������
typedef struct {
	Client *clients;
	int clientsAm;
}ClientsDB;

// ������������ ������ ������
typedef struct {
	BusFlight *flights;
	int flightsAm;
}BusFDB;


// �������� ����� ����� �� input.txt
void GetNewData(BusFDB *flightsDB)
{
	// � ����� ��� ������� �������� ���������� GetDataFromFile, 
	// ������������ ������� � ���, ��� ����� ����� ����� ����������� � ������ ����� ������ 

	printf("���������� ������ �� input.txt...\n");
	char buffer[512];
	FILE *file;
	errno_t err;
	// �������� ������� ����
	err = fopen_s(&file, "input.txt", "r");
	if (err != 0)
	{
		printf("������. ���� input.txt �� ������.\n�������� �����...");
		// ���� ���� �� ������ - ������ ���
		err = fopen_s(&file, "input.txt", "w+t");
		if (err != 0)
			printf("\n������. ���� �� ����� ���� ������.");
		else
			if (file)
			{
				err = fclose(file);
				if (err != 0)
					printf("\n������ ��� �������� ������ ��� ���������� �����\n");
				else
					printf("\n���� input.txt ������� ������\n");
			}
	}
	else
	{
		fseek(file, 0, SEEK_END);
		long pos = ftell(file);
		rewind(file);
		while (!feof(file) && pos > 0)
		{
			// �������� ������ ������� � ������� ������ � ���� ���������� � �����, 
			// ��� ��� ��� ���������� ���������� ��������� ������ ����� � ������ ��� ���������

			BusFlight newFlight = { NULL }; // ������ ���������� �����
			fgets(buffer, 511, file); // ����� ������ �� �����
			char *token = NULL;
			char *temp = strtok_s(buffer, ";", &token); // "��������" �� ������ ������ ���������� �� �����������(;)
			// �������� ������ ��� ������ � ��������� � � ���������� ����� ��� ��� ��������.
			char *compName = (char*)malloc(30 * sizeof(char));
			strcpy_s(compName, 30, temp);
			newFlight.company = compName;
			// ��������, ��������� � int, ���������
			int busNumber = atoi(strtok_s(token, ";", &token));
			newFlight.busNumber = busNumber;
			// �� �� �����
			int seatsAmount = atoi(strtok_s(token, ";", &token));
			newFlight.seatAmount = seatsAmount;
			// ������ ���������� ��������
			Route busRoute = { NULL };
			int dataType = 0;
			// ��������� � ������ ������� ��������
			while (token[0] != 0 && token != NULL && token[0] != 10) // ��� ��� �� ������� ����� ������ ��������� ������� ����� ������ ���, �� ��������� ��, ���� ������ �� ����������
			{
				PStop newStop = malloc(sizeof(struct Stop)); // ��������� ������ ��� ����� ���������
				while (dataType != 4 && token[0] != 10 && token != 0)
				{
					switch (dataType)
					{
					case 0: // ���������� �������� ��������� �� ������ ������ � ���������� � ��������� ���������
						temp = strtok_s(token, ";", &token);
						char *stopName = (char*)malloc(30 * sizeof(char));
						strcpy_s(stopName, 30, temp);
						newStop->stopName = stopName;
						break;
					case 1: // ���������� � ���������� ���� ������
						temp = strtok_s(token, ";", &token);
						int ticketCost = atoi(temp);
						newStop->ticketCost = ticketCost;
						break;
					case 2: // ���������� � ���������� ���� ���������
						temp = strtok_s(token, ";", &token);
						int date = atoi(temp);
						newStop->date = date;
						break;
					case 3: // ���������� � ���������� ������� ���������
						temp = strtok_s(token, ";", &token);
						int time = atoi(temp);
						newStop->time = time;
						newStop->occSeats = 0;
						break;
					}
					dataType++;
				}
				// ���� ��� ������ ���������, �� ������ ������������� � ��������� � � ��� "������" � ��� "�����".
				if (busRoute.Tail == NULL)
				{
					newStop->next = newStop;
					newStop->prev = newStop;
					busRoute.Head = newStop;
					busRoute.Tail = newStop;
				}
				else
				{
					if (busRoute.Tail == busRoute.Head) // ���� ��� ������ ���������, �� ������� ���������� ������ ������������� ������
						busRoute.Head->prev = NULL;
					// ���������� ��������� � �����
					newStop->next = NULL;
					newStop->prev = busRoute.Tail;
					busRoute.Tail->next = newStop;
					busRoute.Tail = newStop;
				}
				dataType = 0;
			}
			// ��������� ������� � ���������� �����
			newFlight.route = busRoute;

			// ������ ����� ������ ������
			int n = flightsDB->flightsAm;
			BusFlight *NewFlights;
			NewFlights = malloc((n + 1) * sizeof(BusFlight));
			int added = 0;
			if (n != 0) // ���� � ������ ������� ��� ���� ������ - ��������� �� � �����
				for (int i = 0, j = 0; i < (int)n; i++, j++)
				{
					// ����� ���� �������� ����� ������� ��, ��� ������ ��� � �������� ��� ����� � ������� �� 1
					if (flightsDB->flights[i].busNumber > newFlight.busNumber && added == 0)
					{
						NewFlights[j] = newFlight; 
						i--;
						added = 1; // ������������ "bool" ����������, ����� ������� ��������� ���� ��������. 
					}
					else
						NewFlights[j] = flightsDB->flights[i];
				}
			free(flightsDB->flights); // ������� ������ ������ �� ������
			if(added == 0) // ���� ����� ���� ����� ����� ������� ����� ��� ������ ������ ��� �����
				NewFlights[n] = newFlight;
			// ��������� ����
			flightsDB->flightsAm = flightsDB->flightsAm + 1;
			flightsDB->flights = NewFlights;
		}
		// ��������� ����
		if (file)
		{
			err = fclose(file);
			if (err != 0)
			{
				printf("\nThe file was not closed\n");
			}
			else
			{
				printf("\n������ ������� �������.\n");
			}
		}
	}
}

// ���������� ������ �� ��������� � ���� data.txt 
void SaveDataToFile(BusFDB *flightsDB, ClientsDB *clientsDB)
{
	// ������ ������ ����������� � ����� data.txt � �������:
	// CompanyName;busNumber;seatAmount;stop Name 1;ticketCost1;date1;time1;stop Name2;ticketCost2;date2;time2;...
	// �������� ��������;����� ��������;���������� ����;�������� ���������1;���� ������ �� ���������1;���� ���������1;����� ���������1;�������� ���������2;...
	// ; - ����������� ����� �������
	// ���� ���� - ���� ������.

	printf("\n���������� ������ � data.txt...\n");
	FILE *file;
	errno_t err;
	// ������(���������) ���� � ������� ������ ������
	err = fopen_s(&file, "data.txt", "w+t");
	if (err != 0) // � ������ ������������� ������� - ������� ��������� �� ������
		printf("\n������ ������\n");
	else
	{
		// ���������� ������ ������
		for (int i = 0; i < flightsDB->flightsAm; i++)
		{
			if(i!=0)
				fprintf(file, "\n"); // ������ "�����", ��� ��� ��������� ���� ������ ���� ������� �� ��������� ������
			//�������� �������� ��������, ����� �������� � ���������� ���� � ��������
			fprintf(file, "%s;%d;%d;", flightsDB->flights[i].company, flightsDB->flights[i].busNumber, flightsDB->flights[i].seatAmount);
			PStop stop = flightsDB->flights[i].route.Head;
			// ���������� �������, ���������� ���������� � ������ ���������
			do
			{
				fprintf(file, "%s;%d;%d;%d;", stop->stopName, stop->ticketCost, stop->date, stop->time);
				stop = stop->next;
			}while (stop != NULL && stop->next != stop->prev);
		}
	}
	// ��������� ����
	if (file)
	{
		err = fclose(file);
		if (err != 0)
		{
			printf("\nThe file was not closed\n");
		}
	}
	

	// ������ �������� ����������� � ����� clientdata.txt � �������:
	// ���;�����;����� ��������;����������� �����;���������� �������;������� ������� 1;������� ����� 1;���� ������ 1; ������� ������� 2;...
	// ������ ������ ������� ������� �� �������� �������� �����. ; - �����������. 1 ������ - 1 ������.


	printf("\n���������� ������ � clientdata.txt...\n");
	// ������(���������) ���� � ������� ������ ������
	err = fopen_s(&file, "clientdata.txt", "w+t");
	if (err != 0) // � ������ ������������� ������� - ������� ��������� �� ������
		printf("\n������ ������\n");
	else
	{
		// ���������� ������ ��������
		for (int j = 0; j < clientsDB->clientsAm; j++)
		{
			if (j != 0)
				fprintf(file, "\n"); // ������ "�����", ��� ��� ��������� ������ ������ ���� ������� �� ��������� ������
			//�������� ���, �����, ����� ��������, ����� ����������� ����� � ���������� �������
			fprintf(file, "%s;%s;%s;%s;%d;", clientsDB->clients[j].fullName, clientsDB->clients[j].adress, clientsDB->clients[j].phoneNumber, clientsDB->clients[j].eMail, clientsDB->clients[j].ticketsAm);
			for (int k = 0; k < clientsDB->clients[j].ticketsAm; k++)
			{
				fprintf(file, "%s;%s;%d;", clientsDB->clients[j].tickets[k].stopStart, clientsDB->clients[j].tickets[k].stopFin, clientsDB->clients[j].tickets[k].ticketCost);
			}
		}
	}
	// ��������� ����
	if (file)
	{
		err = fclose(file);
		if (err != 0)
		{
			printf("\nThe file was not closed\n");
		}
	}
}

// ��������� ������ �� ����� data.txt
void GetDataFromFile(BusFDB *flightsDB, ClientsDB *clientsDB)
{
	// ������ ������� ����� ��������� � ����� data.txt � �������:
	// CompanyName;busNumber;seatAmount;stop Name 1;ticketCost1;date1;time1;stop Name2;ticketCost2;date2;time2;...
	// �������� ��������;����� ��������;���������� ����;�������� ���������1;���� ������ �� ���������1;���� ���������1;����� ���������1;�������� ���������2;...
	// ; - ����������� ����� �����������

	printf("���������� ������ �� data.txt...");
	char buffer[512];
	FILE *file;
	errno_t err;
	err = fopen_s(&file, "data.txt", "r");
	if (err != 0)
	{
		printf("������. ���� data.txt �� ������.\n�������� �����...");
		err = fopen_s(&file, "data.txt", "w+t");
		if (err != 0)
			printf("\n������. ���� �� ����� ���� ������.");
		else
			if (file)
			{
				err = fclose(file);
				if (err != 0)
					printf("\n������ ��� �������� ������ ��� ���������� �����\n");
				else
					printf("\n���� data.txt ������� ������\n");
			}
	}
	else
	{
		fseek(file, 0, SEEK_END);
		long pos = ftell(file);
		rewind(file);
		while (!feof(file) && pos>0)
		{
			// ������ ����� ������ ������
			int n = flightsDB->flightsAm;
			BusFlight *NewFlights;
			NewFlights = malloc((n + 1) * sizeof(BusFlight));
			if (n != 0) // ���� � ������ ������� ��� ���� ������ - ��������� �� � �����
				for (int i = 0; i < (int)n; i++)
					NewFlights[i] = flightsDB->flights[i];
			free(flightsDB->flights); // ������� ������ ������ �� ������
			BusFlight newFlight = { NULL }; // ������ ���������� �����
			fgets(buffer, 511, file); // ����� ������ �� �����
			char *token = NULL;
			char *temp = strtok_s(buffer, ";", &token); // "��������" �� ������ ������ ���������� �� �����������(;)
			// �������� ������ ��� ������ � ��������� � � ���������� ����� ��� ��� ��������.
			char *compName = (char*)malloc(30 * sizeof(char));
			strcpy_s(compName, 30, temp);
			newFlight.company = compName;
			// ��������, ��������� � int, ���������
			int busNumber = atoi(strtok_s(token, ";", &token));
			newFlight.busNumber = busNumber;
			// �� �� �����
			int seatsAmount = atoi(strtok_s(token, ";", &token));
			newFlight.seatAmount = seatsAmount;
			// ������ ���������� ��������
			Route busRoute = { NULL };
			int dataType = 0;
			// ��������� � ������ ������� ��������
			while (token[0] != 0 && token != NULL && token[0] != 10) // ��� ��� �� ������� ����� ������ ��������� ������� ����� ������ ���, �� ��������� ��, ���� ������ �� ����������
			{
				PStop newStop = malloc(sizeof(struct Stop)); // ��������� ������ ��� ����� ���������
				while (dataType != 4 && token[0] != 10 && token != 0)
				{
					switch (dataType)
					{
					case 0: // ���������� �������� ��������� �� ������ ������ � ���������� � ��������� ���������
						temp = strtok_s(token, ";", &token);
						char *stopName = (char*)malloc(30 * sizeof(char));
						strcpy_s(stopName, 30,temp);
						newStop->stopName = stopName;
						break;
					case 1: // ���������� � ���������� ���� ������
						temp = strtok_s(token, ";", &token);
						int ticketCost = atoi(temp);
						newStop->ticketCost = ticketCost;
						break;
					case 2: // ���������� � ���������� ���� ���������
						temp = strtok_s(token, ";", &token);
						int date = atoi(temp);
						newStop->date = date;
						break;
					case 3: // ���������� � ���������� ������� ���������
						temp = strtok_s(token, ";", &token);
						int time = atoi(temp);
						newStop->time = time;
						newStop->occSeats = 0;
						break;
					}
					dataType++;
				}
				// ���� ��� ������ ���������, �� ������ ������������� � ��������� � � ��� "������" � ��� "�����".
				if (busRoute.Tail == NULL)
				{
					newStop->next = newStop;
					newStop->prev = newStop;
					busRoute.Head = newStop;
					busRoute.Tail = newStop;
				}
				else
				{
					if (busRoute.Tail == busRoute.Head) // ���� ��� ������ ���������, �� ������� ���������� ������ ������������� ������
						busRoute.Head->prev = NULL;
					// ���������� ��������� � �����
					newStop->next = NULL;
					newStop->prev = busRoute.Tail;
					busRoute.Tail->next = newStop;
					busRoute.Tail = newStop;
				}
				dataType = 0;
			}
			// ��������� ������� � ���������� �����
			newFlight.route = busRoute;

			// ��������� ���� � ������ ������ � ��������� ����
			NewFlights[n] = newFlight;
			flightsDB->flightsAm = flightsDB->flightsAm + 1;
			flightsDB->flights = NewFlights;
		}
		// ��������� ����
		if (file)
		{
			err = fclose(file);
			if (err != 0)
			{
				printf("\nThe file was not closed\n");
			}
			else
			{
				printf("\n������ ������� �������.");
			}
		}
	}

	// ������ ������� ������� ��������� � ����� clientdata.txt � �������:
	// ���;�����;����� ��������;����������� �����;���������� �������;������� ������� 1;������� ����� 1;���� ������ 1; ������� ������� 2;...
	// ������ ������ ������� ������� �� �������� �������� �����. ; - �����������. 1 ������ - 1 ������.

	printf("\n���������� ������ �� clientdata.txt...\n");
	err = fopen_s(&file, "clientdata.txt", "r");
	if (err != 0)
	{
		printf("������. ���� clientdata.txt �� ������.\n�������� �����...");
		err = fopen_s(&file, "clientdata.txt", "w+t");
		if (err != 0)
			printf("\n������. ���� �� ����� ���� ������.");
		else
			if (file)
			{
				err = fclose(file);
				if (err != 0)
					printf("\n������ ��� �������� ������ ��� ���������� �����\n");
				else
					printf("\n���� clientdata.txt ������� ������\n");
			}
	}
	else
	{
		fseek(file, 0, SEEK_END);
		long pos = ftell(file);
		rewind(file);
		while (!feof(file) && pos > 0)
		{
			// ������ ����� ������ ��������
			int n = clientsDB->clientsAm;
			Client *newClients;
			newClients = malloc((n + 1) * sizeof(Client));
			if (n != 0) // ���� � ������ ������� ��� ���� ������ - ��������� �� � �����
				for (int i = 0; i < (int)n; i++)
					newClients[i] = clientsDB->clients[i];
			free(clientsDB->clients); // ������� ������ ������ �� ������
			Client newClient = { NULL }; // ������ ���������� �������
			fgets(buffer, 511, file); // ����� ������ �� �����
			char *token = NULL;
			char *temp = strtok_s(buffer, ";", &token); // "��������" �� ������ ������ ���������� �� �����������(;)
			// �������� ������ ��� ������ � ��������� � � ���������� ������� ��� ��� ���.
			char *fullName = (char*)malloc(60 * sizeof(char));
			strcpy_s(fullName, 60, temp);
			newClient.fullName = fullName;

			temp = strtok_s(token, ";", &token); // "��������" �� ������ ������ ���������� �� �����������(;)
			// �������� ������ ��� ������ � ��������� � � ���������� ������� ��� ��� �����.
			char *adress = (char*)malloc(128 * sizeof(char));
			strcpy_s(adress, 128, temp);
			newClient.adress = adress;

			// �������� ������ ��� ������ � ��������� � � ���������� ������� ��� ��� ����� ��������.
			temp = strtok_s(token, ";", &token);
			char *phoneNumber = (char*)malloc(15 * sizeof(char));
			strcpy_s(phoneNumber, 15, temp);
			newClient.phoneNumber = phoneNumber;
			// �������� ������ ��� ������ � ��������� � � ���������� ������� ��� ��� EMail.
			temp = strtok_s(token, ";", &token);
			char *EMail = (char*)malloc(254 * sizeof(char));
			strcpy_s(EMail, 254, temp);
			newClient.eMail = EMail;
			// ��������, ��������� � int, ���������
			int ticketsAm = atoi(strtok_s(token, ";", &token));
			newClient.ticketsAm = ticketsAm;
			// ������ ���������� ������
			Ticket *tickets = malloc((ticketsAm) * sizeof(Client));
			int dataType = 0;
			// ��������� � ��������� ������ ������� �������
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
			// ��������� ������ ������� � ������� � ���������� �����
			newClient.tickets = tickets;

			// ��������� ������� � ������ �������� � ��������� ����
			newClients[n] = newClient;
			clientsDB->clientsAm = clientsDB->clientsAm + 1;
			clientsDB->clients = newClients;
		}
		// ��������� ����
		if (file)
		{
			err = fclose(file);
			if (err != 0)
			{
				printf("\nThe file was not closed\n");
			}
			else
			{
				printf("������ ������� �������.\n");
			}
		}
	}
}

// ���������� ��������� ������ ������� �� ������ ��������
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

// ����������� ����� ��������
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

// ����������� ����� �������� � ��������� ����������� � ������ ���������
int PrintStops(Route *route)
{
	PStop stop = route->Head;
	int stopCounter = 0;
	do
	{
		if (stopCounter == 0)
			printf("%d)\"%s\". ���� ��������: %d. ����� ��������: %d. ������� �����: %d ", stopCounter + 1, stop->stopName, stop->date, stop->time, stop->occSeats);
		else
			printf("\n%d)\"%s\". ���� ��������: %d. ����� ��������: %d. ������� ����: %d. ���� ������: %d ", stopCounter + 1, stop->stopName, stop->date, stop->time, stop->occSeats, stop->ticketCost);
		stopCounter++;
		stop = stop->next;
	} while (stop != NULL && stop->next != stop->prev);

	return stopCounter;
}

// ����� �� ����� ������ ������
void PrintFlightsList(BusFDB *flightsDB)
{
	int n = flightsDB->flightsAm;
	if (n == 0)
		printf("\n������ ������ ����\n");
	else
	{
		for (int i = 0; i < (int)n; i++)
			printf("���� #%d) �������� \"%s\", %s - %s. \n������������ ������� �%d\n", i + 1, flightsDB->flights[i].company, flightsDB->flights[i].route.Head->stopName, flightsDB->flights[i].route.Tail->stopName, flightsDB->flights[i].busNumber);
	}
}

// ����� �� ����� ������ � �����
void PrintFlight(BusFDB *flightsDB, int flightNumber)
{
	printf("\n��������: \"%s\". \n����� ��������: %d. \n������������ ���������� ����: %d. \n������ ������� ��������:\n", flightsDB->flights[flightNumber].company, flightsDB->flights[flightNumber].busNumber, flightsDB->flights[flightNumber].seatAmount);
	int n = PrintRoute(&(flightsDB->flights[flightNumber].route));
	printf("\n������� ��������� ���������: %d\n", n);
}

// ����� �� ����� ������ ��������
void PrintClientsList(ClientsDB *clientsDB)
{
	printf("\n������ ��������:");
	if (clientsDB->clientsAm == 0)
		printf("\n������ �������� ����\n");
	else
	{
		for (int i = 0; i < clientsDB->clientsAm; i++)
		{
			printf("\n%d) %s, �����: %s\n���������� ����������:\n����� ��������: %s\n����� ����������� �����: %s", i + 1, clientsDB->clients[i].fullName, clientsDB->clients[i].adress, clientsDB->clients[i].phoneNumber, clientsDB->clients[i].eMail);
			printf("\n������� ������������� �������: ");
			if (clientsDB->clients[i].ticketsAm != 0)
				for (int j = 0; j < clientsDB->clients[i].ticketsAm; j++)
					printf("\n%d. %s - %s. ����: %d �.", j + 1, clientsDB->clients[i].tickets[j].stopStart, clientsDB->clients[i].tickets[j].stopFin, clientsDB->clients[i].tickets[j].ticketCost);
			else
				printf("\n������ ��� �� ���������� �������");
		}
	}
}

// ���������� ������ ��������� ��������
void AddStopFirst(Route *route)
{
	PStop newStop = malloc(sizeof(struct Stop));
	printf("\n������� �������� ���������: ");
	char *stopName1 = (char*)malloc(30 * sizeof(char));
	scanf_s("%s", stopName1, 30);
	newStop->stopName = stopName1;
	printf("������� ���� �������: ");
	int dateStop = 0;
	scanf_s("%d", &dateStop);
	newStop->date = dateStop;
	printf("������� ����� �������: ");
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
	printf("\n����� ����������� �������� �������.");
}

// ���������� ��������� ��������� ��������
void AddStopLast(Route *route)
{
	PStop newStop = malloc(sizeof(struct Stop));
	printf("\n������� �������� ���������: ");
	char *stopName2 = (char*)malloc(30 * sizeof(char));
	scanf_s("%s", stopName2, 30);
	newStop->stopName = stopName2;
	printf("������� ���� ��������: ");
	int dateStop = 0;
	scanf_s("%d", &dateStop);
	newStop->date = dateStop;
	printf("������� ����� ��������: ");
	int timeStop = 0;
	scanf_s("%d", &timeStop);
	newStop->time = timeStop;
	printf("������� ���� ������ �� ���� ���������: ");
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

	printf("\n����� �������� �������� �������.");
}

// ���������� ������������� ���������
void AddStopMid(Route *route)
{
	int stopsAmount = PrintRoute(route);
	printf("\n������� ���� ������ �������� ������������� ���������.");
	int slot = 0;
	scanf_s("%d", &slot);
	if (slot < stopsAmount)
	{
		PStop stop = route->Head;
		for(int i = 0; (slot-1) > i; i++)
		{
			stop = stop->next;
		}
		printf("\n��������� ���������� � ������������� ���������. ");
		
		PStop newStop = malloc(sizeof(struct Stop));
		printf("\n������� �������� ���������: ");
		char *stopName = (char*)malloc(30 * sizeof(char));
		scanf_s("%s", stopName, 30);
		newStop->stopName = stopName;
		printf("������� ���� �������: ");
		int dateStop = 0;
		scanf_s("%d", &dateStop);
		newStop->date = dateStop;
		printf("������� ����� �������: ");
		int timeStop = 0;
		scanf_s("%d", &timeStop);
		newStop->time = timeStop;
		printf("������� ���� ������: ");
		int ticketCost = 0;
		scanf_s("%d", &ticketCost);
		newStop->ticketCost = ticketCost;
		newStop->occSeats = 0;
		newStop->next = stop->next;
		newStop->prev = stop;
		stop->next->prev = newStop;
		stop->next = newStop;
		printf("\n������������� ��������� ������� ���������");
	}
	else
	{
		printf("\nERROR\n");
	}
}

// �������������� ������ ���������
void EditStop(Route *route)
{
	printf("\n������ ��������� ����� ��������:\n");
	PrintStops(route);
	printf("\n������� ����� ���������: ");
	int userAnsw = 0;
	scanf_s("%d", &userAnsw);
	PStop stop = route->Head;
	for (int i = 1; i < userAnsw; i++)
	{
		stop = stop->next;
	}
	printf("\n1)�������� �������� ���������\n2)�������� ���� ��������\n3)�������� ����� ��������\n4)�������� ���� ������\n5)������� ���������\n0)�����");
	printf("\n_____________________________________________\n����: ");
	userAnsw = 0;
	scanf_s("%d", &userAnsw);
	switch (userAnsw)
	{
	case 1:
		printf("\n������� ����� ��������: ");
		char *newName = (char*)malloc(30 * sizeof(char));
		scanf_s("%s", newName, 30);
		if (stop->stopName != "����������")
			free(stop->stopName);
		stop->stopName = newName;
		break;
	case 2:
		printf("\n������� ����� ���� ��������: ");
		int newDate = 0;
		scanf_s("%d", &newDate);
		stop->date = newDate;
		break;
	case 3:
		printf("\n������� ����� ����� ��������: ");
		int newTime = 0;
		scanf_s("%d", &newTime);
		stop->time = newTime;
		break;
	case 4:
		printf("\n������� ����� ���� ������: ");
		int newCost = 0;
		scanf_s("%d", &newCost);
		stop->ticketCost = newCost;
		break;
	case 5:
		printf("\n�� �������? \n1)�� \n2)���");
		printf("\n_____________________________________________\n����: ");
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
				printf("\n���������� ������� ������������ ��������� �� ��������\n");
			}
		}
		break;
	case 0:
		// �����
		break;
	default:
		userAnsw = 11;
		break;
	}
}

// ���������� �����
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
	printf("\n�� ������� ��������� ������ ����� ������ ��� �����?\n1) ������\n2) �����\n");
	printf("\n_____________________________________________\n����: ");
	int userAnsw = 0;
	scanf_s("%d", &userAnsw);
	BusFlight newFlight = { NULL };
	switch (userAnsw)
	{
	case 1:
		printf("\n���������� ������ �����.");
		printf("\n������� �������� ��������-�����������: ");
		char *compName = (char*)malloc(30 * sizeof(char));
		scanf_s("%s", compName, 30);
		newFlight.company = compName;
		printf("������� ����� ��������: ");
		int busNum = 0;
		scanf_s("%d", &busNum);
		newFlight.busNumber = busNum;
		printf("������� ���������� ���� � ��������: ");
		int seatsAm = 0;
		scanf_s("%d", &seatsAm);
		newFlight.seatAmount = seatsAm;
		printf("\n���������� ��������.");
		Route busRoute = { NULL };
		printf("\n��������� ���������� � �����������.");
		AddStopFirst(&busRoute);
		printf("\n\n��������� ���������� � ��������.");
		AddStopLast(&busRoute);
		printf("\n\n�������� ������������� ���������? \n1) ��\n2) ���\n");
		do {
			userAnsw = 0;
			scanf_s("%d", &userAnsw);
			switch (userAnsw)
			{
			case 1:
				AddStopMid(&busRoute);
				printf("\n�������� ��� ������������� ���������? \n1) ��\n2) ���\n");
				break;

			default:
				printf("\n��� ������������� �� ������ �������� ������������� ��������� ����� � ���� ��������� ������ �����.\n");
				break;
			}
		} while (userAnsw == 1);
		newFlight.route = busRoute;
		break;
	default:
		printf("\n�� ������ ��������� ������ ����� � ���� ��������� ������ �����.\n");
		// ��������� ������ ����� ��������������
		newFlight.company = "����������";
		newFlight.busNumber = 0;
		PStop newStop = malloc(sizeof(struct Stop));
		newStop->stopName = "����������";
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

	printf("\n����� ���� ������� ��������.\n");
	NewFlights[n] = newFlight;
	flightsDB->flightsAm = flightsDB->flightsAm + 1;
	flightsDB->flights = NewFlights;
}

// �������� ������ ������
void FlightsEditor(BusFDB *flightsDB)
{
	int userAnsw = 11;
	do{
	printf("\n�������������� ������ ������.");
	printf("\n1)�������� ������ ������������� �����\n2)�������� ����� ����\n0)�����");
	printf("\n_____________________________________________\n����: ");
	userAnsw = 11;
	scanf_s("%d", &userAnsw);
	switch (userAnsw)
	{
	case 1:
		do {
		PrintFlightsList(flightsDB);
		if (flightsDB->flightsAm == 0)
		{
			printf("\n0)�����");
			printf("\n_____________________________________________\n����: ");
			userAnsw = 0;
			scanf_s("%d", &userAnsw);
		}
		else
		{
			printf("\n������� ����� �����, ��� ������ ��������");
			printf("\n_____________________________________________\n����: ");
			userAnsw = 0;
			scanf_s("%d", &userAnsw);
			if (userAnsw <= flightsDB->flightsAm && userAnsw > 0)
			{
				int n = userAnsw-1;
				do {
					PrintFlight(flightsDB, n);
					printf("\n1)�������� �������� ��������-�����������\n2)�������� ����� ��������\n3)�������� ���������� ���� � ��������\n4)������������� �������\n0)�����");
					printf("\n_____________________________________________\n����: ");
					userAnsw = 0;
					scanf_s("%d", &userAnsw);
					switch (userAnsw)
					{
					case 1:
						printf("\n������� ����� ��������: ");
						char *newName = (char*)malloc(30 * sizeof(char));
						scanf_s("%s", newName, 30);
						if(flightsDB->flights[n].company != "����������")
							free(flightsDB->flights[n].company);
						flightsDB->flights[n].company = newName;
					break;
					case 2:
						printf("\n������� ����� �����: ");
						int newNum = 0;
						scanf_s("%d", &newNum);
						flightsDB->flights[n].busNumber = newNum;
						break;
					case 3:
						printf("\n������� ����� ���������� ����: ");
						int newAm = 0;
						scanf_s("%d", &newAm);
						flightsDB->flights[n].seatAmount = newAm;
						break;
					case 4:
						do{
						printf("\n1)�������� ��������� � ������ ����\n2)�������� ��������� � ����� ����\n3)�������� ������������� ���������\n4)�������� ������ ����� �� ���������\n0)�����");
						printf("\n_____________________________________________\n����: ");
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
							// �����
							break;
						default:
							userAnsw = 11;
							break;
						}
						} while (userAnsw != 0);
						break;
					case 0: 
						// �����
						break;
					default:
						userAnsw = 11;
						break;
					}
				} while (userAnsw != 0);
			}
			else
				printf("\n����� ��� ����� ������� �� ����������");
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
		// �����
		break;
	}
	} while (userAnsw != 0);
}

// �������� ���������� � �������
void ClientEditor(ClientsDB *clientsDB, BusFDB *flightsDB)
{
	int userAnswer = 11;
	printf("\n������� ����� �������, ���������� � ������� ������ ��������: ");
	PrintClientsList(clientsDB);
	scanf_s("%d", &userAnswer);
	if (userAnswer > clientsDB->clientsAm)
	{
		printf("\n������ ������� �� ����������");
	}
	else {
	Client *client = &clientsDB->clients[userAnswer];
	printf("\n��������� ������ �������.");
	int userAnsw = 0;
	printf("\n����:\n1)�������� ���\n2)�������� ����� ����������\n3)�������� ����� ��������\n4)�������� e-mail\n5)��������� �����\n0)�����");
	printf("\n_____________________________________________\n����: ");
	scanf_s("%d", &userAnsw);
	switch (userAnsw)
	{
	case 1:
		printf("\n������� ����� ���: ");
		char *newData = (char*)malloc(60 * sizeof(char));
		scanf_s("%s", newData, 60);
		free(client->fullName);
		client->fullName = newData;
		break;
	case 2:
		printf("\n������� ����� �����: ");
		char *newData1 = (char*)malloc(60 * sizeof(char));
		scanf_s("%s", newData1, 60);
		free(client->adress);
		client->adress = newData1;
		break;
	case 3:
		printf("\n������� ����� ����� ��������: ");
		char *newData2 = (char*)malloc(20 * sizeof(char));
		scanf_s("%s", newData2, 20);
		free(client->phoneNumber);
		client->phoneNumber = newData2;
		break;
	case 4:
		printf("\n������� ����� e-mail: ");
		char *newData3 = (char*)malloc(60 * sizeof(char));
		scanf_s("%s", newData3, 60);
		free(client->phoneNumber);
		client->phoneNumber = newData3;
		break;
	case 5:
		printf("\n�������� ���� �� ������� ��������� �����(0 - �����):\n");
		PrintFlightsList(flightsDB);
		userAnsw = 11;
		scanf_s("%d", &userAnsw);
		switch (userAnsw)
		{
		case 0:
			// �����
			break;
		default:
			if (userAnsw > flightsDB->flightsAm)
				printf("\n������ ����� �� ����������\n");
			else
			{
				printf("\n�������� ��������� �� ������� ��������� �����:\n");
				int stopAm = PrintStops(&flightsDB->flights[userAnsw-1].route);
				int temp = userAnsw-1;
				printf("\n");
				scanf_s("%d", &userAnsw);
				if (userAnsw > stopAm)
					printf("\n����� ��������� �� ����������");
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
					printf("\n����� ������� �������� �������\n");
					newTickets[n] = newTicket;
					client->tickets = newTickets;
					client->ticketsAm = client->ticketsAm+1;
				}
			}
			break;
		}
		break;
	case 0:
		// �����
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
	printf("\n����� ���������� � ������� ���������� � ���������� ������ � �������.");
	printf("\n����:\n1)��������� ������ ������\n2)��������� ���������� � �������\n3)�������������� ������\n0)�����");
	printf("\n_____________________________________________\n����: ");
	scanf_s("%d", &userAnsw);
	switch (userAnsw)
	{
	case 1:
		PrintFlightsList(&flightsDB);
		userAnsw = 11;
		printf("\n������� ����� ����� ��� ��������� ��������� ���������� ��� 0 ��� ������.\n_____________________________________________\n����: ");
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
		printf("\n1)�������������� ������ �������\n2)�������������� ������\n3)�������� ������ �� data.txt � clientdata.txt\n4)������������� ������ ������ �� ������ ��������\n5)��������� ������ ������ � ���� data.txt � ������ �������� � clientdata.txt\n6)�������� ����� ����� �� input.txt\n0)�����");
		printf("\n_____________________________________________\n����: ");
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
			// �����
			break;
		default:
			userAnsw = 11;
			break;
		}
		break;
	case 0:
		printf("\n\n���������� ������...\n\n");
		break;
	default:
		userAnsw = 11;
		break;
	}
	}while (userAnsw!=0);
}
*/

