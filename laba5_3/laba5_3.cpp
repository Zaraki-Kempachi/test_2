#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

/**
* Ввод массива с клавиатуры
* @param matr передаваемый двухмерный массив
* @param num количество рядков и столбцов массива
*/
void input_from_keyboard(int*, int);
/**
* Случайное заполнение массива
* @param matr передаваемый двухмерный массив
* @param num количество рядков и столбцов массива
*/
void random_matrix(int*, int);
/**
* Проверка является ли матрица нулевой
*
* @param matr передаваемый двухмерный массив
* @param num количество рядков и столбцов массива
* return 0, если не нулевая, 1 - нулевая
*/
int is_zero(int*, int);
/**
* Вывод массива
* @param matr передаваемый двухмерный массив
* @param num количество рядков и столбцов массива
*/
void print_matr(int*, int);

int clean_stdin() {
	while (getchar() != '\n');
	return 1;
}

int main()
{
	int matr[MAX][MAX], NUM, o;
	char c;
	do {
	printf("vvedite kol-vo ryadkov i stolbzow matrici: ");
	} while
		(((scanf_s("%d%c", &NUM, &c) != 2 || c != '\n') && clean_stdin()));
	printf("1 - vvesti elementi matrici [%d][%d] s klaviaturi\n"
		"2 - zapolnit matricu [%d][%d] sluchaynimi chislami\n",NUM, NUM, NUM, NUM);
	scanf_s("%d", &o);
	switch (o)
	{
	case 1: input_from_keyboard(&matr[NUM][NUM], NUM); break;
	case 2: random_matrix(&matr[NUM][NUM], NUM); break;
	default: printf("oshibka vvoda"); exit(0); break;
	}
	if (is_zero(&matr[NUM][NUM], NUM))
		printf("matrica nulevaya\n");
	else
		printf("matrica ne nulevaya\n");
	printf("vasha matrica:\n");
	print_matr(&matr[NUM][NUM], NUM);
}

void input_from_keyboard(int *matr, int NUM) {
	int *p;
	for (p = matr; p < matr + NUM * NUM; p++)
			scanf_s("%d", p);
}

void random_matrix(int *matr, int NUM) {
	int *p;
	srand(time(NULL));
	for (p = matr; p < matr + NUM * NUM; p++)
		*p = rand() % 201 - 100;
}

int is_zero(int *matr, int NUM)
{
	int *p;
	for (p = matr; p < matr + NUM * NUM ; p++)
		if (*p != 0)
			return 0;
	return 1;
}

void print_matr(int *matr, int NUM)
{
	int *p;
	for (int i = 0; i < NUM; i++) {
		for (p = &matr[i]; p < &matr[i] + NUM; p++) {
			printf("%5d", *p);
		}
		putchar('\n');
	}
}