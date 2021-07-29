
// ЛАБА 7

// Пример 1
/*
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
// Блохнов Сергей

void main() {
	char buffer[128];
	int a = NULL;
	int b = NULL;
	FILE *file;
	errno_t err;
	err = fopen_s(&file, "input.txt", "r");
	if (err != 0)
		printf("Not found");
	else
	{
		fgets(buffer, 127, file);
		char *token = NULL;
		char *temp = strtok_s(buffer, " ", &token);
		a = atoi(temp);
		b = atoi(token);
	} 
	if (file)
	{
		err = fclose(file);
		if (err != 0)
		{
			printf("\nThe file was not closed\n");
		}
	}
	err = fopen_s(&file, "output.txt", "w+t");
	if (err != 0 || a == NULL || b == NULL)
		printf("Not found");
	else
	{
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
				fprintf(file, "%d ", (rand()%90+10));
			fprintf(file, "\n");
		}
	}
	if (file)
	{
		err = fclose(file);
		if (err != 0)
		{
			printf("\nThe file was not closed\n");
		}
	}

	getchar(); getchar();
}
*/

// Пример 2 
/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define ERROR_FILE_OPEN -3

// Блохнов Сергей

void main() {
	FILE *origin = NULL;
	FILE *output = NULL;
	char filename[1024];
	int mode;

	printf("Enter filename: ");
	scanf("%1023s", filename);

	origin = fopen(filename, "r");
	if (origin == NULL) {
		printf("Error opening file %s", filename);
		_getch();
		exit(ERROR_FILE_OPEN);
	}

	printf("enter mode: [1 - copy, 2 - print] ");
	scanf("%d", &mode);

	if (mode == 1) {
		printf("Enter filename: ");
		scanf("%1023s", filename);
		output = fopen(filename, "w");
		if (output == NULL) {
			printf("Error opening file %s", filename);
			_getch();
			fclose(origin);
			exit(ERROR_FILE_OPEN);
		}
	}
	else {
		output = stdout;
	}

	while (!feof(origin)) {
		fprintf(output, "%c", fgetc(origin));
	}

	fclose(origin);
	fclose(output);

	_getch();
}
*/

// Пример 3 
/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define ERROR_FILE_OPEN -3
// Блохнов Сергей


void main() {
	FILE *output = NULL;
	char c;

	output = fopen("output.txt", "w+t");
	if (output == NULL) {
		printf("Error opening file");
		_getch();
		exit(ERROR_FILE_OPEN);
	}

	for (;;) {
		c = _getch();
		if (c == 27) {
			break;
		}
		fputc(c, output);
		fputc(c, stdout);
	}

	fclose(output);
}
*/

// Пример 4
/*#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define ERROR_FILE_OPEN -3
// Блохнов Сергей


void main() {
	FILE *input = NULL;
	int num, maxn, hasRead;

	input = fopen("input.txt", "r");
	if (input == NULL) {
		printf("Error opening file");
		_getch();
		exit(ERROR_FILE_OPEN);
	}

	maxn = INT_MIN;
	while (!feof(input)) {
		fscanf(input, "%d", &num);
		if (num > maxn) {
			maxn = num;
		}
	}
	printf("max number = %d", maxn);

	fclose(input);
	_getch();
}*/

// Пример 5
/*
#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define ERROR_FILE_OPEN -3
// Блохнов Сергей

void main() {
	setlocale(LC_ALL, "RUS");
	FILE *input = NULL;
	char buffer[512];
	char enWord[128];
	char ruWord[128];
	char usrWord[128];
	unsigned index;
	int length;
	int wasFound;

	input = fopen("input.txt", "r");
	if (input == NULL) {
		printf("Error opening file");
		_getch();
		exit(ERROR_FILE_OPEN);
	}

	printf("enter word: ");
	fgets(usrWord, 127, stdin);
	wasFound = 0;
	while (!feof(input)) {
		fgets(buffer, 511, input);
		length = strlen(buffer);
		for (index = 0; index < length; index++) {
			if (buffer[index] == '\t') {
				buffer[index] = '\0';
				break;
			}
		}
		strcpy(ruWord, buffer);
		strcpy(enWord, &buffer[index + 1]);
		if (!strcmp(enWord, usrWord)) {
			wasFound = 1;
			break;
		}
	}

	if (wasFound) {
		printf("%s", ruWord);
	}
	else {
		printf("Word not found");
	}

	fclose(input);
	_getch();
}
*/

