// ���� 1

// ������ 1
/*
#include <conio.h>
#include <stdio.h>

int sum(int a, int b) {
	return a + b;
}
//������� ������

void main() {
	//��������� ��������� �� �������
	int(*fptr)(int, int) = NULL;
	int result;
	//����������� ��������� �������� - ����� �������
	//��� ������ �� ������ � ��������: �������� ������ ������ ������������ �� �����
	fptr = sum;
	//����� �������������� �����, ��� � ������� �������
	result = fptr(10, 40);
	printf("%d", result);
	_getch();
}
*/

// ������ 2
/*
#include <conio.h>
#include <stdio.h>
//������� ������

int dble(int a) {
	return 2 * a;
}

int deleteEven(int a) {
	if (a % 2 == 0) {
		return 0;
	}
	else {
		return a;
	}
}

//������� ��������� ������, ��� ������ � ��������� �� �������,
//������� ����� ����������� �� ���� ��������� �������
void map(int *arr, unsigned size, int(*fun)(int)) {
	unsigned i;
	for (i = 0; i < size; i++) {
		arr[i] = fun(arr[i]);
	}
}

void main() {
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	unsigned i;
	map(a, 10, deleteEven);
	for (i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
	map(a, 10, dble);
	printf("\n");
	for (i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
	_getch();
}
*/

// ������ 3
/*
#include <conio.h>
#include <stdio.h>
// ������� ������

void dbleInt(void *a) {
	*((int*)a) *= 2;
}

void deleteEvenInt(void* a) {
	int tmp = *((int*)a);
	if (tmp % 2 == 0) {
		*((int*)a) = 0;
	}
}

void dbleDouble(void *a) {
	*((double*)a) *= 2.0;
}

void deleteEvenDouble(void* a) {
	int tmp = *((double*)a);
	if (tmp % 2 == 0) {
		*((double*)a) = 0;
	}
}

//������� ��������� ������, ��� ������, ������ ������ �������� � ��������� �� �������,
//������� ����� ����������� �� ���� ��������� �������
void map(void *arr, unsigned num, size_t size, void(*fun)(void *)) {
	unsigned i;
	char *ptr = (char*)arr;
	for (i = 0; i < num; i++) {
		fun((void*)(ptr + i * size));
	}
}

void main() {
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	double b[] = { 1., 2., 3., 4., 5., 6., 7., 8., 9., 10. };
	unsigned i;
	//�������� � �������� ���� int
	map(a, 10, sizeof(int), deleteEvenInt);
	for (i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
	map(a, 10, sizeof(int), dbleInt);
	printf("\n");
	for (i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	//�������� � �������� ���� double
	map(b, 10, sizeof(double), deleteEvenDouble);
	for (i = 0; i < 10; i++) {
		printf("%.3f ", b[i]);
	}
	map(b, 10, sizeof(double), dbleDouble);
	printf("\n");
	for (i = 0; i < 10; i++) {
		printf("%.3f ", b[i]);
	}
	_getch();
}
*/

// ������ 4
/*#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
// ������� ������

int isOdd(int a) {
	return (a % 2 != 0);
}

int isGtThree(int a) {
	return a > 3;
}

unsigned int filter(int *arr, unsigned size, int(*pred)(int), int** out) {
	unsigned i;
	unsigned j; //������ ������������� ������   
	*out = (int*)malloc(sizeof(int)*size);
	for (i = 0, j = 0; i < size; i++) {
		if (pred(arr[i])) {
			(*out)[j] = arr[i];
			j++;
		}
	}
	*out = (int*)realloc(*out, j * sizeof(int));
	return j;
}

void main() {
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int *aOdd = NULL;
	int *aGtThree = NULL;
	unsigned i;
	unsigned size;

	size = filter(a, 10, isOdd, &aOdd);
	for (i = 0; i < size; i++) {
		printf("%d ", aOdd[i]);
	}
	printf("\n");
	size = filter(a, 10, isGtThree, &aGtThree);
	for (i = 0; i < size; i++) {
		printf("%d ", aGtThree[i]);
	}
	free(aOdd);
	free(aGtThree);
	_getch();
}
*/

// ������ 5
/*
#include <stdio.h>
#include <stdlib.h>
// ������� ������

typedef struct point_tag {
	float x;
	float y;
} point_t;

void foo(point_t point) {
	point.x = 100;
}

int main() {
	point_t p = { 10.0, 20.0 };

	printf("p.x = %.3f\n", p.x);
	foo(p);
	printf("p.x = %.3f", p.x);

	_getch();
	return 0;
}*/

