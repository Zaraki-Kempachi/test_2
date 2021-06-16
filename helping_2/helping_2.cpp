#include<stdio.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES
#include<math.h>
double add_sub_mult(double number, char sign) {
	int o;
	double x_1, x_2, x;
	if (number != 0) {
		printf("input 1 to work with received number\ninput 2 to work with new numbers\n");
		scanf_s("%d", &o);
		switch (o) {
		case 1: printf("input second number:");
			scanf_s("%lf", &x_1);
			switch (sign) {
			case '+': x = number + x_1; break;
			case '-': x = number - x_1; break;
			case '*': x = number * x_1; break;
			}
			printf("%g%c%g=%g\n", number, sign, x_1, x);
			break;
		case 2: printf("input 2 new numbers:");
			scanf_s("%lf %lf", &x_1, &x_2);
			switch (sign) {
			case '+': x = x_1 + x_2; break;
			case '-': x = x_1 - x_2; break;
			case '*': x = x_1 * x_2; break;
			}
			printf("%g%c%g=%g\n", x_1, sign, x_2, x); break;
		}
	}
	else {
		printf("input 2 numbers:");
		scanf_s("%lf %lf", &x_1, &x_2);
		switch (sign) {
		case '+': x = x_1 + x_2; break;
		case '-': x = x_1 - x_2; break;
		case '*': x = x_1 * x_2; break;
		}
		printf("%g%c%g=%g\n", x_1, sign, x_2, x);
	}
	return x;
}
double divis(double number)
{
	int o;
	double x_1, x_2, x;
	if (number != 0) {
		printf("input 1 to work with received number\ninput 2 to work with new numbers\n");
		scanf_s("%d", &o);
		switch (o) {
		case 1: printf("vvedite novoe chislo:");
			scanf_s("%lf", &x_1);
			if (x_1 == 0) {
				printf("delenie na nol\n");
				x = number;
			}
			else {
				x = number / x_1;
				printf("%g/%g=%g\n", number, x_1, x);
			}
			break;
		case 2: printf("vvedite 2 novih chisla:");
			scanf_s("%lf %lf", &x_1, &x_2);
			if (x_2 == 0) {
				printf("delenie na nol\n");
				x = number;
			}
			else {
				x = x_1 / x_2;
				printf("%g/%g=%g\n", x_1, x_2, x_1 / x_2);
			} break;
		}
	}
	else {
		printf("vvedite 2 chisla:");
		scanf_s("%lf %lf", &x_1, &x_2);
		if (x_2 == 0) {
			printf("delenie na nol\n");
			x = number;
		}
		else {
			x = x_1 / x_2;
			printf("%g/%g=%g\n", x_1, x_2, x_1 / x_2);
		}
	}
	return x;
}
double arccos_x(double number) {
	int o;
	double x_1, x;
	if (number != 0) {
		printf("input 1 to work with received number\ninput 2 to work with new number\n");
		scanf_s("%d", &o);
		switch (o) {
		case 1:if (number > 1 || number < -1)
		{
			printf("can be calculate arccos only from a number -1 to 1\n");
			x = number;
		}
	    else
		{
			x = acos(number);
			printf("arccos(%g)=%g\n", number, x);
		}
			   break;
		case 2: printf("input new number:");
			scanf_s("%lf", &x_1);
			if (x_1 > 1 || x_1 < -1)
			{
				printf("can be calculate arccos only from a number -1 to 1\n");
				x = number;
			}
			else {
				x = acos(x_1);
				printf("arccos(%g)=%g\n", x_1, x);
				break;
			}
		}
	}
	else {
		printf("input number:");
		scanf_s("%lf", &x_1);
		if (x_1 > 1 || x_1 < -1)
		{
			printf("can be calculate arccos only from a number -1 to 1\n");
			x = number;
		}
		else {
			x = acos(x_1);
			printf("arccos(%g)=%g\n", x_1, x);
		}
	}
	return x;
}
double x_in_pow(double number) {
	int o;
	double x_1, x;
	if (number != 0) {
		printf("input 1 to work with received number\ninput 2 to work with new number\n");
		scanf_s("%d", &o);
		switch (o) {
		case 1:x = pow(number,1.0/3);
		printf("%g^1/3=%g\n", number, x);
		break;
		case 2: printf("input new number:");
			scanf_s("%lf", &x_1);
	        x = pow(x_1,1.0/3);
			printf("%g^1/3=%g\n", x_1, x);
			break;
		}
	}
	else {
		printf("input new number:");
		scanf_s("%lf", &x_1);
		x = pow(x_1,(1.0/3));
		printf("%g^1/3=%g\n", x_1, x);
	}
	return x;
}
double div_two_x(double number) {
	int o;
	double x_1, x;
	if (number != 0) {
		printf("input 1 to work with received number\ninput 2 to work with new number\n");
		scanf_s("%d", &o);
		switch (o) {
		case 1:if (number ==0)
		{
			printf("division by zero\n");
			x = number;
		}
			   else
		{
			x = 2/ number;
			printf("2/%g=%g\n", number, x);
		}
			   break;
		case 2: printf("input new number:");
			scanf_s("%lf", &x_1);
			if (x_1 == 0)
			{
				printf("division by zero\n");
				x = number;
			}
			else {
				x = 2/x_1;
				printf("2/%g=%g\n", x_1, x);
				break;
			}
		}
	}
	else {
		printf("input new number:");
		scanf_s("%lf", &x_1);
		if (x_1 == 0)
		{
			printf("division by zero\n");
			x = number;
		}
		else {
			x = 2 / x_1;
			printf("2/%g=%g\n", x_1, x);
		}
	}
	return x;
}

int main()
{
	double number = 0;
	for (;;)
	{
		printf("choose operation:\n1)Discharge\n2)Addition\n3)Subtraction\n4)Multiplication\n5)Division\n6)Arccos(x)\n7)x^(1/3)\n8)2/x\n9)Exit\n");
		int operation;
		scanf_s("%d", &operation);
		switch (operation) {
		case 1:number = 0; break;
		case 2:number = add_sub_mult(number, '+'); break;
		case 3:number = add_sub_mult(number, '-'); break;
		case 4:number = add_sub_mult(number, '*'); break;
		case 5:number = divis(number); break;
		case 6:number = arccos_x(number); break;
		case 7:number = x_in_pow(number); break;
		case 8:number = div_two_x(number); break;
		case 9:exit(0); break;
		default:printf("Input error\n");
		}
		printf("\n");
	}
}
