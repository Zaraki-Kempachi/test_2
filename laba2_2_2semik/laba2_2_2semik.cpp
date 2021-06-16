#include<stdio.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES
#include<math.h>

double sbros(int k);
double slozhenie(double);
double vichitanie(double);
double umnozhenie(double);
double delenie(double);
double ctg_x(double);
double koren_iz_x(double);
double x_v_kube(double);
double koren_3_iz_x(double);
void stars();

int main()
{
	double k = 0;
	for (int i = 0; i >-1; i++)
	{
		int x;
		printf("viberite nuzhnoe deystvie:\n1 - Sbros\n2 - Slozhenie\n3 - Vichitanie\n4 - Umnozhenie\n5 - Delenie\n6 - Funktziya kotangensa\n7 - Koren kvadratniy\n8 - chislo v 3 stepeni\n9 - chislo v stepeni 1/3\n10 - vihod\n");
		scanf_s("%d", &x);
		switch (x) {
		case 1:k=sbros(k); break;
		case 2:k=slozhenie(k); break;
		case 3:k=vichitanie(k); break;
		case 4:k=umnozhenie(k); break;
		case 5:k=delenie(k); break;
		case 6:k=ctg_x(k); break;
		case 7:k=koren_iz_x(k); break;
		case 8:k=x_v_kube(k); break;
		case 9:k=koren_3_iz_x(k); break;
		case 10:exit(0); break;
		default:printf("oshibka vvoda\n");
		}
		stars();
	}

	printf("%f", cbrt(-8));
}