// ������ 6
/*
#include <stdio.h>
#include <stdlib.h>
// ������� ������

typedef struct point_tag {
	float x;
	float y;
} point_t;

void foo(point_t *point) {
	point->x = 100;
}

int main() {
	point_t p = { 10.0, 20.0 };

	printf("p.x = %.3f\n", p.x);
	foo(&p);
	printf("p.x = %.3f", p.x);

	_getch();
	return 0;
}
*/

// ������ 7
/*
#include <stdio.h>
#include <stdlib.h>
// ������� ������

typedef struct point_tag {
	float x;
} point_t;

void foo(point_t *point) {
	point = malloc(sizeof(point_t));
	point->x = 100;
}

int main() {
	point_t *p = malloc(sizeof(point_t));
	p->x = 10;

	printf("p.x = %.3f\n", p->x);
	foo(p);
	printf("p.x = %.3f", p->x);

	_getch();
	free(p);
	return 0;
}
*/

// ������ 7.1
/*#include <stdio.h>
#include <stdlib.h>
// ������� ������

typedef struct point_tag {
	float x;
} point_t;

void foo(point_t **point) {
	free(*point);
	(*point) = malloc(sizeof(point_t));
	(*point)->x = 100;
}

int main() {
	point_t *p = malloc(sizeof(point_t));
	p->x = 10;

	printf("p.x = %.3f\n", p->x);
	foo(&p);
	printf("p.x = %.3f", p->x);

	_getch();
	free(p);
	return 0;
}
*/

// ��������������� �������
/*#include<locale.h>
#include<stdio.h>
// ������� ������

int Sum(int a, int b)
{
	return a + b;
}
int Razn(int a, int b)
{
	return a - b;
}
int Proiz(int a, int b)
{
	return a * b;
}
int Div(int a, int b)
{
	if (b != 0)
		return a / b;
	else
		return 0;
}
int Pow(int a, int b)
{
	int res = a;
	for (int i = 1; i < b; i++)
		res *= a;
	return res;
}
void main()
{
	setlocale(LC_ALL, "RUS");
	int fncNum;
	int n1, n2;
	int(*fncPointer) (int, int) = NULL;
	printf("�����������\n____________________________________________\n");
	do
	{
		printf("������� ������ �����: ");
		scanf_s("%d", &n1);
		printf("\n������� ������ �����: ");
		scanf_s("%d", &n2);
		printf("\n��������� �������:\n1.������� ��� �����\n2.������� ��� �����\n3.�������� ��� �����\n4.��������� ��� �����\n5.�������� ����� � �������\n____________\n0.����� �� ������� ������������\n");
		printf("������� ����� �������� �������: ");
		scanf_s("%d", &fncNum);
		switch (fncNum)
		{
		case 1:
			fncPointer = Sum;
			break;
		case 2:
			fncPointer = Razn;
			break;
		case 3:
			fncPointer = Proiz;
			break;
		case 4:
			fncPointer = Div;
			break;
		case 5:
			fncPointer = Pow;
			break;
		case 0:
			printf("���������� ������...\n");
			break;
		}
		printf("���������: %d\n", fncPointer(n1, n2));
	} while (fncNum != 0);
}*/



// ���� 2

// ������ 1
/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
// ������� ������

struct date {
	int day;
	char month[20];
	int year;
};
struct persone {
	char firstname[20];
	char lastname[20];
	struct date bd;
};
int main() {
	setlocale(LC_ALL, "RUS");
	system("cls");
	struct persone p;
	printf("������� ���: ");
	scanf("%s", p.firstname);
	printf("������� �������: ");
	scanf("%s", p.lastname);
	printf("������� ���� ��������\n�����: ");
	scanf("%d", &p.bd.day);
	printf("�����: ");
	scanf("%s", p.bd.month);
	printf("���: ");
	scanf("%d", &p.bd.year);
	printf("\n�� �����: %s %s, ���� �������� %d %s %d ����",
		p.firstname, p.lastname, p.bd.day, p.bd.month, p.bd.year);
	getchar(); getchar();
	return 0;
}
*/

// ������ 2
/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
// ������� ������

