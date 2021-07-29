
// ���� 4

// ������ 1
/*
#define _CRT_SECURE_NO_WARNINGS // ��� ���������� ������ scanf()
#include <stdio.h>
// ������� ������


// ������� ���������� ������� �����������
void inclusionSort(int *num, int size)
{
	// ��� ���� ��������� ����� ����������
	for (int i = 1; i < size; i++)
	{
		int value = num[i]; // ���������� �������� ��������
		int index = i;     // � ��� ������
		while ((index > 0) && (num[index - 1] > value))
		{   // ������� ������ �������� � ����� ������� ���� ��� ������ index
			num[index] = num[index - 1];
			index--;    // ������� �������� � ������ �������
		}
		num[index] = value; // ��������������� ������� �������� �� �������������� �����
	}
}
int main()
{
	int a[10]; // ��������� ������ �� 10 ���������
	// ������ �������� ��������� �������
	for (int i = 0; i < 10; i++)
	{
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	inclusionSort(a, 10);  // �������� ������� ����������
	// ������� ��������������� �������� �������
	for (int i = 0; i < 10; i++)
		printf("%d ", a[i]);
	getchar(); getchar();
	return 0;
}
*/

// ������ 2
/*
#define _CRT_SECURE_NO_WARNINGS // ��� ���������� ������ scanf()
#include <stdio.h>
// ������� ������


// ������� ���������� ������ �������
void selectionSort(int *num, int size)
{
	int min, temp; // ��� ������ ������������ �������� � ��� ������
	for (int i = 0; i < size - 1; i++)
	{
		min = i; // ���������� ������ �������� ��������
		// ���� ����������� ������� ����� ��������� �� ����� i-���
		for (int j = i + 1; j < size; j++)  // ��� ��������� ��������� ����� i-���
		{
			if (num[j] < num[min]) // ���� ������� ������ ������������,
				min = j;       // ���������� ��� ������ � min
		}
		temp = num[i];      // ������ ������� i-�� � ����������� ��������
		num[i] = num[min];
		num[min] = temp;
	}
}
int main()
{
	int a[10]; // ��������� ������ �� 10 ���������
	// ������ �������� ��������� �������
	for (int i = 0; i < 10; i++)
	{
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	selectionSort(a, 10);  // �������� ������� ����������
	// ������� ��������������� �������� �������
	for (int i = 0; i < 10; i++)
		printf("%d ", a[i]);
	getchar(); getchar();
	return 0;
}
*/

// ������ 3
/*
#define _CRT_SECURE_NO_WARNINGS // ��� ���������� ������ scanf()
#include <stdio.h>
// ������� ������

// ������� ���������� ������ ������� (����� "��������")
void bubbleSort(int *num, int size)
{
	// ��� ���� ���������
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = (size - 1); j > i; j--) // ��� ���� ��������� ����� i-���
		{
			if (num[j - 1] > num[j]) // ���� ������� ������� ������ �����������
			{
				int temp = num[j - 1]; // ������ �� �������
				num[j - 1] = num[j];
				num[j] = temp;
			}
		}
	}
}
int main()
{
	int a[10]; // ��������� ������ �� 10 ���������
	// ������ �������� ��������� �������
	for (int i = 0; i < 10; i++)
	{
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	bubbleSort(a, 10);  // �������� ������� ����������
	// ������� ��������������� �������� �������
	for (int i = 0; i < 10; i++)
		printf("%d ", a[i]);
	getchar(); getchar();
	return 0;
}
*/


// ������ 4
/*
#define _CRT_SECURE_NO_WARNINGS // ��� ���������� ������ scanf()
#include <stdio.h>
// ������� ������

// ������� ������-����������
void shekerSort(double *mass, int count)
{
	int left = 0, right = count - 1; // ����� � ������ ������� ����������� ������� �������
	int flag = 1;  // ���� ������� �����������
	// ���������� ����� ���� ����� ������� �� �������� � ������
	// � ���� � ������� ������� �����������
	while ((left < right) && flag > 0)
	{
		flag = 0;
		for (int i = left; i < right; i++)  //��������� ����� �������
		{
			if (mass[i] > mass[i + 1]) // ���� ��������� ������� ������ ��������,
			{             // ������ �� �������
				double t = mass[i];
				mass[i] = mass[i + 1];
				mass[i + 1] = t;
				flag = 1;      // ����������� � ���� ����� ����
			}
		}
		right--; // �������� ������ ������� �� ���������� �������
		for (int i = right; i > left; i--)  //��������� ������ ������
		{
			if (mass[i - 1] > mass[i]) // ���� ���������� ������� ������ ��������,
			{            // ������ �� �������
				double t = mass[i];
				mass[i] = mass[i - 1];
				mass[i - 1] = t;
				flag = 1;    // ����������� � ���� ����� ����
			}
		}
		left++; // �������� ����� ������� �� ��������� �������
	}
}
int main() {
	double m[10];
	// ������ �������� �������
	for (int i = 0; i < 10; i++) {
		printf("m[%d]=", i);
		scanf("%lf", &m[i]);
	}
	shekerSort(m, 10); // �������� ������� ����������
	// ������� ��������������� �������� �������
	for (int i = 0; i < 10; i++)
		printf("%.2lf ", m[i]);
	getchar(); getchar();
	return 0;
}
*/

