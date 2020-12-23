// Лаба 6. Задание 3.
// Найти  минимальный элемент матрицы С (размер m*n), 
// и поменять его местами с первым элементом.
/*

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
float frand()
{
	return (((float)rand() / 100) * 5.2f);
}
void main()
{
	setlocale(LC_ALL, "Rus");
	int n, m, j, i;
	float  **matr;
	system("CLS");
	printf("Введите размер матрицы.\nn: ");
	scanf_s("%d", &n);
	printf("m: ");
	scanf_s("%d", &m);
	
	matr = (float **)malloc(sizeof(float *)*n);
	if (matr == NULL)
	{
		puts("не создан динамический массив!");
		return;
	}
	srand(time(NULL));
	for (i = 0; i < n; i++)
	{
		matr[i] = (float *)malloc(sizeof(float)*n);
		if (NULL == matr[i])
		{
			puts("не создан динамический массив!");
			return;
		}
		for (j = 0; j < m; j++)
			matr[i][j] = frand();
	}
	float min = matr[0][0];
	int minI = 0;
	int minJ = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 1; j < m; j++)
		{
			if (matr[i][j] < min)
			{
				min = matr[i][j];
				minI = i;
				minJ = j;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			printf(" %.2f", matr[i][j]);
		printf("\n");
	}
	printf("\nМинимальный элемент матрицы находится в [%d][%d] и равен %.2f\n", minI, minJ, min);
	matr[minI][minJ] = matr[0][0];
	matr[0][0] = min;
	printf("Новая матрица:\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			printf(" %.2f", matr[i][j]);
		printf("\n");
	}
	for (i = 0; i < n; i++)
		free(matr[i]); 
	free(matr); 
	_getch();
}
*/

// Лаба 6. Прога 2.
/*#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<time.h>
#include <locale.h>

void clrscr()
{
	system("CLS");
}
void randomize()
{
	srand(time(NULL));
}

void main()
{
	setlocale(LC_ALL, "Rus");
	int n, j, i;
	float  ** matr; 
	float * mass; 
	// Объявляем matr - указатель на массив указателей
	// mass – указатель на одномерный массив
	clrscr();
	printf("Введите размер квадратной матрицы n: "); 
	scanf_s("%d", &n);
	mass = (float *)malloc(n * sizeof(float)); // Выделяем память под массив mass
	if (mass == NULL)
	{
		puts("не создан динамический массив!");
		return;
	}
	matr = (float **)malloc(sizeof(float *)*n); // Выделяем память под массив  указателей
	if (matr == NULL)
	{
		puts("не создан динамический массив!");
		return;
	}
	randomize();
	for (i = 0; i < n; i++)
	{
		matr[i] = (float *)malloc(sizeof(float)*n); // Выделяем память под i-ю строку 
		if (NULL == matr[i])
		{
			puts("не создан динамический массив!");
			return;
		}
		for (j = 0; j < n; j++)   matr[i][j] = rand(100);
	}
	for (i = 0; i < n; i++)
	{
		mass[i] = 0;
		for (j = 0; j < n; j++)
			mass[i] += matr[i][j];
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("\t%6.2f", matr[i][j]);
		printf("\n");
	}
	for (i = 0; i < n; i++)
		printf("\n  сумма %d строки %8.2f", i, mass[i]);
	for (i = 0; i < n; i++)
		free(matr[i]); //Освобождаем память i – й строки
	free(matr); // Освобождаем память массива указателей
	free(mass); // Освобождаем память массива сумм
	_getch();
}*/

// Лаба 6. Прога 1.
/*#include <stdio.h>
#include <conio.h>
//#include <alloc.h>

void main()
{
	float *p, d;
	int i, n;
	printf("\n input n:");
	scanf_s("%d", &n);
	p = (float *)malloc(n * sizeof(float));
	for (i = 0; i < n; i++)
	{
		printf("x[%d]=", i);
		scanf_s("%f", &d);
		p[i] = d;
	}
	for (i = 0; i < n; i++)
	{
		if (i % 4 == 0) printf("\n");
		printf("\t x[%d]=%6.2f", i, p[i]);
	}
	free(p);
	_getch();
}*/

