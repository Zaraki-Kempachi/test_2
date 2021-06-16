#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 7

void input_from_keyboard(int[][MAX]);
void random_matrix(int[][MAX]);
int summa_elementov(int[][MAX]);
int opredelitel(int[][MAX]);

int main()
{
	int matr[MAX][MAX], o;
	printf("1 - vvesti elementi matrici [7][7] s klaviaturi\n2 - zapolnit matricu [7][7] sluchaynimi chislami\n");
	scanf_s("%d", &o);
	switch (o)
	{
	case 1: input_from_keyboard(matr); break;
	case 2: random_matrix(matr); break;
	default: printf("oshibka vvoda"); exit(0); break;
	}
	printf("summa videlennih elementov: %d\n\n", summa_elementov(matr));
	printf("opredelitel podmatrici: %d\n\n", opredelitel(matr));
}

void input_from_keyboard(int matr[][MAX]) {
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			scanf_s("%d", &matr[i][j]);
}

void random_matrix(int matr[][MAX]) {
	srand(time(NULL));
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			matr[i][j] = rand() % 801;
	printf("vasha matrica:\n");
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++)
			printf("%5d", matr[i][j]);
		putchar('\n');
	}
	putchar('\n');
}

int summa_elementov(int matr[][MAX]) {
	int s;
	s = matr[1][6] + matr[2][5] + matr[2][6] + matr[3][4] + matr[3][5] + matr[3][6] + matr[4][5] + matr[4][6] + matr[5][6];
	return s;
}

int opredelitel(int matr[][MAX]) {
	int d;
	d = matr[1][1] * matr[2][2] * matr[3][3] + matr[1][2] * matr[2][3] * matr[3][1] + matr[1][3] * matr[2][1] * matr[3][2] - matr[1][3] * matr[2][2] * matr[3][1] - matr[1][2] * matr[2][1] * matr[3][3] - matr[1][1] * matr[2][3] * matr[3][2];
	return d;
}