// ������ 5
/*#define _CRT_SECURE_NO_WARNINGS // ��� ���������� ������ scanf()
#include <stdio.h>
// ������� ������

// ������� ���������� �����
void shellSort(int *num, int size)
{
	int increment = 3;    // ��������� ���������� ����������
	while (increment > 0)  // ���� ���������� ����������
	{
		for (int i = 0; i < size; i++)  // ��� ���� ��������� �������
		{
			int j = i;          // ��������� ������ � �������
			int temp = num[i];
			// ������������� ��������� �������� �������, ��������� �� j-���
			// �� �������� ����������
			while ((j >= increment) && (num[j - increment] > temp))
			{  // ���� ��������� ������� ������ ��������
				num[j] = num[j - increment]; // ���������� ��� �� ������� �������
				j = j - increment;       // ��������� � ���������� ���������� ��������
			}
			num[j] = temp; // �� ���������� ����� �������� ���������� �������
		}
		if (increment > 1)      // ����� ���������� �� 2
			increment = increment / 2;
		else if (increment == 1)   // ��������� ������ ��������,
			break;  // ������� �� �����
	}
}
int main()
{
	int m[10];
	// ������ �������� �������
	for (int i = 0; i < 10; i++)
	{
		printf("m[%d]=", i);
		scanf("%d", &m[i]);
	}
	shellSort(m, 10); // �������� ������� ����������
	// ������� ��������������� �������� �������
	for (int i = 0; i < 10; i++)
		printf("%.2d ", m[i]);
	getchar(); getchar();
	return 0;
}*/


// ������ 6
/*#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
// ������� ������

// ������� ������� ����������
void quickSort(int *numbers, int left, int right)
{
	int pivot; // ����������� �������
	int l_hold = left; //����� �������
	int r_hold = right; // ������ �������
	pivot = numbers[left];
	while (left < right) // ���� ������� �� ���������
	{
		while ((numbers[right] >= pivot) && (left < right))
			right--; // �������� ������ ������� ���� ������� [right] ������ [pivot]
		if (left != right) // ���� ������� �� ����������
		{
			numbers[left] = numbers[right]; // ���������� ������� [right] �� ����� ������������
			left++; // �������� ����� ������� ������
		}
		while ((numbers[left] <= pivot) && (left < right))
			left++; // �������� ����� ������� ���� ������� [left] ������ [pivot]
		if (left != right) // ���� ������� �� ����������
		{
			numbers[right] = numbers[left]; // ���������� ������� [left] �� ����� [right]
			right--; // �������� ������ ������� ������
		}
	}
	numbers[left] = pivot; // ������ ����������� ������� �� �����
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) // ���������� �������� ���������� ��� ����� � ������ ����� �������
		quickSort(numbers, left, pivot - 1);
	if (right > pivot)
		quickSort(numbers, pivot + 1, right);
}
int main()
{
	int a[SIZE];
	// ���������� ������� ���������� �������
	for (int i = 0; i < SIZE; i++)
		a[i] = rand() % 201 - 100;
	// ����� ��������� ������� �� ����������
	for (int i = 0; i < SIZE; i++)
		printf("%4d ", a[i]);
	printf("\n");
	quickSort(a, 0, SIZE - 1); // ����� ������� ����������
			  // ����� ��������� ������� ����� ����������
	for (int i = 0; i < SIZE; i++)
		printf("%4d ", a[i]);
	printf("\n");
	getchar();
	return 0;
}
*/

