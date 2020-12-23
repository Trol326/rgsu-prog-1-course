/*#include <stdio.h>
#include<float.h>
#include<math.h>
#include <locale.h>
#define N 100
*/
/*
void main()
{
	setlocale(LC_ALL, "Rus");
	printf("Вычисляем...");
	float dx, xi;
	float xn=1.0f;
	float xk=2.0f;
	float eps = 0.0001f;
	printf("xn = %f, xk = %f, f(xn) = %f, f(xk) = %f\n", xn, xk, f(xn), f(xk));
	while ((xk - xn) > eps)
	{
		dx = (xk - xn)/2;
		xi = xn + dx;
		printf("dx = %f, xi = %f, f(xn) = %f, f(xi) = %f\n", dx, xi, f(xn), f(xi));
		if (f(xn)*f(xi) < 0)
		{
			xk = xi;
		}
		else
		{
			xn = xi;
		}
	}
	printf("\nКорень уравнения - %f с точностью eps=%f\n", xi, eps);
}
*/
/*
void Laba3_1()
{
	int x = -12345;
	printf("%d\n", x);
	while (x != 0)
	{
		printf("%d %d\n", x / 10, abs(x % 10));
		x /= 10;
	}
}

float f(float x)
{
	float otv = (x*x) / (10 + x * x*x);
	return otv;
}
float Integral1(float a, float b)
{
	float h = (b - a) / N;
	float I1 = (f(a) / 2) + (f(b) / 2);
	for (int i = 2; i < N; i++)
	{
		I1 += f(a + (N - i)*h);
	}
	I1 *= h;
	return I1;
}
void Laba3_2()
{
	float a1 = -2.0f;
	float b1 = 5.0f;
	printf("\nintegral: %f\n", Integral1(a1, b1));
}

void PR3_1()
{
	int x = 0;
	int k = 0;
	printf("\nВведите число: ");
	scanf_s("%d", &x);
	while (x > 0)
	{
		k += x % 10;
		x /= 10;
	}
	printf("\nВведите число: %d\n", k);
}

void PR3_2()
{
	int number;
	char raspNumber[4];
	printf("Введите число\n");
	scanf_s("%d", &number);
	int i = 0;
	int num = number;
	while (num != 0)
	{
		raspNumber[3 - i] = (num % 10) + 48;
		i++;
		num = num / 10;
	}
	printf("\nЧисло: %d. Распакованное число: %0.4s\n", number, raspNumber);
}

float f2(float x)
{
	float result = cos(2 / x) - 2 * sin(1 / x) + 1 / x;
	return result;
}
float foundOtvet(float a, float b, float eps)
{
	float c;
	if (fabs(b - a) < eps)
		return (a + b) / 2;
	else
	{
		c = (a + b) / 2;
		if (f2(a)*f2(c) <= 0.)
			return foundOtvet(a, c, eps);
		else
			return foundOtvet(c, b, eps);
	}
}
void PR3_3()
{
	float xn = -1.0f;
	float xk = 2.0f;
	float eps = 0.0001f;
	printf("\nКорень уравнения - %f с точностью eps=%f\n", foundOtvet(xn, xk, eps), eps);
}

float calcFunc(float x, float eps)
{
	float res = 0.0f;
	float t = 0.0f;
	int i = 1;

	printf("\nИдёт расчёт, пожалуйста подождите...\n");
	while (abs(x - t) > eps)
	{
		t = res;
		res += pow(-1, i + 1)*sin(i*x) / i;
		i++;
	}
	return res;
}
void PR3_4()
{
	float x;
	float eps = 0.001f;
	printf("Введите X\n");
	scanf_s("%f", &x);
	printf("\nY = %f\n", calcFunc(x, eps));
}
*/
/*
void main()
{
	setlocale(LC_ALL, "Rus");

}
*/