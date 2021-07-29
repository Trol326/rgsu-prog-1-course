
// ЛАБА 4

// Пример 1
/*
#define _CRT_SECURE_NO_WARNINGS // для корректной работы scanf()
#include <stdio.h>
// Блохнов Сергей


// Функция сортировки прямыми включениями
void inclusionSort(int *num, int size)
{
	// Для всех элементов кроме начального
	for (int i = 1; i < size; i++)
	{
		int value = num[i]; // запоминаем значение элемента
		int index = i;     // и его индекс
		while ((index > 0) && (num[index - 1] > value))
		{   // смещаем другие элементы к концу массива пока они меньше index
			num[index] = num[index - 1];
			index--;    // смещаем просмотр к началу массива
		}
		num[index] = value; // рассматриваемый элемент помещаем на освободившееся место
	}
}
int main()
{
	int a[10]; // Объявляем массив из 10 элементов
	// Вводим значения элементов массива
	for (int i = 0; i < 10; i++)
	{
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	inclusionSort(a, 10);  // вызываем функцию сортировки
	// Выводим отсортированные элементы массива
	for (int i = 0; i < 10; i++)
		printf("%d ", a[i]);
	getchar(); getchar();
	return 0;
}
*/

// Пример 2
/*
#define _CRT_SECURE_NO_WARNINGS // для корректной работы scanf()
#include <stdio.h>
// Блохнов Сергей


// Функция сортировки прямым выбором
void selectionSort(int *num, int size)
{
	int min, temp; // для поиска минимального элемента и для обмена
	for (int i = 0; i < size - 1; i++)
	{
		min = i; // запоминаем индекс текущего элемента
		// ищем минимальный элемент чтобы поместить на место i-ого
		for (int j = i + 1; j < size; j++)  // для остальных элементов после i-ого
		{
			if (num[j] < num[min]) // если элемент меньше минимального,
				min = j;       // запоминаем его индекс в min
		}
		temp = num[i];      // меняем местами i-ый и минимальный элементы
		num[i] = num[min];
		num[min] = temp;
	}
}
int main()
{
	int a[10]; // Объявляем массив из 10 элементов
	// Вводим значения элементов массива
	for (int i = 0; i < 10; i++)
	{
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	selectionSort(a, 10);  // вызываем функцию сортировки
	// Выводим отсортированные элементы массива
	for (int i = 0; i < 10; i++)
		printf("%d ", a[i]);
	getchar(); getchar();
	return 0;
}
*/

// Пример 3
/*
#define _CRT_SECURE_NO_WARNINGS // для корректной работы scanf()
#include <stdio.h>
// Блохнов Сергей

// Функция сортировки прямым обменом (метод "пузырька")
void bubbleSort(int *num, int size)
{
	// Для всех элементов
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = (size - 1); j > i; j--) // для всех элементов после i-ого
		{
			if (num[j - 1] > num[j]) // если текущий элемент меньше предыдущего
			{
				int temp = num[j - 1]; // меняем их местами
				num[j - 1] = num[j];
				num[j] = temp;
			}
		}
	}
}
int main()
{
	int a[10]; // Объявляем массив из 10 элементов
	// Вводим значения элементов массива
	for (int i = 0; i < 10; i++)
	{
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	bubbleSort(a, 10);  // вызываем функцию сортировки
	// Выводим отсортированные элементы массива
	for (int i = 0; i < 10; i++)
		printf("%d ", a[i]);
	getchar(); getchar();
	return 0;
}
*/