// ������ 7
/*
#include <stdio.h>
#include <stdlib.h>
// ������� ������

// ������� ���������� ����������� ��������
void merge(int *a, int n)
{
	int mid = n / 2; // ������� �������� ����������� ������������������
	if (n % 2 == 1)
		mid++;
	int h = 1; // ���
	// �������� ������ ��� ����������� ������������������
	int *c = (int*)malloc(n * sizeof(int));
	int step;
	while (h < n)
	{
		step = h;
		int i = 0;   // ������ ������� ����
		int j = mid; // ������ ������� ����
		int k = 0;   // ������ �������� � �������������� ������������������
		while (step <= mid)
		{
			while ((i < step) && (j < n) && (j < (mid + step)))
			{ // ���� �� ����� �� ����� ����
			  // ��������� ��������� ������� ����������� ������������������
			  // ������� �� ���� ���������������
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
			{ // ������������ ���������� �������� ������� ���� (���� ������ �������� ������)
				c[k] = a[i];
				i++; k++;
			}
			while ((j < (mid + step)) && (j < n))
			{  // ������������ ���������� �������� ������� ���� (���� ������ �������� ������)
				c[k] = a[j];
				j++; k++;
			}
			step = step + h; // ��������� � ���������� �����
		}
		h = h * 2;
		// ��������� ������������� ������������������ (������������� �������) � �������� ������
		for (i = 0; i < n; i++)
			a[i] = c[i];
	}
}
int main()
{
	int a[8];
	// ���������� ������� ���������� �������
	for (int i = 0; i < 8; i++)
		a[i] = rand() % 20 - 10;
	// ����� ��������� ������� �� ����������
	for (int i = 0; i < 8; i++)
		printf("%d ", a[i]);
	printf("\n");
	merge(a, 8); // ����� ������� ����������
	// ����� ��������� ������� ����� ����������
	for (int i = 0; i < 8; i++)
		printf("%d ", a[i]);
	printf("\n");
	getchar();
	return 0;
}
*/

// ��������������� ������
// ������ 8
/*
#include <stdio.h>
#include <locale.h>
//������� ������


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
		a[i] = rand() % 100 - 25; // ��������� ��������
	for (int i = 0; i < 10; i++)
		printf("%d ", a[i]); // ������ ��������������� �������
	printf("\n");
	shifts = TrSort(a, 10); // ��������������� �-� � �����������
	for (int i = 0; i < 10; i++)
		printf("%d ", a[i]); // ������ ��������������� �������
	printf("\n");
	printf("���� ����������� %d ������������", shifts);
	getchar();
	return 0;
}*/


// ���� 5

// ������ 1-4
/*
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// ������� ������

typedef struct TNode *PNode;
struct TNode
{
	int key; // ���� ������
	PNode LNode, RNode;
	char *word; // ����� ������
};

// ���������� ��������� ������
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

// ����� ������ ����
void TreePrintUpDown(PNode tree)
{
	if (tree != NULL)
	{
		printf_s("\n����: %d", tree->key);
		TreePrintUpDown(tree->LNode);
		TreePrintUpDown(tree->RNode);
	}
}

// ����� ����� �������
void TreePrintLeftToRight(PNode tree)
{
	if (tree != NULL)
	{
		TreePrintLeftToRight(tree->LNode);
		printf_s("\n����: %d", tree->key);
		TreePrintLeftToRight(tree->RNode);
	}
}

// ����� ����� �����
void TreePrintDownToUp(PNode tree)
{
	if (tree != NULL)
	{
		TreePrintDownToUp(tree->LNode);
		TreePrintDownToUp(tree->RNode);
		printf_s("\n����: %d", tree->key);
	}
}

void main()
{
	setlocale(LC_ALL, "RUS");
	char word[100];
	int key;
	PNode root = NULL;
	printf("������� ����: ");
	scanf_s("%d", &key);
	printf("\n������� �������� ������: ");
	scanf_s("%s", word, 100);
	root = AddNode(root, word, key); 

	// ��� ������������ ������� � ������ ������ ������ � �������
	int keys[6] = {18, 6, 21, 1, 13, 15};
	char *words[6] = { "Data1", "Data2", "Data3", "Data4", "Data5", "Data6" };
	for (int k = 0; k<6;k++)
		root = AddNode(root, words[k], keys[k]);

//	TreePrintUpDown(root); // ����� ������ ����
//	TreePrintLeftToRight(root); // ����� ����� �������
	TreePrintDownToUp(root);
	getchar(); getchar();
}
*/

