#include <stdio.h>

void input_array(int *, int );
void print_matr(int*, int);

int main()
{
	int matr[100][100], NUM;
	printf("vvedite kol-vo ryadkov i stolbzow matrici: ");
	scanf_s("%d", &NUM);
	printf("vvedite matr: ");
	input_array(*matr, NUM);
	print_matr(*matr, NUM);
}

void input_array(int *matr, int NUM) {
	int *p;
	for (p = matr; p < matr + NUM * NUM; p++)
		scanf_s("%d", p);
}
void print_matr(int *matr, int NUM)
{
	int *p;
	for (int i = 0; i < NUM; i++) 
	{
		for (p = &matr[i]; p < &matr[i] + NUM; p++) {
			printf("%5d", *p);
		}
		putchar('\n');
	}
}