double sbros(int k) 
{
	k = 0;
	printf("znachenie sbrosheno");
	return k;
}
double slozhenie(double k)
{
	int f;
	double x1, x2,x;
	if (k != 0) {
		printf("vvedite 1, esli hotite slagat poluchennoe ranee chislo s novim\nvvedite 2, esli hotite slagat novie chisla\n");
		scanf_s("%d", &f);
		switch (f) {
		case 1: printf("vvedite novoe chislo:");
			scanf_s("%lf", &x1);
			x = k + x1;
			printf("%g+%g=%g\n",k,x1,k+x1);
			break;
		case 2: printf("vvedite 2 novih chisla:");
			scanf_s("%lf %lf", &x1, &x2);
			x = x1 + x2;
			printf("%g+%g=%g\n", x1, x2, x1 + x2); break;
		}
	}
	else {
		printf("vvedite 2 chisla:");
		scanf_s("%lf %lf", &x1, &x2);
		x = x1 + x2;
		printf("%g+%g=%g\n", x1, x2, x1 + x2);
	}
	return x;
}
double vichitanie(double k)
{
	int f;
	double x1, x2, x;
	if (k != 0) {
		printf("vvedite 1, esli hotite vichitat iz poluchennogo ranee chisla novoe\nvvedite 2, esli hotite vichitat iz novogo chisla drugoe novoe\n");
		scanf_s("%d", &f);
		switch (f) {
		case 1: printf("vvedite novoe chislo:");
			scanf_s("%lf", &x1);
			x = k - x1;
			printf("%g-%g=%g\n", k, x1, k - x1);
			break;
		case 2: printf("vvedite 2 novih chisla:");
			scanf_s("%lf %lf", &x1, &x2);
			x = x1 - x2;
			printf("%g-%g=%g\n", x1, x2, x1 - x2); break;
		}
	}
	else {
		printf("vvedite 2 chisla:");
		scanf_s("%lf %lf", &x1, &x2);
		x = x1 - x2;
		printf("%g-%g=%g\n", x1, x2, x1 - x2);
	}
	return x;
}
double umnozhenie(double k)
{
	int f;
	double x1, x2, x;
	if (k != 0) {
		printf("vvedite 1, esli hotite umnozhat poluchennoe ranee chislo na novoe\nvvedite 2, esli hotite umnozhat 2 novih chisla drug na druga\n");
		scanf_s("%d", &f);
		switch (f) {
		case 1: printf("vvedite novoe chislo:");
			scanf_s("%lf", &x1);
			x = k * x1;
			printf("%g*%g=%g\n", k, x1, k * x1);
			break;
		case 2: printf("vvedite 2 novih chisla:");
			scanf_s("%lf %lf", &x1, &x2);
			x = x1 * x2;
			printf("%g*%g=%g\n", x1, x2, x1 * x2); break;
		}
	}
	else {
		printf("vvedite 2 chisla:");
		scanf_s("%lf %lf", &x1, &x2);
		x = x1 * x2;
		printf("%g*%g=%g\n", x1, x2, x1 * x2);
	}
	return x;
}
double delenie(double k)
{
	int f;
	double x1, x2, x;
	if (k != 0) {
		printf("vvedite 1, esli hotite delit poluchennoe ranee chislo na novoe\nvvedite 2, esli hotite delit 2 novih chisla drug na druga\n");
		scanf_s("%d", &f);
		switch (f) {
		case 1: printf("vvedite novoe chislo:");
			scanf_s("%lf", &x1);
			if (x1 == 0) {
				printf("delenie na nol\n");
				x = k;
			}
			else {
				x = k / x1;
				printf("%g/%g=%g\n", k, x1, k / x1);
			}
			break;
		case 2: printf("vvedite 2 novih chisla:");
			scanf_s("%lf %lf", &x1, &x2);
			if (x2 == 0) {
				printf("delenie na nol\n");
				x = k;
			}
			else {
				x = x1 / x2;
				printf("%g/%g=%g\n", x1, x2, x1 / x2);
			} break;
		}
	}
	else {
		printf("vvedite 2 chisla:");
		scanf_s("%lf %lf", &x1, &x2);
		if (x2 == 0) {
			printf("delenie na nol\n");
			x = k;
		}
		else {
			x = x1 / x2;
			printf("%g/%g=%g\n", x1, x2, x1 / x2);
		}
	}
	return x;
}
double ctg_x(double k)
{
	int f;
	double x1, x, rad;
	if (k != 0) {
		printf("vvedite 1, esli hotite prinyat poluchennoe chislo kak gradusi i vichislit kotangens\nvvedite 2, esli hotite vvesti novoe chislo v gradusah i vichislit kotangens\n");
		scanf_s("%d", &f);
		switch (f) {
		case 1:
			rad = k * (M_PI / 180.0);
			x  = (1 / (tan(rad)));
			printf("ctg(%g)=%g\n", k, x);
			break;
		case 2: printf("vvedite novoe chislo:");
			scanf_s("%lf", &x1);
			rad = x1 * (M_PI / 180.0);
			x = (1 / (tan(rad)));
			printf("ctg(%g)=%g\n", x1, x);
			break;
		}
	}
	else {
		printf("vvedite znachenie v gradusah:");
		scanf_s("%lf", &x1);
		rad = x1 * (M_PI / 180.0);
		x = (1 / (tan(rad)));
		printf("ctg(%g)=%g\n", x1, x);
	}
	return x;
}
double koren_iz_x(double k) 
{
	int f;
	double x1, x;
	if (k != 0) {
		printf("vvedite 1, esli hotite nayti koren iz poluchenogo ranee chisla\nvvedite 2, esli nayti koren iz novogo chisla\n");
		scanf_s("%d", &f);
		switch (f) {
		case 1:if (k < 0)
		{
			printf("pod kornem mozhet bit chislo >= 0\n");
			x = k;
		}
	    else 
		{
			x = sqrt(k);
			printf("%g^0.5=%g\n", k, x);
		}
			break;
		case 2: printf("vvedite novoe chislo:");
			scanf_s("%lf", &x1);
			if (x1 < 0)
			{
				printf("pod kornem mozhet bit chislo >= 0\n");
				x = k;
			}
			else {
				x = sqrt(x1);
				printf("%g^0.5=%g\n", x1, x);
				break;
			}
		}
	}
	else {
		printf("vvedite chislo:");
		scanf_s("%lf", &x1);
		if (x1 < 0)
		{
			printf("pod kornem mozhet bit chislo >= 0\n");
			x = k;
		}
		else {
			x = sqrt(x1);
			printf("%g^0.5=%g\n", x1, x);
		}
	}
	return x;
}
double x_v_kube(double k) 
{
	int f;
	double x1, x;
	if (k != 0) {
		printf("vvedite 1, esli hotite vozvesti v kub poluchenoe ranee chislo\nvvedite 2, esli hotite vozvesti v kub novoe chislo\n");
		scanf_s("%d", &f);
		switch (f) {
		case 1:
			x = pow(k,3);
			printf("%g^3=%g\n", k, x);
			break;
		case 2: printf("vvedite novoe chislo:");
			scanf_s("%lf", &x1);
			x = pow(x1,3);
			printf("%g^3=%g\n", x1, x);
			break;
		}
	}
	else {
		printf("vvedite chislo:");
		scanf_s("%lf", &x1);
		x = pow(x1, 3);
		printf("%g^3=%g\n", x1, x);
	}
	return x;
}
double koren_3_iz_x(double k) {
	int f;
	double x1, x;
	if (k != 0) {
		printf("vvedite 1, esli hotite vichislit koren 3 stepeni iz poluchennogo ranee chisla\nvvedite 2,  esli hotite vichislit koren 3 stepeni iz novogo chisla\n");
		scanf_s("%d", &f);
		switch (f) {
		case 1:if (k < 0)
			x = -pow(fabs(k), 1.0/3);
			   else
			x = pow(k, 1.0/3.0);
			printf("%g^1/3=%g\n", k, x);
			break;
		case 2: printf("vvedite novoe chislo:");
			scanf_s("%lf", &x1);
			if (x1 < 0)
				x = -pow(fabs(x1), 1.0 / 3);
			else
			x = pow(x1, 1.0/3.0);
			printf("%g^1/3=%g\n", x1, x);
			break;
		}
	}
	else {
		printf("vvedite chislo:");
		scanf_s("%lf", &x1);
		if (x1 < 0)
			x = -pow(fabs(x1), 1.0 / 3);
		else
		x = pow(x1, 1.0/3.0);
		printf("%g^1/3=%g\n", x1, x);
	}
	return x;
}
void stars() {
	for (int i = 0; i < 30; i++)
		putchar('*');
	putchar('\n');
}