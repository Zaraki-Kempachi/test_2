#include <stdio.h>
#include <stdlib.h>
#include < time.h> 
#include <math.h>
#define MAX 100 

void input_arr_from_keyboard(int[], int);
void random_arr(int[], int);
int summa_elem(int[], int);
int clean_stdin() {
	while (getchar() != '\n');
	return 1;
}


int main()
{
	int arr[MAX], n, o, s;
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
		s = summa_elem(arr, n);
		printf("summa = %d", s);
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
}

int summa_elem(int arr[], int n) 
{
	int s = 0, i, k=-1;
	for (i = 0; i < n; i++) {
		if (arr[i] < 0)
			k = i;
	}
	if (k == -1)
		s = 0;
	else {
		for (i = k + 1; i < n; i++)
			if (i % 2 == 0)
				s += fabs(arr[i]);
	}
	return s; 
}