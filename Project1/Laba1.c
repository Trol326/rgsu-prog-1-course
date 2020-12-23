//#include <stdlib.h>
//#include <locale.h>
//#include <windows.h>
//#include <conio.h>
//#include <stdio.h>
//#include <string.h>
//void gotoxy(int x, int y)
//{
//	HANDLE OutputHandle;
//	CONSOLE_SCREEN_BUFFER_INFO ScreenBufInfo;
//	OutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
//	GetConsoleScreenBufferInfo(OutputHandle, &ScreenBufInfo);
//	ScreenBufInfo.dwCursorPosition.X = x;
//	ScreenBufInfo.dwCursorPosition.Y = y;
//	SetConsoleCursorPosition(OutputHandle, ScreenBufInfo.dwCursorPosition);
//}
//
//void Zadanie1_1()
//{
//	int i, s, a[20];
//	printf("Введите 20 чисел, по одному в строке\n");
//	for (s = 0, i = 0; i < 20; i++)
//	{
//		scanf_s("%d", &a[i]);
//		s += a[i];
//	}
//	for (i = 0; i < 20; i++)
//		printf("%2d:%7d ", i + 1, a[i]);
//	_getch();
//	printf("\n");
//	for (i = 0; i < 20; i++)
//		printf("%6d\n", a[i]);
//	printf("------\n%6d", s);
//	_getch();
//}
//
//void Zadanie1_2()
//{
//	long N;
//	char a[33];
//	printf("Введите положительное число : ");
//	scanf_s("%ld", &N);
//	if (N == 0)
//	{
//		printf("\nТакое число в любой системе = 0");
//		exit(1);
//	}
//	_ltoa_s(N, a, 33, 2);
//	printf("\nВ двоичном представлении %ld = %s", N, a);
//	_ltoa_s(N, a, 33, 8);
//	printf("\nВ восьмеричном представлении %ld = %s", N, a);
//	_ltoa_s(N, a, 33, 16);
//	printf("\nВ шестнадцатеричном представлении %ld = %s", N, a);
//	_getch();
//}
//
//void Zadanie1_3()
//{
//	long M;
//	int k;
//	printf("\nВведите целое число: ");
//	scanf_s("%ld", &M);
//	for (k = 0; k < 10; k++)
//		printf("\nВ позиции %d находится %d", k, digit_in_pos(M, k));
//	_getch();
//}
//
//int digit_in_pos(long N, int j)
//{
//	int Result, k;
//	for (k = 0; k <= j; k++)
//	{
//		Result = N % 10;
//		N = N / 10;
//	}
//	return Result;
//}
//int rasst(long n1, long n2);
//char s[40];
//void Zadanie1_4()
//{
//	long M1, M2;
//	printf("\nВведите два целых числа : ");
//	scanf_s("%ld %ld", &M1, &M2);
//	_ltoa_s(M1, s, 40, 2);
//	printf("\nM1 =%32s", s);
//	_ltoa_s(M2, s, 40, 2);
//	printf("\nM2 =%32s", s);
//	_ltoa_s(M1^M2, s, 40, 2);
//	printf("\nXOR=%32s", s);
//	printf("\nРасстояние между этим кодами = %5d", rasst(M1, M2));
//	_getch();
//}
//int rasst(long n1, long n2)
//{
//	int Result = 0, k;
//	long j = 0x00000001;
//	for (k = 0; k < 32; k++)
//	{
//		if ((j & n1) != (j & n2)) Result++;
//		j = j << 1;
//	}
//	return Result;
//}
//
//long invert(long N);
//void Zadanie1_5()
//{
//	long M;
//	printf("\nВведите целое число : ");
//	scanf_s("%ld", &M);
//	printf("\nСправа налево оно выглядит так  %ld", invert(M));
//	_getch();
//}
//long invert(long N)
//{
//	long Result = 0, sign = 1;
//	if (N < 0) { N = -N; sign = -1; }
//	while (N != 0)
//	{
//		Result = Result * 10 + (N % 10);
//		N = N / 10;
//	}
//	return Result * sign;
//}
//
//void Zadanie1_9(){
//long a;
//printf("Введите число: ");
//scanf_s("%ld", &a);
//printf("Сумма цифр числа %ld = %d \n", a, sum_dig(abs(a)));
//}
//
//int sum_dig(long n)
//{
//	int res = 0;
//	while (n != 0)
//	{
//		res += n % 10;
//		n = n / 10;
//	}
//	return res;
//}
//void Zadanie2_1()
//{
//	int i, j;
//	system("cls");
//	gotoxy(31, 1);
//	printf("Таблица ASCII\n");
//	for (i = 32; i <= 52; i++)
//	{
//		gotoxy(1, i - 29);
//		for (j = i; j <= 255; j += 21)
//			printf("%c %3d  ", j, j);
//	}
//	_getch();
//}
//
//char *up(char *a)
//{
//	unsigned char b[80];
//	int j;
//	strcpy_s(b, 80, a);
//	for (j = 0; j < strlen(a); j++)
//	{
//		if (97 <= b[j] && b[j] <= 122) b[j] -= 32;
//		if (160 <= b[j] && b[j] <= 175) b[j] -= 32;
//		if (224 <= b[j] && b[j] <= 239) b[j] -= 80;
//		if (241 == b[j]) b[j]--;
//	}
//	return b;
//}
//void Zadanie2_2()
//{
//	setlocale(LC_ALL, "Rus");
//	char a[80];
//	printf("\nВведите строку, содержащую малые и большие буквы ");
//	scanf_s("%s", a, 80);
//	char *d = up(a);
//	printf("\na=%s", a);
//	printf("\nb=%s\n", d);
//	_getch();
//}
//
//#define N 10
//void Zadanie2_3()
//{
//char names[N][20], tmp[20];
//	int i, j;
//	system("cls");
//	puts("Введите 10 фамилий по одной в строке");
//	for (i = 0; i < N; i++)
//		gets_s(&names[i][0], 15);
//	for (i = 0; i < N - 1; i++)
//		for (j = i + 1; j < N; j++)
//			if (strcmp(&names[i][0], &names[j][0]) > 0)
//			{
//				strcpy_s(tmp, 20, &names[i][0]);
//				strcpy_s(&names[i][0], 20, &names[j][0]);
//				strcpy_s(&names[j][0], 20, tmp);
//			}
//	puts("А теперь они же по алфавиту");
//	for (i = 0; i < N; i++)
//		puts(&names[i][0]);
//	_getch();
//}
//
//void Zadanie2_4()
//{
//char s[81], space = 1, words = 0, i, len;
//	puts("Введите строку");
//	gets(s);
//	len = strlen(s);
//	if (len == 0) goto ret;
//
//	if (s[0] != ' ')
//	{
//		space = 0;
//		words = 1;
//	}
//	for (i = 1; i < len; i++)
//	{
//		if (space == 1 && s[i] != ' ')
//		{
//			space = 0;
//			words++;
//		}
//		if (space == 0 && s[i] == ' ')space = 1;
//	}
//
//ret:
//	printf("\nЧисло слов в строке = %d \n", words);
//	_getch();
//}
//void Zadanie2_5()
//{
//unsigned char ch;
//	system("cls");
//
//getkey:
//	ch = _getch();
//
//	if (ch == 27) {
//		printf("\nНажат Esc. Завершение работы...\n");
//		exit(0);
//	}
//
//	if (ch == 13)
//	{
//		printf("\nНажата клавиша Enter с кодом = 13");
//		goto getkey;
//	}
//	if (ch == 0)
//	{
//		ch = _getch();
//		printf("\nНажата управляющая клавиша c кодом = %d", ch);
//	}
//	else printf("\nНажата обычная клавиша %c с кодом = %d", ch, ch);
//	goto getkey;
//}
//
//char *num_to_str(long m);
//void Zadanie2_6()
//{
//long n;
//
//	printf("Введите целое число : ");
//	scanf_s("%ld", &n);
//	printf("\n%ld = %s\n", n, num_to_str(n));
//	_getch();
//}
//char *num_to_str(long m)
//{
//	char *num1[] = { "нуль", "один", "два","три", "четыре", "пять", "шесть", "семь", "восемь", "девять", "десять", "одиннадцать", "двенадцать", "тринадцать", "четырнадцать", "пятнадцать", "шестнадцать", "семнадцать", "восемнадцать", "девятнадцать" };
//	char *num2[] = { "двадцать", "тридцать", "сорок", "пятьдесят", "шестьдесят", "семьдесят", "восемьдесят", "девяносто" };
//	char *num3[] = { "сто", "двести", "триста", "четыреста", "пятьсот", "шестьсот", "семьсот", "восемьсот", "девятьсот" };
//	static char Result[40] = "";
//	char dig1, dig10, dig100;
//	if (m < 0)
//	{
//		m = -m;
//		strcpy_s(Result, 40,"минус ");
//	}
//	if (m < 20)
//	{
//		strcat_s(Result, 40, num1[m]);
//		return Result;
//	}
//	dig1 = m % 10;
//	m = m / 10;
//	dig10 = m % 10;
//	dig100 = m / 10;
//	if (dig100 != 0)
//	{
//		strcat_s(Result, 40, num3[dig100 - 1]);
//		strcat_s(Result, 40, " ");
//	}
//	if (dig10 != 0)
//	{
//		strcat_s(Result, 40, num2[dig10 - 2]);
//		strcat_s(Result, 40, " ");
//	}
//	strcat_s(Result, 40, num1[dig1]);
//	return Result;
//}
//void Zadanie2_7()
//{
//char s[81], space = 1, i, len;
//	puts("Введите строку");
//	gets(s);
//	len = strlen(s);
//	if (len == 0) goto end;
//
//	if (s[0] != ' ')
//	{
//		space = 0;
//	}
//
//	for (i = 1; i < len; i++)
//	{
//		if (space == 1 && s[i] != ' ')
//		{
//			space = 0;
//		}
//		if (space == 1 && s[i] == ' ')
//		{
//			memmove(&s[i], &s[i + 1], strlen(s) - i);
//			i--;
//		}
//		if (space == 0 && s[i] == ' ')space = 1;
//	}
//
//end:
//	printf("%s\n", s);
//	_getch();
//}

/*
void main()
{
	setlocale(LC_ALL, "Rus");
	Zadanie2_2();
}*/
