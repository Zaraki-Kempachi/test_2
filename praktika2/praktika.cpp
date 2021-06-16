#include <stdio.h>

int get_fibonnachi(int);

int clean_stdin() {
	while (getchar() != '\n');
	return 1;
}

int main() 
{
	char c;
	int pnum;
	do {
		printf("Fibonacci series ordinal number: ");
	} while
		(((scanf_s("%d%c", &pnum, &c) != 2 || c != '\n') && clean_stdin()));
	printf("+-----------+--------------+\n");
	printf("|   nomer   |   znachenie  |\n");
	printf("+-----------+--------------+\n");
	for (int i = 0; i < 10; i++) {
		printf("| %5d     |   %5d      |\n", (pnum + i), get_fibonnachi(pnum + i));
		printf("+-----------+--------------+\n");
	}
}

int get_fibonnachi(int num) {
	if (num == 0 || num == 1)
		return 1;
	return get_fibonnachi(num - 1) + get_fibonnachi(num - 2); 
}