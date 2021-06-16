/**
* @file laba3_1.cpp
* @author Корпань В.М. 515-и
* @date 21 марта 2021
* @brief Лабораторная работа №3
*
* Массивы. Задание 2
*/

// подключение заголовочных файлов стандартных и математических библиотек языка C
#include <stdio.h>
#include<locale.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int sum_even_elements(int vector[], int number)
{
	int sum = 0, i;
	for (i = number - 1; i >= 0; i--) {
		if (vector[i] % 2 == 1 || vector[i] % 2 == -1)
			break;
	}
	for (i = i + 1; i < number; i++)
		sum += fabs(vector[i]);
	return sum;
}

int main()
{
	// смена кодовой таблицы символов - включение русского языка
	setlocale(LC_CTYPE, "rus");
	int vector[100], number, how_input;
	printf("Введите количество элементов массива: ");
	scanf_s("%d", &number);
	printf("Ввести массив с клавиатуры - 1\nЗаполнить массив случайно - 2\n");
	scanf_s("%d", &how_input);
	if (how_input == 1) {
		printf("Ваш массив: ");
		for (int i = 0; i < number; i++)
			scanf_s("%d", &vector[i]);
	}
	else if(how_input == 2){
		srand(time(0));
		for (int i = 0; i < number; i++)
			vector[i] = rand() % 1000 - 500;
		printf("Случайный массив: ");
		for (int i = 0; i < number; i++)
			printf("%d ", vector[i]);
		printf("\n");
	}
	else
	{
		printf("ошибка ввода");
		exit(0);
	}
	printf("Сумма = %d", sum_even_elements(vector, number));
}