int main() {
	setlocale(LC_ALL, "RUS");
	char temp;

	system("cls");
	union
	{
		unsigned char p[2];
		unsigned int t;
	} type;
	printf("������� �����: ");
	scanf("%d", &type.t);
	printf("%d = %x �����.\n", type.t, type.t);
	// ������ ������
	temp = type.p[0];
	type.p[0] = type.p[1];
	type.p[1] = temp;
	printf("�������� ������� �����, ��������\n");
	printf("%d = %x �����.\n", type.t, type.t);
	getchar(); getchar();
	return 0;
}*/

// ������ 3
/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define YEAR0 1980
// ������� ������
struct date
{
	unsigned short day : 5;
	unsigned short month : 4;
	unsigned short year : 7;
};
int main() {
	setlocale(LC_ALL, "RUS");
	struct date today;
	system("cls");
	today.day = 11;
	today.month = 03;
	today.year = 2021 - YEAR0; 
	printf("\n ������� %u.%u.%u \n", today.day, today.month, today.year + YEAR0);
	printf("\n ������ ��������� today : %d ����", sizeof(today));
	printf("\n �������� �������� today = %hu = %hx �����.", today, today);
	getchar();
	return 0;
}*/

// ������ 5
/*
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// ������� ������
struct book
{
	char title[30];
	char author[30];
	int value;
};
int main()
{
	setlocale(LC_ALL, "RUS");
	struct book libry[3];
	int i;
	system("cls");
	for (i = 0; i < 3; i++)
	{
		printf("������� �������� %d �����: ", i + 1);
		gets_s(libry[i].title,sizeof(libry[i].title));
		printf("������� ������ %d �����: ", i + 1);
		gets_s(libry[i].author,sizeof(libry[i].author));
		printf("������� ���� %d �����: ", i + 1);
		scanf_s("%d", &libry[i].value);
		getchar();
	}
	for (i = 0; i < 3; i++)
	{
		printf("\n %d. %s ", i + 1, libry[i].author);
		printf("%s %d", libry[i].title, libry[i].value);
	}
	getchar();
	return 0;
}
*/

// ������ 6
/*
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>
// ������� ������

struct book
{
	char title[30];
	char author[30];
	int value;
};
int main()
{
	setlocale(LC_ALL, "RUS");
	struct book *lib;
	int i;
	system("cls");
	lib = (struct book*)malloc(3 * sizeof(struct book));
	for (i = 0; i < 3; i++)
	{
		printf("������� �������� %d �����: ", i + 1);
		gets_s((lib + i)->title, sizeof((lib + i)->title));
		printf("������� ������ %d �����: ", i + 1);
		gets_s((lib + i)->author, sizeof((lib + i)->author));
		printf("������� ���� %d �����: ", i + 1);
		scanf_s("%d", &(lib + i)->value);
		getchar();
	}
	for (i = 0; i < 3; i++)
	{
		printf("\n %d. %s ", i + 1, (lib + i)->author);
		printf("%s %d", (lib + i)->title, (lib + i)->value);
	}
	getchar();
	return 0;
}
*/

// ��������������� �������



// ���� 3

// ������ 1.
/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
// ������� ������

struct Node {
	char *word; //������� ������
	int count;
	struct Node *next; //������ �� ��������� ����
};
typedef struct Node *PNode;
PNode CreateNode(char *NewWord)
{
	struct Node node = {NewWord, 1, NULL};
	PNode NewNode = &node;
	return NewNode; 
}
void AddFirst(PNode Head, PNode NewNode)
{
	NewNode->next = Head;
	Head = NewNode;
}
void AddAfter(PNode p, PNode NewNode)
{
	NewNode->next = p->next;
	p->next = NewNode;
}
void AddBefore(PNode Head, PNode p, PNode NewNode)
{
	PNode q = Head;
	if (Head == p) {
		AddFirst(Head, NewNode); //������� ����� ������ �����
		return;
	}
	while (q != NULL && q->next != p) //���� ����, �� ������� ������� p
	{
		q = q->next;
	}
	if (q) //���� ����� ���� ������
	{
		AddAfter(q, NewNode); //�������� ����� ����� ����
	}
}
void AddLast(PNode Head, PNode NewNode)
{
	PNode q = Head;
	if (Head == NULL) //���� ������ ����
	{
		AddFirst(Head, NewNode); //��������� ������ �������
		return;
	}
	while (q->next != NULL) 
	{
		q = q->next; 
	}
	AddAfter(q, NewNode);
}
PNode Find(PNode Head, char NewWord[])
{
	PNode q = Head;
	while (q && strcmp(q->word, NewWord)) { q = q->next; }
	return q;
}
PNode FindPlace(PNode Head, char NewWord[])
{
	PNode q = Head;
	while (q && (strcmp(q->word, NewWord) > 0)) { q = q->next; }
	return q;
}

