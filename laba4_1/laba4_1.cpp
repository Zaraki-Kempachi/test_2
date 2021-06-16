#include <stdio.h>
#include <stdlib.h>
#include < time.h> 
#include <math.h>
#define MAX 100 

/**
 *Ввод массива с клавиатуры
 *
 *@param arr[] - массив, n - число елементов массива
 *@return
 */
void input_arr_from_keyboard(int[], int);

/**
 *Заполнение массива случайными числами
 *
 *@param arr[] - массив, n - число елементов массива
 *@return
 */
void random_arr(int[], int);

int clean_stdin() {
	while (getchar() != '\n');
	return 1;
}

/**
 *функция, которая находит опорный елемент и после нахождения вызывает саму себя
 *
 *@param arr[] - массив, low - первый елемент массива, high - последний елемент массива
 *@return
 */
void quicksort(int arr[], int low, int high);

int rozdelenie(int arr[], int low, int hidh);

/**
 *Вывод отсортированного массива 
 *
 *@param arr[] - массив, n - число елементов массива
 *@return
 */
void output_sort_arr(int arr[], int);


int main() {
	int arr[MAX], n, o;
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
	quicksort(arr, 0, n-1);
	putchar('\n');
	output_sort_arr(arr, n);
}

void input_arr_from_keyboard(int arr[], int n)
{
	printf("vash massiv: ");
	for (int i = 0; i < n; i++)
		scanf_s("%d", &arr[i]);
}

void random_arr(int arr[], int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 201 - 100;
	printf("vash massiv: ");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	putchar('\n');
}

void quicksort(int arr[], int low, int high)
{
	int middle;
	if (low >= high) return;
	middle = rozdelenie(arr, low, high);
	quicksort(arr, low, middle - 1);
	quicksort(arr, middle + 1, high);
}

int rozdelenie(int arr[], int low, int high)
{
	int part_element = arr[low];
	for (;;)
	{
		while (low < high && part_element <= arr[high])
			high--;
		if (low >= high) break;
		arr[low++] = arr[high];
		while (low < high && arr[low] <= part_element)
			low++;
		if (low >= high) break;
		arr[high--] = arr[low];
	}
	arr[high] = part_element;
	return high;
}

void output_sort_arr(int arr[], int n) {
	printf("otsortirovaniy massiv: ");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return;
}