// Пример 6
/*
#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
// Блохнов Сергей

int cntLines(const char *filename) {
	int lines = 1;
	int any;    //any типа int, потому что EOF имеет тип int!
	FILE *f = fopen(filename, "r");
	if (f == NULL) 
		return -1;
	do {
		any = fgetc(f);
		if (any == '\n')
			lines++;
	}while (any != EOF);
	fclose(f);
	return lines;
}

void main() {
	printf("%d\n", cntLines("input.txt"));
	_getch();
}*/


// ЛАБА 8

// Пример 1
/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define SIZE 10
// Блохнов Сергей

void main() {
	const char filename[] = "state";
	FILE *bfile = NULL;
	int pos;
	int value = 0;
	int i;
	char wasCreated;

	do {
		wasCreated = 0;
		bfile = fopen(filename, "r+b");
		if (NULL == bfile) {
			printf("Try to create file...\n");
			_getch();
			bfile = fopen(filename, "wb");
			if (bfile == NULL) {
				printf("Error when create file");
				_getch();
				exit(1);
			}
			for (i = 0; i < SIZE; i++) {
				fwrite(&value, sizeof(int), 1, bfile);
			}
			printf("File created successfully...\n");
			fclose(bfile);
			wasCreated = 1;
		}
	} while (wasCreated);

	do {
		printf("Enter position [0..9] ");
		scanf("%d", &pos);
		if (pos < 0 || pos >= SIZE) {
			break;
		}
		printf("Enter value ");
		scanf("%d", &value);
		fseek(bfile, pos * sizeof(int), SEEK_SET);
		fwrite(&value, sizeof(int), 1, bfile);
		rewind(bfile);
		for (i = 0; i < SIZE; i++) {
			fread(&value, sizeof(int), 1, bfile);
			printf("%d ", value);
		}
		printf("\n");
	} while (1);

	fclose(bfile);
}
*/

// Пример 2
/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define ERROR_FILE_OPEN -3
// Блохнов Сергей 

void main() {
	const char filename[] = "words.bin";
	const char termWord[] = "exit";
	char buffer[128];
	unsigned int len;
	FILE *wordsFile = NULL;

	printf("Opening file...\n");

	wordsFile = fopen(filename, "w+b");
	if (wordsFile == NULL) {
		printf("Error opening file");
		_getch();
		exit(ERROR_FILE_OPEN);
	}

	printf("Enter words\n");
	do {
		scanf("%127s", buffer);
		if (strcmp(buffer, termWord) == 0) {
			len = 0;
			fwrite(&len, sizeof(unsigned), 1, wordsFile);
			break;
		}
		len = strlen(buffer);
		fwrite(&len, sizeof(unsigned), 1, wordsFile);
		fwrite(buffer, 1, len, wordsFile);
	} while (1);

	printf("rewind and read words\n");
	rewind(wordsFile);
	_getch();

	do {
		fread(&len, sizeof(int), 1, wordsFile);
		if (len == 0) {
			break;
		}
		fread(buffer, 1, len, wordsFile);
		buffer[len] = '\0';
		printf("%s\n", buffer);
	} while (1);
	fclose(wordsFile);
	_getch();
}
*/

// Пример 3  
/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define DEBUG

#ifdef DEBUG
#define debug(data) printf("%s", data);
#else
#define debug(data)
#endif

// Блохнов Сергей 

const char inputFile[] = "input.txt";
const char outputFile[] = "output.bin";

struct someArgs {
	int* items;
	size_t number;
};

int writeToFile(FILE *file, void* args) {
	size_t i;
	struct someArgs *data = (struct someArgs*) args;
	debug("write to file\n")
		fwrite(data->items, sizeof(int), data->number, file);
	debug("write finished\n")
		return 0;
}