// Пример 4
/*
#define _CRT_SECURE_NO_WARNINGS // для корректной работы scanf()
#include <stdio.h>
// Блохнов Сергей

// Функция Шейкер-сортировки
void shekerSort(double *mass, int count)
{
	int left = 0, right = count - 1; // левая и правая границы сортируемой области массива
	int flag = 1;  // флаг наличия перемещений
	// Выполнение цикла пока левая граница не сомкнётся с правой
	// и пока в массиве имеются перемещения
	while ((left < right) && flag > 0)
	{
		flag = 0;
		for (int i = left; i < right; i++)  //двигаемся слева направо
		{
			if (mass[i] > mass[i + 1]) // если следующий элемент меньше текущего,
			{             // меняем их местами
				double t = mass[i];
				mass[i] = mass[i + 1];
				mass[i + 1] = t;
				flag = 1;      // перемещения в этом цикле были
			}
		}
		right--; // сдвигаем правую границу на предыдущий элемент
		for (int i = right; i > left; i--)  //двигаемся справа налево
		{
			if (mass[i - 1] > mass[i]) // если предыдущий элемент больше текущего,
			{            // меняем их местами
				double t = mass[i];
				mass[i] = mass[i - 1];
				mass[i - 1] = t;
				flag = 1;    // перемещения в этом цикле были
			}
		}
		left++; // сдвигаем левую границу на следующий элемент
	}
}
int main() {
	double m[10];
	// Вводим элементы массива
	for (int i = 0; i < 10; i++) {
		printf("m[%d]=", i);
		scanf("%lf", &m[i]);
	}
	shekerSort(m, 10); // вызываем функцию сортировки
	// Выводим отсортированные элементы массива
	for (int i = 0; i < 10; i++)
		printf("%.2lf ", m[i]);
	getchar(); getchar();
	return 0;
}
*/

// Пример 5
/*#define _CRT_SECURE_NO_WARNINGS // для корректной работы scanf()
#include <stdio.h>
// Блохнов Сергей

// Функция сортировки Шелла
void shellSort(int *num, int size)
{
	int increment = 3;    // начальное приращение сортировки
	while (increment > 0)  // пока существует приращение
	{
		for (int i = 0; i < size; i++)  // для всех элементов массива
		{
			int j = i;          // сохраняем индекс и элемент
			int temp = num[i];
			// просматриваем остальные элементы массива, отстоящие от j-ого
			// на величину приращения
			while ((j >= increment) && (num[j - increment] > temp))
			{  // пока отстоящий элемент больше текущего
				num[j] = num[j - increment]; // перемещаем его на текущую позицию
				j = j - increment;       // переходим к следующему отстоящему элементу
			}
			num[j] = temp; // на выявленное место помещаем сохранённый элемент
		}
		if (increment > 1)      // делим приращение на 2
			increment = increment / 2;
		else if (increment == 1)   // последний проход завершён,
			break;  // выходим из цикла
	}
}
int main()
{
	int m[10];
	// Вводим элементы массива
	for (int i = 0; i < 10; i++)
	{
		printf("m[%d]=", i);
		scanf("%d", &m[i]);
	}
	shellSort(m, 10); // вызываем функцию сортировки
	// Выводим отсортированные элементы массива
	for (int i = 0; i < 10; i++)
		printf("%.2d ", m[i]);
	getchar(); getchar();
	return 0;
}*/


// Пример 6
/*#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
// Блохнов Сергей

// Функция быстрой сортировки
void quickSort(int *numbers, int left, int right)
{
	int pivot; // разрешающий элемент
	int l_hold = left; //левая граница
	int r_hold = right; // правая граница
	pivot = numbers[left];
	while (left < right) // пока границы не сомкнутся
	{
		while ((numbers[right] >= pivot) && (left < right))
			right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
		if (left != right) // если границы не сомкнулись
		{
			numbers[left] = numbers[right]; // перемещаем элемент [right] на место разрешающего
			left++; // сдвигаем левую границу вправо
		}
		while ((numbers[left] <= pivot) && (left < right))
			left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
		if (left != right) // если границы не сомкнулись
		{
			numbers[right] = numbers[left]; // перемещаем элемент [left] на место [right]
			right--; // сдвигаем правую границу вправо
		}
	}
	numbers[left] = pivot; // ставим разрешающий элемент на место
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
		quickSort(numbers, left, pivot - 1);
	if (right > pivot)
		quickSort(numbers, pivot + 1, right);
}
int main()
{
	int a[SIZE];
	// Заполнение массива случайными числами
	for (int i = 0; i < SIZE; i++)
		a[i] = rand() % 201 - 100;
	// Вывод элементов массива до сортировки
	for (int i = 0; i < SIZE; i++)
		printf("%4d ", a[i]);
	printf("\n");
	quickSort(a, 0, SIZE - 1); // вызов функции сортировки
			  // Вывод элементов массива после сортировки
	for (int i = 0; i < SIZE; i++)
		printf("%4d ", a[i]);
	printf("\n");
	getchar();
	return 0;
}
*/