// Лаба 5. Прога 7.
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Danger function: it's not responsible for
// the memory it allocates for the duplicate!
int* duplicate_array(int *A, size_t N)
{
	int * B = (int *)malloc(sizeof(int)*N);
	for (size_t i = 0; i < N; i++)
		B[i] = A[i];
	printf(" duplicate_array() allocated memory for the duplicate.\n");
	return B;
}

int main()
{
	printf("Calling irresponsible function duplicate_array():\n");
	int A[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int *B = duplicate_array(A, 10);
	for (int i = 0; i < 10; ++i)
		printf("%d\t", B[i]);

	printf("Since caller function is not taking responsibility by itself,\n");
	printf(" memory for the array above will never be released...\n\n");

	printf("The same situation for the standard function strdup():\n");
	char *hello = "Hello, World!";
	char *message = _strdup(hello);
	printf("Strdup allocated memory for this message: \"%s\"\n", message);
	printf("It'll never be released...\n\n");

	int *p;
	for (int i = 0; i < 10; i++)
	{
		p = (int *)malloc(sizeof(int));
		printf("Allocating memory many times in cycle.\n");
		*p = i;
	}
	free(p);
	printf("But releasing it just once...\n");

	return 0;
}*/

// Лаба 5. Прога 6.
/*
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
void foo(int *pointer)
{
	assert(pointer);
	*pointer = 0; //potential Segmentation fault
}
int main()
{
	int *p = NULL;  // Uninitialized pointer!
	//*p = 10; // Using it => Segmentation fault!

	//foo(p);  // Another use of uninitialized pointer => Segmentation fault!

	int x = 100;
	scanf_s("%d", &x); // Very popular Segmentation fault.

	return 0;
}
*/

// Лаба 5. Прога 5.
/*#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int N = 50000000;

	for (int k = 0; k < 1000; ++k)
	{
		int *A = (int *)malloc(N * sizeof(int));
		if (NULL == A) {
			printf("OS didn't gave memory. Exit...\n");
			exit(1);
		}
		printf("Allocate array - OK. iteration %d.\n", k);
		for (int i = 0; i < N; ++i)
			A[i] = i;
		//free(A); //TODO: uncomment this line
	}
	printf("Program is on finish!\n");
	system("pause");

	return 0;
}*/

// Лаба 5. Прога 4.
/*#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int N;
	printf("Enter size of array to create:");
	scanf_s("%d", &N);

	char *A = (char *)malloc(N);
	if (NULL == A)
	{
		printf("OS didn't gave memory. Exit...\n");
		exit(1);
	}
	for (int i = 0; i < N; ++i)
		A[i] = i;
	printf("Array A successfully created!\n");
	system("pause");

	return 0;
}*/

// Лаба 5. Прога 3.
/*#include <stdio.h>
#include <stdlib.h>

void print_abstract(void *p, int type_marker);

int main(int argc, char* argv[])
{
	char c = 'W';
	int i = 450;
	double d = -1;

	void *p; // бестиповый указатель.Любой адрес
		p = &c;
	print_abstract(p, 1);
	p = &i;
	print_abstract(p, 2);
	p = &d;
	print_abstract(p, 3);

	return 0;
}

void print_abstract(void *p, int type_marker)
{
	if (type_marker == 1)
		printf("%c\n", *(char *)p);
	else if (type_marker == 2)
		printf("%d\n", *(int *)p);
	else if (type_marker == 3)
		printf("%lf\n", *(double *)p);
	else
	{
		printf("Unknown type marker. Exitting.");
		exit(1);
	}

}*/

// Лаба 5. Прога 2.
/*#include <stdio.h>

int main(int argc, char* argv[])
{
	int A[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	printf("%d\n", *A);

	int *p = A + 5;
	printf("%d\n", p[-1]);

	int *q = A + 7;
	if (p > q)
		printf("p > q\n");
	else
		printf("p <= q\n");

	printf("p - q = %d\n", p - q);

	return 0;
}*/

// Лаба 5. Прога 1.
/*#include <stdio.h>
int main(int argc, char* argv[])
{
	int i = 10;
	int *pi = &i;
	int **ppi = &pi;
	int ***pppi = &ppi;

	printf("%d\n", i);
	*pi = 20;
	printf("%d\n", i);
	**ppi = 30;
	printf("%d\n", i);
	***pppi = 40;
	printf("%d\n", i);

	return 0;
}*/

