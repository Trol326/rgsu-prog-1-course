//#include<math.h>
//#include<locale.h>
//#include <conio.h>
//#include <string.h>
//#include <stdbool.h>
//
//void Zadanie1_1()
//{
//	int min, minInx;
//	int *nums[4];
//	for (int i = 0; i < 4; i++)
//	{
//		printf("\n������� %d� �����: ", i + 1);
//		scanf_s("%d", &nums[i]);
//	}
//	min = nums[0];
//	for (int i = 1; i < 4; i++)
//	{
//		if (nums[i] < min)
//		{
//			min = nums[i];
//			minInx = i;
//		}
//	}
//
//	printf("\n����������� ����� - %d, ��� �������� ��� ���������� ������� %d(%d� �������� �����)\n", min, minInx, minInx + 1);
//}
//
//void Zadanie1_2() {
//	int N, curs;
//	char *sem;
//	printf("������� ��������� �� ��� ����������(������� ���������)?\n");
//	scanf_s("%d", &N);
//	if (N < 0 || N>10)
//	{
//		printf("%d ��������� �� ������", N);
//	}
//	else
//	{
//		if (N == 1)
//		{
//			sem = "�������";
//		}
//		else if (N >= 2 && N <= 4)
//		{
//			sem = "��������";
//		}
//		else
//		{
//			sem = "���������";
//		}
//		curs = ceil(N / 2);
//		printf("� ��������� %d %s. � �� %d �����\n", N, sem, curs + 1);
//	}
//}
//
//void Zadanie1_2() 
//{
//	char s[81];
//	printf("������� ������: ");
//	gets(s);
//	bool isNumber = false;
//	bool zeroLine = false;
//	int i = 0;
//	while (s[i] != 46)
//	{
//		if (s[i] == '?')
//		{
//			s[i] = '!';
//		}
//		if (s[i] == '-')
//		{
//			memmove(&s[i], &s[i + 1], strlen(s) - i);
//			i--;
//		}
//		if (s[i] == '&')
//		{
//			memmove(&s[i + 1], &s[i], strlen(s) + 1);
//			i++;
//		}
//		if ((s[i] >= 'A') && (s[i] <= 'Z'))
//		{
//			s[i] += 32;
//		}
//
//		if (s[i] == '0' && !isNumber)
//		{
//			memmove(&s[i], &s[i + 1], strlen(s) - i);
//			i--;
//		}
//		if (s[i] > '0'&& s[i] <= '9')
//		{
//			isNumber = true;
//		}
//		else if (s[i] != '0')
//		{
//			isNumber = false;
//		}
//
//		if ((s[i] == 't' || s[i] == 'T') && (s[i + 1] == 'h' || s[i + 1] == 'H') && (s[i + 2] == 'e' || s[i + 2] == 'E'))
//		{
//			memmove(&s[i], &s[i + 1], strlen(s) - i);
//			memmove(&s[i], &s[i + 1], strlen(s) - i);
//			memmove(&s[i], &s[i + 1], strlen(s) - i);
//			i--;
//		}
//
//		i++;
//	}
//	printf("%s\n", s);
//	_getch();
//}

/*
void main()
{
	setlocale(LC_ALL, "Rus");

}
*/
