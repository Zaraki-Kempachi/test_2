#include <stdio.h>
#include <stdlib.h>
#include < time.h> 
#define MAX 100 

/**
* Ввод массива с клавиатуры
* @param arr передаваемый массив
* @param n количество елементов массива
*/
void input_arr_from_keyboard(int*, int);
/**
* Случайное заполнение массива
* @param arr передаваемый массив
* @param n количество елементов массива
*/
void random_arr(int*, int);
/**
* Расчет суммы всех елементов, сумы четных и суммы нечетных елементов массива
* @param arr передаваемый массив
* @param num количество елементов массива
*/
void summa_elem(int*, int, int*, int*, int*);
int clean_stdin() {
	while (getchar() != '\n');
	return 1;
}

int main()
{
	int arr[MAX], n, o, s_odd_elem, s_even_elem, s_all_elem;
	char c;
	do {
		printf("vvedite kol-vo elementov masiva: ");
	} while
		(((scanf_s("%d%c", &n, &c) != 2 || c != '\n') && clean_stdin()));
	printf("1 - vvesti massiv s klaviaturi\n2 - zapolnit' massiv sluchayno\n");
	scanf_s("%d", &o);
	switch (o)
	{
	case 1:input_arr_from_keyboard(arr, n); break;
	case 2:random_arr(arr, n); break;
	default:printf("oshibka vvoda"); exit(0); break;
	}
	putchar('\n');
	summa_elem(arr, n, &s_odd_elem, &s_even_elem, &s_all_elem);
	printf("summa vsih elementiv: %d\n", s_all_elem);
	printf("summa neparnih elementiv: %d\n", s_odd_elem);
	printf("summa parnih elementiv: %d\n", s_even_elem);
}

void input_arr_from_keyboard(int *arr, int n)
{
	int*p;
	printf("vash massiv: ");
	for (p=arr; p < arr + n; p++)
		scanf_s("%d", p);
}

void random_arr(int *arr, int n)
{
	int*p;
	srand(time(NULL));
	for (p = arr; p < arr + n; p++)
		*p = rand() % 201 - 100;
	printf("vash massiv: ");
	for (p = arr; p < arr + n; p++)
		printf("%d ", *p);
}

void summa_elem(int *arr, int n, int*s_odd, int*s_even, int* s_all) 
{
	int * p;
	*s_all = *s_even = *s_odd = 0;
	for (p = arr; p < arr + n; p++)
		*s_all += *p;
	for (p = arr; p < arr + n; p++) 
	{
		if(*p % 2 == 1 || *p%2==-1)
			*s_odd += *p;
	}
	for (p = arr; p < arr + n; p++)
	{
		if (*p % 2 == 0)
			*s_even += *p;
	}
}