// ������ 5
/*
#include <stdio.h>
#include <locale.h>
// ������� ������


// �������� �����
void LineSearch(int *arr, int x, int amount)
{
	for (int i = 0; i<amount; i++)
	{
		if (arr[i] > x)
			printf("%d ", arr[i]);
	}
}

// �������� �����
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

// ��������� �����
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
	int arr[10] = { 10, 13, 14, 20, 25, 28, 31, 38, 50, 90 }; // ������������� ������
	printf("�������� �����: ");
	LineSearch(arr, 30, 10); 
	printf("\n�������� �����: ");
	BinSearch(arr, 30, 10);
	printf("\n��������� �����: ");
	IndexSearch(arr, 30, 10);
	getchar();
}
*/



// ���� 6

// ������ 1
/*
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// ������� ������


// ��������� �������� ������������ ������
struct Node
{
	int data;
	struct Node *Next;
};
typedef struct Node List;

// ������������������ ������ � ������������� ���������� �������� � ������
List* Reordering(List *list, int x)
{
	List *l = list;
	List *l0 = NULL;
	while (l != NULL)
	{
		if (l->data == x)
		{
			printf("\n������� �������� �������!\n");
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
	// ��� ������������ ������ �������������� ������ �� 4 ���������
	List testList3 = { 25, NULL };
	List testList2 = { 20, &testList3 };
	List testList1 = { 15, &testList2 };
	List dataList = { 10, &testList1 };
	printf("�������������� ��������� ������: \n");
	List *l = &dataList;
	while (l != NULL)
	{
		printf("%d ", l->data);
		l = l->Next;
	}
	int searchableElement;
	printf("\n������� �������� ��������, ������� ���������� �����: ");
	scanf_s("%d", &searchableElement);
	// ������������������ ������ � ������������� ���������� �������� � ������
	l = Reordering(&dataList, searchableElement);
	// ����� ������������������ ������
	while (l != NULL)
	{
		printf("%d ", l->data);
		l = l->Next;
	}
	getchar(); getchar();
}
*/

// ������ 2
/*
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// ������� ������


// ��������� �������� ������������ ������
struct Node
{
	int data;
	struct Node *Next;
};
typedef struct Node List;

// �-� ����������������
List* Transponition(List *list, int x)
{
	List *l = list;
	List *l0 = NULL; // ������� ���������� � ������: l0 l1 l 
	List *l1 = NULL;
	if (l->data != x)
	{
		l1 = l;
		l = l->Next;
		while (l != NULL)
		{
			if (l->data == x)
			{
				printf("\n������� �������� �������!\n");
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
		printf("\n������� �������� �������!\n");
		return list;
	}
}


void main()
{
	setlocale(LC_ALL, "RUS");
	// ��� ������������ ������ �������������� ������ �� 6 ���������
	List testList5 = { 35, NULL };
	List testList4 = { 30, &testList5 };
	List testList3 = { 25, &testList4 };
	List testList2 = { 20, &testList3 };
	List testList1 = { 15, &testList2 };
	List dataList = { 10, &testList1 };
	printf("�������������� ��������� ������: \n");
	List *l = &dataList;
	while (l != NULL)
	{
		printf("%d ", l->data);
		l = l->Next;
	}
	int searchableElement;
	printf("\n������� �������� ��������, ������� ���������� �����: ");
	scanf_s("%d", &searchableElement);

	// ������� � �������������
	l = Transponition(&dataList, searchableElement);
	
	// ����� ������ ������
	while (l != NULL)
	{
		printf("%d ", l->data);
		l = l->Next;
	}
	getchar(); getchar();
}*/

// ��������������� ������
// ������ 3
/*
#include <stdio.h>
#include <locale.h>
// ������� ������ 

// �������� ������������������
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

// ����� ������������
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
	int numbers1[20] = { 20,19,18,17,16,15,9,8,7,6,5,4,3,2,1,14,13,12,11,10,}; // ���������� ������� - 1, ��� ������ - 14
	int numbers2[20] = { 20,19,18,17,16,15,9,8,7,6,5,4,3,2,1,14,13,12,11,10, }; 

	printf("�������������� ������: \n");
	for (int i = 0; i < 20; i++)
	{
		printf("%d ", numbers1[i]);
	}
	printf("\n�������� ������������������: \n");
	Reordering(numbers1, 20);
	for (int i = 0; i < 20; i++)
	{
		printf("%d ", numbers1[i]);
	}
	printf("\n����� ������������: \n");
	Transposition(numbers2, 20);
	for (int i = 0; i < 20; i++)
	{
		printf("%d ", numbers2[i]);
	}
	getchar(); getchar();
}
*/
