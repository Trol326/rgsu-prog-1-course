#include<math.h>
#include<stdio.h>
#include<float.h>

//Вариант 2
/*
int main(void)
{
	float x, y, rez;
	printf_s("X = ");
	scanf_s("%f", &x);
	printf_s("Y = ");
	scanf_s("%f", &y);
	if (y != 1.0f/18.0f)
	{
	
	rez = exp(x) - ((pow(y, 2) + 12 * x*y - 3 * pow(x, 2)) / (18 * y - 1));
	printf("result is %f \n", rez);
	}
	else
	{
		printf("there's no result(divided by 0) \n");
	}
	return 0;
}
*/

void XFinder() // #1 
{
	printf("ax^2+bx+c=0 calcer \n");
	float a, b, c, d, x1, x2;
	printf("a = ");
	scanf_s("%f", &a);
	printf("b = ");
	scanf_s("%f", &b);
	printf("c = ");
	scanf_s("%f", &c);
	if (a == 0)
	{
		if (b == 0 && c == 0)
		{
			printf("x - any number \n");
		}
		else if (b == 0 && c != 0)
		{
			printf("There's no X \n");
		}
		else
		{
			x1 = -1 * c / b;
			printf("Amount of x - 1. \nX = %f \n", x1);
		}
	}
	else
	{
		d = b * b - 4 * a*c;
		if (d == 0)
		{
			x1 = -b / (2 * a);
			printf("Amount of x - 1. \nX = %f \n", x1);
		}
		else if (d < 0)
		{
			x2 = sqrt(-d) / (2 * a);
			x1 = (-b / 2 * a);
			printf("Amount of x - 2. X is complex. \nX1 = %f + i*%f \nX2 = %f - i*%f \n", x1, x2, x1, x2);
		}
		else
		{
			x1 = (-b - sqrt(d)) / (2 * a);
			x2 = (-b + sqrt(d)) / (2 * a);
			printf("Amount of x - 2. \nX1 = %f \nX2 = %f \n", x1, x2);
		}
	}
}

void ExpFunction() // #2
{
	float x, y, rez;
	printf_s("X = ");
	scanf_s("%f", &x);
	printf_s("Y = ");
	scanf_s("%f", &y);
	if (y != 1.0f / 18.0f)
	{

		rez = exp(x) - ((pow(y, 2) + 12 * x*y - 3 * pow(x, 2)) / (18 * y - 1));
		printf("result is %f \n", rez);
	}
	else
	{
		printf("there's no result(divided by 0) \n");
	}
}

void Cube() // #3
{
	float a, Sf, Stf, V;
	printf_s("a = ");
	scanf_s("%f", &a);
	if (a > 0)
	{
		Sf = a * a;
		printf_s("Cube face area %f\n", Sf);
		Stf = 6 * a*a;
		printf_s("Total surface area of cube %f\n", Stf);
		V = a * a*a;
		printf_s("Cube volume %f\n", V);
	}
	else
	{
		printf("a can't be a negative\n");
	}
}

void Oblast() // #4
{
	float x, y;
	printf("x = ");
	scanf_s("%f", &x);
	printf("y = ");
	scanf_s("%f", &y);
	if (((x >= 1) && (x <= 7) && (y <= 8) && (y >= 6)) || ((x >= 3) && (x <= 5) && (y >= 2) && (y <= 6)))
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}
}

void ChessHorse() // #5
{
	int a1, b1, a2, b2;
	printf("a1 = ");
	scanf_s("%d", &a1);
	printf("b1 = ");
	scanf_s("%d", &b1);
	printf("a2 = ");
	scanf_s("%d", &a2);
	printf("b2 = ");
	scanf_s("%d", &b2);
	if ((a1 <= 8) && (a2 <= 8) && (b1 <= 8) && (b2 <= 8) && (a1 > 0) && (a2 > 0) && (b1 > 0) && (b2 > 0))
	{
		if (((a1 + 2 == a2 || a1 - 2 == a2) && (b1 + 1 == b2 || b1 - 1 == b2)) || ((b1 + 2 == b2 || b1 - 2 == b2) && (a1 + 1 == a2 || a1 - 1 == a2)))
		{
			printf("True\n");
		}
		else
		{
			printf("False\n");
		}
	}
	else
	{
		printf("Out of range\n");
	}
}