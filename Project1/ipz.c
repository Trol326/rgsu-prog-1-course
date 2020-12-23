
// 3 задание
/*#include <stdio.h>
#include <math.h>
#include <locale.h>

#define WIDTH 80
#define HEIGHT 50
#define X WIDTH/2
#define Y HEIGHT/2
#define XMAX WIDTH-X-1
#define XMIN -(WIDTH-X)
#define YMAX HEIGHT-Y
#define YMIN -(HEIGHT-Y)+1
#define MAS 10


char grid[HEIGHT][WIDTH];

int plot(int x, int y)
{
	if (x > XMAX || x < XMIN || y > YMAX || y < YMIN)
		return(-1);

	grid[Y - y][X + x] = '*';
	return(1);
}

void init_grid(float a, float b)
{
	int x, y;

	for (y = 0; y < HEIGHT; y++)
		for (x = 0; x < WIDTH; x++)
			grid[y][x] = ' ';
	
	for (y = 0; y < HEIGHT; y++)
		grid[y][X] = '!';
	for (x = 0; x < WIDTH; x++)
		grid[Y][x] = '-';
	for (y = 0; y < HEIGHT; y++)
	{
			grid[y][X + (int)rintf(a)*MAS] = '|';
	}
	for (y = 0; y < HEIGHT; y++)
	{
			grid[y][X + (int)rintf(b)*MAS] = '|';
	}
	grid[Y+1][X+1] = '0';
	grid[Y+1][X+(int)rintf(a)*MAS+1] = 'a';
	grid[Y+1][X+(int)rintf(b)*MAS+1] = 'b';
}

void show_grid(void)
{
	int x, y;

	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
			putchar(grid[y][x]);
		putchar('\n');
	}
}
int main()
{
	setlocale(LC_ALL, "Rus");
	float x, y;
	float a, b;
	printf("Введите а: ");
	scanf_s("%f", &a);
	printf("Введите b: ");
	scanf_s("%f", &b);

	printf("График функции f(x)= -x+sin(2x) на отрезке [%.1f;%.1f]\n", a,b);

	init_grid(a,b);
	for (x = -3.1415; x <= 3.1415; x += 0.08)
	{
		y = (-x)+sin(2*x);
		plot(rintf(x*MAS), rintf(y*MAS));
	}
	show_grid();

	return(0);
}*/


// 2 задание
/*void main()
{
	setlocale(LC_ALL, "Rus");
	int n, j, i;
	int  **matr;
	system("CLS");
	printf("Введите размер матрицы.\nn: ");
	scanf_s("%d", &n);
	
	matr = (int **)calloc(sizeof(int *),n);
	if (matr == NULL)
	{
		puts("не создан динамический массив!");
		return;
	}
	for (i = 0; i < n; i++)
	{
		matr[i] = (int *)calloc(sizeof(int), n);
		if (NULL == matr[i])
		{
			puts("не создан динамический массив!");
			return;
		}
		for (j = 0; j < n-i; j++)
			matr[i][j] = i+1;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf(" %d", matr[i][j]);
		printf("\n");
	}

	for (i = 0; i < n; i++)
		free(matr[i]);
	free(matr);
	_getch();
}

*/

// 1 задание
/*
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void SelectionSort(int arr[], int n)
{
	int max, i;
	
	for (i = 0; i < n - 1; i++)
	{
		max = i;
		for (int j = i + 1; j < n; j++) 
		{
			if (arr[j] > arr[max])
				max = j;       
		}
		swap(&arr[i], &arr[max]);
	}

	printf("\nМассив отсортированный выбором: ");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
}
void main()
{
	setlocale(LC_ALL, "rus");
	int array[100], n, i;
	printf("введите количество элементов ");
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("значение %d-го элемента: ", i + 1);
		scanf_s("%d", &array[i]);
	}
	SelectionSort(array, n);
}*/