// Пример 7
/*
#include <stdio.h>
#include <stdlib.h>
// Блохнов Сергей

// Функция сортировки двухпутевым слиянием
void merge(int *a, int n)
{
	int mid = n / 2; // находим середину сортируемой последовательности
	if (n % 2 == 1)
		mid++;
	int h = 1; // шаг
	// выделяем память под формируемую последовательность
	int *c = (int*)malloc(n * sizeof(int));
	int step;
	while (h < n)
	{
		step = h;
		int i = 0;   // индекс первого пути
		int j = mid; // индекс второго пути
		int k = 0;   // индекс элемента в результирующей последовательности
		while (step <= mid)
		{
			while ((i < step) && (j < n) && (j < (mid + step)))
			{ // пока не дошли до конца пути
			  // заполняем следующий элемент формируемой последовательности
			  // меньшим из двух просматриваемых
				if (a[i] < a[j])
				{
					c[k] = a[i];
					i++; k++;
				}
				else {
					c[k] = a[j];
					j++; k++;
				}
			}
			while (i < step)
			{ // переписываем оставшиеся элементы первого пути (если второй кончился раньше)
				c[k] = a[i];
				i++; k++;
			}
			while ((j < (mid + step)) && (j < n))
			{  // переписываем оставшиеся элементы второго пути (если первый кончился раньше)
				c[k] = a[j];
				j++; k++;
			}
			step = step + h; // переходим к следующему этапу
		}
		h = h * 2;
		// Переносим упорядоченную последовательность (промежуточный вариант) в исходный массив
		for (i = 0; i < n; i++)
			a[i] = c[i];
	}
}
int main()
{
	int a[8];
	// Заполнение массива случайными числами
	for (int i = 0; i < 8; i++)
		a[i] = rand() % 20 - 10;
	// Вывод элементов массива до сортировки
	for (int i = 0; i < 8; i++)
		printf("%d ", a[i]);
	printf("\n");
	merge(a, 8); // вызов функции сортировки
	// Вывод элементов массива после сортировки
	for (int i = 0; i < 8; i++)
		printf("%d ", a[i]);
	printf("\n");
	getchar();
	return 0;
}
*/

// Самостоятельная работа
// Пример 8
/*
#include <stdio.h>
#include <locale.h>
//Блохнов Сергей


int TrSort(int *arr, int amount)
{
	int perAm = 0;
	for (int i = 0; i < amount-1; i++)
	{
		if (arr[i]>arr[i+1])
		{
			int *temp = arr[i+1];
			arr[i + 1] = arr[i];
			arr[i] = temp;
			i = -1;
			perAm++;
		}
	}
	return perAm;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	int a[10];
	int shifts;
	for (int i = 0; i < 10; i++)
		a[i] = rand() % 100 - 25; // заполняем рандомом
	for (int i = 0; i < 10; i++)
		printf("%d ", a[i]); // Печать первоначального массива
	printf("\n");
	shifts = TrSort(a, 10); // Непосредственно ф-я с сортировкой
	for (int i = 0; i < 10; i++)
		printf("%d ", a[i]); // Печать отсортированого массива
	printf("\n");
	printf("Было произведено %d перестановок", shifts);
	getchar();
	return 0;
}*/


// ЛАБА 5

