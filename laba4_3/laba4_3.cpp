#include <stdio.h>

/**
 *Вычисление нужного члена последовательности Фибоначчи
 *
 *@param i номер нужного члена последовательности
 *@return значение нужного члена последовательности
 */
int get_fibonacci(int);

int clean_stdin() {
	while (getchar() != '\n');
	return 1;
}


int main() 
{
	int n;
	char c;
	do {
		printf("vvedite chislo n (n>1):");
	} while
		(((scanf_s("%d%c", &n, &c) != 2 || c != '\n') && clean_stdin()));
	for (int i = n - 1; i <= n + 1; i++)
	{
		printf("%d-y chlen posledovatel'nosti Fibonachi: %d\n",i, get_fibonacci(i));
	}
}

int get_fibonacci(int i) {
	int arr[100];
	arr[0] = arr[1] = arr[2] = 1;
	for (int k=3; k <= i; k++)
		arr[k]=arr[k-2]+arr[k-1];
	return arr[i];
}