// ������ 1
int main()
{
	PNode Head = NULL, p, where;
	FILE *in, *out;
	char word[80];
	int n;
	in = fopen("input.txt", "r");

	while (1)
	{
		n = fscanf(in, "%s", word); //������ ����� �� �����
		if (n <= 0) break;

		p = Find(Head, word); //���� ����� � ������
		if (p != NULL) { p->count++; } //���� ����� �����, ����������� �������
		else
		{
			p = CreateNode(word); //������ ����� ����
			where = FindPlace(Head, word); //���� �����
			if (!where) { AddLast(Head, p); }
			else { AddBefore(Head, where, p); }
		}

	}
	fclose(in);
	out = fopen("output.txt", "w");
	p = Head;
	while (p)
	{
		fprintf(out, "%s - %d\n", p->word, p->count);
		p = p->next;
	}
	fclose(out);
}
*/

// ������ 2
/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include <string.h>

struct DNode
{
	char word[40]; // ������� ������
	int count;
	struct DNode *next, *prev; //������ �� �������� ����
};
typedef struct DNode *PDNode;

void AddFirst(PDNode Head, PDNode Tail, PDNode NewNode)
{
	NewNode->next = Head;
	NewNode->prev = NULL;
	if (Head) 
	{ 
		Head->prev = NewNode; 
	}
	Head = NewNode;
	if (!Tail) { 
		Tail = Head; 
	}
}
void AddLast(PDNode Head, PDNode Tail, PDNode NewNode)
{
	NewNode->prev = Tail;
	NewNode->next = NULL;
	if (Tail)
	{
		Tail->next = NewNode;
	}
	Tail = NewNode;
	if (!Head) {
		Head = Tail;
	}
}

void Delete(PDNode Head, PDNode Tail, PDNode OldNode)
{
	if (Head == OldNode)
	{
		Head = OldNode->next; //������� ������ �������
		if (Head) { Head->prev = NULL; }
		else { Tail = NULL; } //������� ������������ �������
	}
	else
	{
		OldNode->prev->next = OldNode->next;
		if (OldNode->next) { OldNode->next->prev = OldNode->prev; }
		else { 
			Tail = NULL; 
		} //������� ��������� �������
	}
	free(OldNode);
}
void AddAfter(PDNode Head, PDNode Tail, PDNode p, PDNode NewNode)
{
	if (!p->next) { 
		AddLast(Head, Tail, NewNode);
	}
	else
	{
		NewNode->next = p->next;
		NewNode->prev = p;
		p->next->prev = NewNode;
		p->next = NewNode;
	}
}

int main()
{
	printf("All good");
}*/

// ������ 3
/*#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
// ������� ������

const int MAXSIZE = 100;
typedef struct {
	char data[100];
	int size;
}Stack;
Stack Push(Stack S, char x)
{
	if (S.size == MAXSIZE) {
		printf("���� ����������");
		return S;
	}
	S.data[S.size] = x;
	S.size++;
	return S;
}
Stack Pop(Stack S)
{
	if (S.size == 0) {
		printf("���� ����");
		char n = 255;
		return S;
	}
	S.size--;
	return S;
}

void main()
{
	setlocale(LC_ALL, "RUS");
	char br1[3] = { 40, 91, 123 }; 
	char br2[3] = { 41, 93, 125 }; 
	char s[80], upper;
	int i, k, OK;
	Stack S; 
	printf("������� ��������� �� ��������> ");
	scanf_s("%s", s,80);
	S.size = 0; 
	OK = 1;
	for (i = 0; OK && (s[i] != '\0'); i++)
		for (k = 0; k < 3; k++) 
		{
			if (s[i] == br1[k])
			{ 
				S = Push(S, s[i]); 
				break;
			}
			if (s[i] == br2[k])
			{ 
				S = Pop(S);
				upper = S.data[S.size];
				if (upper != br1[k]) OK = 0;
				break;
			}
		}
	if (OK && (S.size == 0))
		printf("\n��p������ �p��������\n");
	else
		printf("\n��p������ ���p�������� \n");
}*/