// Пример 1-4
/*
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// Блохнов Сергей

typedef struct TNode *PNode;
struct TNode
{
	int key; // ключ записи
	PNode LNode, RNode;
	char *word; // Текст записи
};

// Построение бинарного дерева
PNode AddNode(PNode tree, char *word, int key)
{
	if (tree == NULL) 
	{
		PNode node = (PNode)malloc(sizeof(PNode));
		node->key = key;
		node->word = word;
		node->LNode = NULL;
		node->RNode = NULL;
		return node;
	}
	else if(tree->key > key)
	{
		tree->LNode = AddNode(tree->LNode, word, key);
		return tree;
	}
	else
	{
		tree->RNode = AddNode(tree->RNode, word, key);
		return tree;
	}
}

// Обход сверху вниз
void TreePrintUpDown(PNode tree)
{
	if (tree != NULL)
	{
		printf_s("\nКлюч: %d", tree->key);
		TreePrintUpDown(tree->LNode);
		TreePrintUpDown(tree->RNode);
	}
}

// Обход слева направо
void TreePrintLeftToRight(PNode tree)
{
	if (tree != NULL)
	{
		TreePrintLeftToRight(tree->LNode);
		printf_s("\nКлюч: %d", tree->key);
		TreePrintLeftToRight(tree->RNode);
	}
}

// Обход снизу вверх
void TreePrintDownToUp(PNode tree)
{
	if (tree != NULL)
	{
		TreePrintDownToUp(tree->LNode);
		TreePrintDownToUp(tree->RNode);
		printf_s("\nКлюч: %d", tree->key);
	}
}

void main()
{
	setlocale(LC_ALL, "RUS");
	char word[100];
	int key;
	PNode root = NULL;
	printf("Введите ключ: ");
	scanf_s("%d", &key);
	printf("\nВведите значение записи: ");
	scanf_s("%s", word, 100);
	root = AddNode(root, word, key); 

	// Для тестирования запишем в дерево массив данных с ключами
	int keys[6] = {18, 6, 21, 1, 13, 15};
	char *words[6] = { "Data1", "Data2", "Data3", "Data4", "Data5", "Data6" };
	for (int k = 0; k<6;k++)
		root = AddNode(root, words[k], keys[k]);

//	TreePrintUpDown(root); // Обход сверху вниз
//	TreePrintLeftToRight(root); // Обход слева направо
	TreePrintDownToUp(root);
	getchar(); getchar();
}
*/

// Пример 5
/*
#include <stdio.h>
#include <locale.h>
// Блохнов Сергей


// Линейный поиск
void LineSearch(int *arr, int x, int amount)
{
	for (int i = 0; i<amount; i++)
	{
		if (arr[i] > x)
			printf("%d ", arr[i]);
	}
}

// Бинарный поиск
void BinSearch(int *arr, int x, int amount)
{
	int left = 0;
	int right = amount;
	while (arr[left] <= x)
	{
		int mid = (left + right) / 2;
		if (arr[mid] < x)
		{
			left = mid + 1;
		}
		else
		{
			left++;
		}
	}
	for (int i = left; i < amount; i++)
		printf("%d ", arr[i]);
}

// Индексный поиск
void IndexSearch(int *arr, int x, int amount)
{
	int indx[4];
	int pindx[4];
	for (int n = 0, m = 0; n < 20; n+=8, m++)
	{
		indx[m] = arr[n];
		pindx[m] = n;
	}
	int i = 0;
	while (indx[i] < x)
		i++;
	for (int j = pindx[i - 1]; j<amount; j++)
		if (arr[j] > x)
			printf("%d ", arr[j]);
}

void main()
{
	setlocale(LC_ALL, "RUS");
	int arr[10] = { 10, 13, 14, 20, 25, 28, 31, 38, 50, 90 }; // Упорядоченный массив
	printf("Линейный поиск: ");
	LineSearch(arr, 30, 10); 
	printf("\nБинарный поиск: ");
	BinSearch(arr, 30, 10);
	printf("\nИндексный поиск: ");
	IndexSearch(arr, 30, 10);
	getchar();
}
*/



// ЛАБА 6

// Пример 1
/*
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// Блохнов Сергей


// Структура простого односвязного списка
struct Node
{
	int data;
	struct Node *Next;
};
typedef struct Node List;

// Переупорядочивание списка с перестановкой найденного элемента в начало
List* Reordering(List *list, int x)
{
	List *l = list;
	List *l0 = NULL;
	while (l != NULL)
	{
		if (l->data == x)
		{
			printf("\nИскомое значение найдено!\n");
			if(l0!= NULL)
				l0->Next = l->Next;
			List *temp = list;
			list = l;
			list->Next = temp;
			return l;
		}
		l0 = l;
		l = l->Next;
	}
	return NULL;
}


void main()
{
	setlocale(LC_ALL, "RUS");
	// Для тестирования быстро инициализируем список из 4 элементов
	List testList3 = { 25, NULL };
	List testList2 = { 20, &testList3 };
	List testList1 = { 15, &testList2 };
	List dataList = { 10, &testList1 };
	printf("Первоначальное состояние списка: \n");
	List *l = &dataList;
	while (l != NULL)
	{
		printf("%d ", l->data);
		l = l->Next;
	}
	int searchableElement;
	printf("\nВведите значение элемента, которое необходимо найти: ");
	scanf_s("%d", &searchableElement);
	// Переупорядочивание списка с перестановкой найденного элемента в начало
	l = Reordering(&dataList, searchableElement);
	// Вывод переупорядоченного списка
	while (l != NULL)
	{
		printf("%d ", l->data);
		l = l->Next;
	}
	getchar(); getchar();
}
*/

