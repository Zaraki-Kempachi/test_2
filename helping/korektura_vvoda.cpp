#include <stdio.h>

int clean_stdin() {
	while (getchar() != '\n');
	return 1;
}

char c; long n;

int main() {
	do {
		printf("vvedite chislo: ");
	} while
		(((scanf_s("%ld%c", &n, &c) != 2 || c != '\n') && clean_stdin()));
}