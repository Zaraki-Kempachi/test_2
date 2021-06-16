#include<stdio.h>
#include<math.h>

double factorial(double);
double function(double);
double summa(double, double);

int main()
{
	double h, x, n, a, b;
	printf("vvedite nachalo diapazona:");
	scanf_s("%2lf", &a);
	printf("vvedite konec diapazona:");
	scanf_s("%2lf", &b);
	printf("vvedite shag izmeneniya:");
	scanf_s("%lf", &h);
	printf("vvedite kolichastvo slagaemih summi(n):");
	scanf_s("%lf", &n);
	printf("+--------+--------+---------+\n");
	printf("|  Y(x)  |  S(x)  |Y(x)-S(x)|\n");
	for (x = a; x <= b; x+=h)
	{
		printf("+--------+--------+---------+\n");
		printf("| %.4f | %.4f |  %.4f | \n",function(x),summa(x, n), fabs(function(x)-summa(x,n)));
	}
	printf("+--------+--------+---------+\n");
	return 0;
}


double factorial(double x)
{
	if (x == 0)
		x = 1;
	else
	{
		for (double n = x - 1; n > 0; n--)
		{
			x *= n;
		}
	}
	return x;
}
double function(double x)
{
	double y;
	y=exp(4*x);
	return y;
}
double summa(double x, double n)
{
	double s=0;
	for (int k = 0; k <= n; k++)
	{
		s += (pow((4 * x),k)/factorial(k));
	}
	return s;
}