int readAndCallback(FILE *file, void* args) {
	struct someArgs data;
	size_t size, i = 0;
	int result;
	debug("read from file\n")
		fscanf(file, "%d", &size);
	data.items = (int*)malloc(size * sizeof(int));
	data.number = size;
	while (!feof(file)) {
		fscanf(file, "%d", &data.items[i]);
		i++;
	}
	debug("call withOpenFile\n")
		result = withOpenFile(outputFile, "w", writeToFile, &data);
	debug("read finish\n")
		free(data.items);
	return result;
}

int doStuff() {
	return withOpenFile(inputFile, "r", readAndCallback, NULL);
}

//Обёртка - функция открывает файл. Если файл был благополучно открыт,
//то вызывается функция fun. Так как аргументы могут быть самые разные,
//то они передаются через указатель void*. В качестве типа аргумента
//разумно использовать структуру
int withOpenFile(const char *filename,	const char *mode,	int(*fun)(FILE* source, void* args), void* args)
{
	FILE *file = fopen(filename, mode);
	int err;

	debug("try to open file ")
		debug(filename)
		debug("\n")

		if (file != NULL)
			err = fun(file, args);
		else
			return 1;

	debug("close file ")
		debug(filename)
		debug("\n")
		fclose(file);
	return err;
}

void main() {
	printf("result = %d", doStuff());
	_getch();
}
*/

// Пример 4 
/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdint.h>
#define SIZE 100
// Блохнов Сергей

int saveInt32Array(const char *filename, const int32_t *a, size_t size) {
	FILE *out = fopen(filename, "wb");
	if (!out) {
		return 0;
	}
	//Записываем длину массива
	fwrite(&size, sizeof(size_t), 1, out);
	//Записываем весь массив
	fwrite(a, sizeof(int32_t), size, out);
	fclose(out);
	return 1;
}

int loadInt32Array(const char *filename, int32_t **a, size_t *size) {
	FILE *in = fopen(filename, "rb");
	if (!in) {
		return 0;
	}
	//Считываем длину массива
	fread(size, sizeof(size_t), 1, in);
	//Инициализируем массив
	(*a) = (int32_t*)malloc(sizeof(int32_t) * (*size));
	if (!(*a)) {
		return 0;
	}
	//Считываем весь массив
	fread((*a), sizeof(int32_t), *size, in);
	fclose(in);
	return 1;
}

void main() {
	const char *tmpFilename = "tmp.bin";
	int32_t exOut[SIZE];
	int32_t *exIn = NULL;
	size_t realSize;
	int i;

	for (i = 0; i < SIZE; i++) {
		exOut[i] = i * i;
	}

	saveInt32Array(tmpFilename, exOut, SIZE);
	loadInt32Array(tmpFilename, &exIn, &realSize);

	for (i = 0; i < realSize; i++) {
		printf("%d ", exIn[i]);
	}

	_getch();
}*/

// Пример 5
/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
// Блохнов Сергей

//Каждая функция возвращает результат. Если он равен Ok, то функция
//отработала без проблем
typedef int Result;

//Возможные результаты работы
#define Ok 0
#define ERROR_OPENING_FILE  1
#define ERROR_OUT_OF_MEMORY 2

//Функция, которую мы будем табулировать
double mySinus(double x) {
	return sin(x);
}

Result tabFunction(const char *filename, double from, double to, double step, double(*f)(double)) {
	Result r;
	FILE *out = fopen(filename, "wb");
	double value;
	if (!out) {
		r = ERROR_OPENING_FILE;
		goto EXIT;
	}

	fwrite(&from, sizeof(from), 1, out);
	fwrite(&to, sizeof(to), 1, out);
	fwrite(&step, sizeof(step), 1, out);

	for (from; from < to; from += step) {
		value = f(from);
		fwrite(&value, sizeof(double), 1, out);
	}

	r = Ok;
EXIT:
	fclose(out);
	return r;
}

