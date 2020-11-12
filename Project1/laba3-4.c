#include <stdio.h>
#include<float.h>
#include<math.h>
#define N 100
float f(float x)
{
	float otv = (x*x) / (10 + x * x*x);
	return otv;
}
float Integral1(float a, float b)
{
	float h = (b - a) / N;
	float I1 = (f(a)/2) + (f(b)/2);
	for (int i = 2; i < N; i++)
	{
		I1 += f(a + (N - i)*h);
	}
	I1 *= h;	
	return I1;
}

void main()
{
	int x = -12345;
	printf("%d\n", x);
	while (x != 0)
	{
		printf("%d %d\n", x / 10, abs(x % 10));
		x /= 10;
	}

	//float a1 = -2.0f;
	//float b1 = 5.0f;
	//printf("\nintegral: %f\n", Integral1(a1,b1));
}