// Пример 2
/*
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// Блохнов Сергей


// Структура простого односвязного списка
struct Node
{
	int data;
	struct Node *Next;
};
typedef struct Node List;

// ф-я транспонирования
List* Transponition(List *list, int x)
{
	List *l = list;
	List *l0 = NULL; // Порядок указателей в списке: l0 l1 l 
	List *l1 = NULL;
	if (l->data != x)
	{
		l1 = l;
		l = l->Next;
		while (l != NULL)
		{
			if (l->data == x)
			{
				printf("\nИскомое значение найдено!\n");
				if (l0 != NULL) // l0 l l1
					l0->Next = l;
				l1->Next = l->Next;
				l->Next = l1;
				return list;
			}
			l0 = l1;
			l1 = l;
			l = l->Next;
		}
	}
	else {
		printf("\nИскомое значение найдено!\n");
		return list;
	}
}


void main()
{
	setlocale(LC_ALL, "RUS");
	// Для тестирования быстро инициализируем список из 6 элементов
	List testList5 = { 35, NULL };
	List testList4 = { 30, &testList5 };
	List testList3 = { 25, &testList4 };
	List testList2 = { 20, &testList3 };
	List testList1 = { 15, &testList2 };
	List dataList = { 10, &testList1 };
	printf("Первоначальное состояние списка: \n");
	List *l = &dataList;
	while (l != NULL)
	{
		printf("%d ", l->data);
		l = l->Next;
	}
	int searchableElement;
	printf("\nВведите значение элемента, которое необходимо найти: ");
	scanf_s("%d", &searchableElement);

	// Функция с транспозицией
	l = Transponition(&dataList, searchableElement);
	
	// Вывод нового списка
	while (l != NULL)
	{
		printf("%d ", l->data);
		l = l->Next;
	}
	getchar(); getchar();
}*/

// Самостоятельная работа
// Пример 3
/*
#include <stdio.h>
#include <locale.h>
// Блохнов Сергей 

// Алгоритм переупорядочивания
void Reordering(int *nums, int amount)
{
	int min = NULL;
	int minindx;
	for (int k = 0; k < amount; k++)
	{
		if (nums[k] < min || min == NULL)
		{
			min = nums[k];
			minindx = k; 
		}
	}
	int temp = nums[0];
	int temp1;
	nums[0] = min;
	for (int k = 1; k < amount; k++)
	{ 
		if (k == minindx)
		{
			temp1 = nums[k + 1];
			nums[k] = temp;
			temp = temp1;
		}else 
		{
		temp1 = nums[k];
		nums[k] = temp;
		temp = temp1;
		}
	}
}

// Метод транспозиции
void Transposition(int *nums, int amount)
{
	int min = NULL;
	int minindx;
	for (int k = 0; k < amount; k++)
	{
		if (nums[k] < min || min == NULL)
		{
			min = nums[k];
			minindx = k;
		}
	}
	if (minindx != 0)
	{
		int temp = nums[minindx - 1];
		nums[minindx - 1] = min;
		nums[minindx] = temp;
		if ((minindx - 1) != 0)
			Transposition(nums, amount);
	}
}

void main()
{
	setlocale(LC_ALL, "RUS");
	int numbers1[20] = { 20,19,18,17,16,15,9,8,7,6,5,4,3,2,1,14,13,12,11,10,}; // наименьший элемент - 1, его индекс - 14
	int numbers2[20] = { 20,19,18,17,16,15,9,8,7,6,5,4,3,2,1,14,13,12,11,10, }; 

	printf("Первоначальный массив: \n");
	for (int i = 0; i < 20; i++)
	{
		printf("%d ", numbers1[i]);
	}
	printf("\nАлгоритм переупорядочивания: \n");
	Reordering(numbers1, 20);
	for (int i = 0; i < 20; i++)
	{
		printf("%d ", numbers1[i]);
	}
	printf("\nМетод транспозиции: \n");
	Transposition(numbers2, 20);
	for (int i = 0; i < 20; i++)
	{
		printf("%d ", numbers2[i]);
	}
	getchar(); getchar();
}
*/