// ������ 4
/*#include<stdio.h>
#include<stdlib.h>
struct Node {
	char data;
	struct Node *next, *prev;
};
typedef struct Node *PNode;

typedef struct {
	PNode Head, Tail;
}Stack;

Stack Push(Stack S, char x)
{
	struct Node a = {x,S.Head,NULL};
	PNode NewNode = &a;
	if (S.Head)
		S.Head->prev = NewNode;
	S.Head = NewNode;
	if (!S.Tail)
		S.Tail = S.Head;

	return S;
}
Stack Pop(Stack S)
{
	PNode TopNode = S.Head;
	char x;
	if (!TopNode)
		return  S;
	x = TopNode->data;
	S.Head = TopNode->next;
	if (S.Head) S.Head->prev = NULL; // ����������� ������ 
	else S.Tail = NULL;
	free(TopNode); // ���������� ������ 
	return S;
}*/

// ������ 5
/*#include<stdio.h>
#include<locale.h>
const int MAXSIZE = 100;
typedef struct{
	int data[100];
	int size, head, tail;
}Queue;

void PushTail(Queue *Q, int x)
{
	if (Q->size == MAXSIZE) {
		printf("������� �����������\n");
		return;
	}
	Q->tail++;
	if (Q->tail >= MAXSIZE) // ��������� � ������ 
		Q->tail = 0;
	Q->data[Q->tail] = x;
	Q->size++;
}

int Pop(Queue *Q)
{
	int temp;
	if (Q->size == 0)
	{
		printf("������� �����\n");
		return 32767; // ������ �� ������
	}
	temp = Q->data[Q->head];
	Q->head++;
	if (Q->head >= MAXSIZE) Q->head = 0;
	Q->size--;
	return temp;
}

int main()
{
	setlocale(LC_ALL, "RUS");
}*/

// ������ 6
/*#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int data;
	Node *next, *prev;
}Node;
typedef Node *PNode;

typedef struct {
	PNode head, tail;
} Queue;

void PushTail(Queue *Q, int x)
{
	Node node = { x, NULL, Q->tail };
	PNode NewNode = &node;
	if (Q->tail)  
		Q->tail->next = NewNode;
	Q->tail = NewNode;
	if (!Q->head) Q->head = Q->tail;
}*/

// ��������������� �������

// ���������� ���� � ������� �������
/*#include<stdio.h>
#include<locale.h>
// ������� ������

const int MAXSIZE = 100;
typedef struct{
	int data[100];
	int size;
}Deque;
void PushFront(Deque *deck, char newData)
{
	if (deck->size == MAXSIZE)
	{
		printf("\n���� �����������\n");
	}
	else
	{
		for (int i = deck->size; i > 1; i--)
		{
			deck->data[i + 1] = deck->data[i];
		}
		deck->data[0] = newData;
		deck->size++;
	}
}
void PushBack(Deque *deck, char newData)
{
	if (deck->size == MAXSIZE)
	{
		printf("\n���� �����������\n");
	}
	else
	{
		deck->data[deck->size] = newData;
		deck->size++;
	}
}
void PopFront(Deque *deck)
{
	if (deck->size == 0)
	{
		printf("\n���� �����\n");
	}
	else
	{
		for (int i = 0; i<deck->size; i++)
		{
			deck->data[i] = deck->data[i 
+ 1];
		}
		deck->size--;
	}
}
void PopBack(Deque *deck)
{
	if (deck->size == 0)
	{
		printf("\n���� �����\n");
	}
	else
	{
		deck->size--;
	}
}


void PrintDeque(Deque *deck)
{
	printf("� ������ ������ � ���� ��������� %d ��.\n������ ���������: \n", deck->size);
	for (int i = 0; i < deck->size; i++)
	{
		printf("%d, ", deck->data[i]);
	}
	printf("\n");
}
void main()
{
	setlocale(LC_ALL, "RUS");
	int fncNum=123;
	int addSym=0;
	Deque dataDeck = { {9,8,7,6}, 4};
	printf("������� ������������ ���� �� ������ �������\n____________________________________________\n");
	do
	{
		PrintDeque(&dataDeck);
		printf("��������� �������:\n1.�������� ����� � ������ ����\n2.�������� ����� � �����\n3.������� ����� �� ������ ����\n4.������� ����� �� �����\n____________\n0.����� �� ������� ������������\n");
		printf("������� ����� �������� �������: ");
		scanf_s("%d", &fncNum);
		switch (fncNum)
		{
		case 1:
			printf("������� �����, ��� �� ������ �� �������� � ������ ����: ");
			scanf_s("%d", &addSym);
			PushFront(&dataDeck, addSym);
			printf("\n���������\n");
			break;
		case 2:
			printf("������� �����, ��� �� ������ �� �������� � ����� ����: ");
			scanf_s("%d", &addSym);
			PushBack(&dataDeck, addSym);
			printf("\n���������\n");
			break;
		case 3:
			printf("�������� ������� �����: ");
			PopFront(&dataDeck);
			printf("\n���������\n");
			break;
		case 4:
			printf("�������� ���������� �����: ");
			PopBack(&dataDeck);
			printf("\n���������\n");
			break;
		case 0:
			printf("���������� ������...\n");
			break;
		default:
			printf("����� ������� ���, ���������� ������� ����� �� ������\n");
			break;
		}
	} while (fncNum != 0);
}*/