Result loadFunction(const char *filename, double **a, double *from, double *to, double *step) {
	Result r;
	uintptr_t size;
	FILE *in = fopen(filename, "rb");
	if (!in) {
		r = ERROR_OPENING_FILE;
		goto EXIT;
	}
	//Считываем вспомогательную информацию
	fread(from, sizeof(*from), 1, in);
	fread(to, sizeof(*to), 1, in);
	fread(step, sizeof(*step), 1, in);
	//Инициализируем массив
	size = (uintptr_t)((*to - *from) / *step);
	(*a) = (double*)malloc(sizeof(double)* size);
	if (!(*a)) {
		r = ERROR_OUT_OF_MEMORY;
		goto EXIT;
	}
	//Считываем весь массив
	fread((*a), sizeof(double), size, in);
	r = Ok;
EXIT:
	fclose(in);
	return r;
}

void main() {
	const char *tmpFilename = "tmp.bin";

	Result r;
	double *exIn = NULL;
	int accuracy, option;
	double from, to, step, arg;
	uintptr_t index;

	//Запрашиваем параметры для создания таблицы поиска
	printf("Enter parameters\nfrom = ");
	scanf("%lf", &from);
	printf("to = ");
	scanf("%lf", &to);
	printf("step = ");
	scanf("%lf", &step);

	r = tabFunction(tmpFilename, from, to, step, mySinus);
	if (r != Ok) {
		goto CATCH_SAVE_FUNCTION;
	}

	//Обратите внимание на формат вывода. Точность определяется
	//во время работы программы. Формат * подставит значение точности,
	//взяв его из списка аргументов
	accuracy = (int)(-log10(step));
	printf("function tabulated from %.*lf to %.*lf with accuracy %.*lf\n",
		accuracy, from, accuracy, to, accuracy, step);

	r = loadFunction(tmpFilename, &exIn, &from, &to, &step);
	if (r != Ok) {
		goto CATCH_LOAD_FUNCTION;
	}

	accuracy = (int)(-log10(step));
	do {
		printf("1 to enter values, 0 to exit : ");
		scanf("%d", &option);
		if (option == 0) {
			break;
		}
		else if (option != 1) {
			continue;
		}

		printf("Enter value from %.*lf to %.*lf : ", accuracy, from, accuracy, to);
		scanf("%lf", &arg);
		if (arg < from || arg > to) {
			printf("bad value\n");
			continue;
		}
		index = (uintptr_t)((arg - from) / step);
		printf("saved %.*lf\ncomputed %.*lf\n", accuracy, exIn[index], accuracy, mySinus(arg));
	} while (1);

	r = Ok;
	goto EXIT;
CATCH_SAVE_FUNCTION: {
	printf("Error while saving values");
	goto EXIT;
	}
				 CATCH_LOAD_FUNCTION: {
					 printf("Error while loading values");
					 goto EXIT;
}

								  EXIT:
									  free(exIn);
									  _getch();
									  exit(r);
}
*/