// ���������� ���� � ������� ����������� ������
/*#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
// ������� ������

struct Node{
	int data;
	struct Node *next, *prev;
};
typedef struct Node *PNode;
typedef struct{
	int length;
	PNode Head, Tail;
}Deque;


void PushFront(Deque *deck, int newData)
{
	PNode newNode = malloc(sizeof(struct Node));
	newNode->data = newData;
	newNode->next = deck->Head;
	deck->Head->prev = newNode;
	deck->Head = newNode;
	deck->length++;
}
void PushBack(Deque *deck, int newData)
{
	PNode newNode = malloc(sizeof(struct Node));
	newNode->data = newData;
	newNode->prev = deck->Tail;
	deck->Tail->next = newNode;
	deck->Tail = newNode;
	deck->length++;
}
void PopFront(Deque *deck)
{
	if (deck->Head->next != NULL)
	{
		PNode del = deck->Head;
		deck->Head->next->prev = NULL;
		deck->Head = deck->Head->next;
		deck->length--;
		free(del);
	}
}
void PopBack(Deque *deck)
{
	if (deck->Head->next != NULL)
	{
		PNode del = deck->Tail;
		deck->Tail->prev->next = NULL;
		deck->Tail = deck->Tail->prev;
		deck->length--;
		free(del);
	}
}

void PrintDeque(Deque *deck)
{
	printf("� ������ ������ � ���� ��������� %d ��.\n������ ���������: \n", deck->length);
	PNode node = deck->Head;
		for(int i = 0; (i!=deck->length && node!=NULL); i++)
		{
			printf("%d, ", node->data);
			node = node->next;
		}
	printf("\n");
}


void main()
{
	setlocale(LC_ALL, "RUS");
	int fncNum = 123;
	int addSym = 0;
	struct Node node = {11, NULL, NULL};
	Deque dataDeck = {1, &node, &node};
	printf("������� ������������ ���� �� ������ ����������� ������\n____________________________________________\n");
	do
	{
		PrintDeque(&dataDeck);
		printf("��������� �������:\n1.�������� ����� � ������ ����\n2.�������� ����� � �����\n3.������� ����� �� ������ ����\n4.������� ����� �� �����\n____________\n0.����� �� ������� ������������\n");
		printf("������� ����� �������� �������: ");
		scanf_s("%d", &fncNum);
		switch (fncNum)
		{
		case 1:
			printf("������� �����, ��� �� ������ �� �������� � ������ ����: ");
			scanf_s("%d", &addSym);
			PushFront(&dataDeck, addSym);
			printf("\n���������\n");
			break;
		case 2:
			printf("������� �����, ��� �� ������ �� �������� � ����� ����: ");
			scanf_s("%d", &addSym);
			PushBack(&dataDeck, addSym);
			printf("\n���������\n");
			break;
		case 3:
			printf("�������� ������� �����: ");
			PopFront(&dataDeck);
			printf("\n���������\n");
			break;
		case 4:
			printf("�������� ���������� �����: ");
			PopBack(&dataDeck);
			printf("\n���������\n");
			break;
		case 0:
			printf("���������� ������...\n");
			break;
		default:
			printf("����� ������� ���, ���������� ������� ����� �� ������\n");
			break;
		}
	}while (fncNum != 0);
}*/