// Пример 6
/*
#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Блохнов Сергей


typedef struct PersonKey {
	long long id;
	char login[64];
	char password[64];
	long offset;//Положение соответствующих значений PersonInfo
} PersonKey;

typedef struct PersonInfo {
	unsigned age;
	char firstName[64];
	char lastName[128];
} PersonInfo;

// Функция запрашивает у пользователя данные и пишет их подряд в два файла
void createOnePerson(FILE *keys, FILE *values) {
	static long long id = 0;
	PersonKey pkey;
	PersonInfo pinfo;

	pkey.id = id++;
	//Так как все значения пишутся друг за другом, то текущее положение
	//указателя во втором файле будет позицией для новой записи
	pkey.offset = ftell(values);

	printf("Login: ");
	scanf("%63s", pkey.login);
	printf("Password: ");
	scanf("%63s", pkey.password);
	printf("Age: ");
	scanf("%d", &(pinfo.age));
	printf("First Name: ");
	scanf("%63s", pinfo.firstName);
	printf("Last Name: ");
	scanf("%127s", pinfo.lastName);

	fwrite(&pkey, sizeof(pkey), 1, keys);
	fwrite(&pinfo, sizeof(pinfo), 1, values);
}

void createPersons(FILE *keys, FILE *values) {
	char buffer[2];
	int repeat = 1;
	int counter = 0;//Количество элементов в файле
	//Резервируем место под запись числа элементов
	fwrite(&counter, sizeof(counter), 1, keys);
	printf("CREATE PERSONS\n");
	do {
		createOnePerson(keys, values);
		printf("\nYet another one? [y/n]");
		scanf("%1s", buffer);
		counter++;
		if (buffer[0] != 'y' && buffer[0] != 'Y') {
			repeat = 0;
		}
	} while (repeat);
	//Возвращаемся в начало и пишем количество созданных элементов
	rewind(keys);
	fwrite(&counter, sizeof(counter), 1, keys);
}


// Создаём массив ключей
PersonKey* readKeys(FILE *keys, int *size) {
	int i;
	PersonKey *out = NULL;
	rewind(keys);
	fread(size, sizeof(*size), 1, keys);
	out = (PersonKey*)malloc(*size * sizeof(PersonKey));
	fread(out, sizeof(PersonKey), *size, keys);
	return out;
}


// Функция открывает сразу два файла. Чтобы упростить задачу, возвращаем массив файлов.
FILE** openFiles(const char *keysFilename, const char *valuesFilename) {
	FILE **files = (FILE**)malloc(sizeof(FILE*) * 2);
	files[0] = fopen(keysFilename, "w+b");
	if (!files[0]) {
		return NULL;
	}
	files[1] = fopen(valuesFilename, "w+b");
	if (!files[1]) {
		fclose(files[0]);
		return NULL;
	}
	return files;
}


// Две вспомогательные функции для вывода ключа и информации

void printKey(PersonKey pk) {
	printf("%d. %s [%s]\n", (int)pk.id, pk.login, pk.password);
}

void printInfo(PersonInfo info) {
	printf("%d %s %s\n", info.age, info.firstName, info.lastName);
}


// Функция по ключу (вернее, по его полю offset)
// достаёт нужное значение из второго файла
PersonInfo readInfoByPersonKey(PersonKey pk, FILE *values) {
	PersonInfo out;
	rewind(values);
	fseek(values, pk.offset, SEEK_SET);
	fread(&out, sizeof(PersonInfo), 1, values);
	return out;
}

void getPersonsInfo(PersonKey *keys, FILE *values, int size) {
	int index;
	PersonInfo p;
	do {
		printf("Enter position of element. To exit print bad index: ");
		scanf("%d", &index);
		if (index < 0 || index >= size) {
			printf("Bad index");
			return;
		}
		p = readInfoByPersonKey(keys[index], values);
		printInfo(p);
	} while (1);
}

void main() {
	int size;
	int i;
	PersonKey *keys = NULL;
	FILE **files = openFiles("keys.bin", "values.bin");
	if (files == 0) {
		printf("Error opening files");
		goto FREE;
	}
	createPersons(files[0], files[1]);
	keys = readKeys(files[0], &size);

	for (i = 0; i < size; i++) {
		printKey(keys[i]);
	}

	getPersonsInfo(keys, files[1], size);

	fclose(files[0]);
	fclose(files[1]);
FREE:
	free(files);
	free(keys);
	_getch();
}
*/


// ЛАБА 9

// Пример 1
/*
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
// Блохнов Сергей

void main() {
	setlocale(LC_ALL, "RUS");
	char buffer[128];
	FILE *file;
	errno_t err;
	err = fopen_s(&file, "input.txt", "r");
	if (err != 0)
		printf("Not found");
	else
	{
		int nums = 0;
		int rusSyms = 0;
		while(!feof(file))
		{
		fgets(buffer, 127, file);
		int i = 0;
		while (buffer[i] != 0)
		{
			if ((int)buffer[i] <= -1 && (int)buffer[i] >= -64)
				rusSyms++;
			else if ((int)buffer[i] <= 57 && (int)buffer[i] >= 48)
				nums++;
			i++;
		}
		}
		printf("Количество цифр = %d \nКоличество русских букв = %d\nСледовательно, ", nums, rusSyms);
		if (nums > rusSyms)
			printf("цифр больше.");
		else
			printf("букв больше.");
	}
	if (file)
	{
		err = fclose(file);
		if (err != 0)
		{
			printf("\nThe file was not closed\n");
		}
	}

	getchar(); getchar();
}
*/
