#include <stdio.h>

int check_repeated_dig(long);
void information(long, int[]);
void output(int[]);
int clean_stdin() {
	while (getchar() != '\n');
	return 1;
}

int main() {
	long n;
	char c;
	int arr[10] = { 0 };
	do {
		printf("vvedite chislo: ");
	}while
	(((scanf_s("%ld%c", &n, &c)!=2 || c!='\n') && clean_stdin()));
		if (n < 0) {
			printf("vashe chislo slishkom bol'shoe ili otricatelnoe\nvvedite drugoe:");
			scanf_s("%ld", &n);
		}
		if (check_repeated_dig(n)) {
			printf("est cifri, kotorie povtoryayutsya\n");
			information(n, arr);
			output(arr);
		}
		else
			printf("net cifr, kotorie povtoryayutsya\n");
}

int check_repeated_dig(long n) {
	int digit;
	int digit_seen[10] = { 0 };
	while (n > 0) {
		digit = n % 10;
		if (digit_seen[digit])
			break;
		digit_seen[digit] = 1;
		n /= 10;
	}
	return n;
}

void information(long n, int arr[10]) {
	int digit_seen[10] = { 0 };
	int digit;
	for (int i = 0; i < 10; i++)
		arr[i]++;
	while(n>0){
		digit = n % 10;
		if (digit_seen[digit])
			arr[digit]=arr[digit]++;
		digit_seen[digit] = 1;
		n /= 10;
	}
	return;
}

void output(int arr[10]) {
	for (int i = 0; i < 10; i++)
		if (arr[i] >= 2)
			printf("cifra %d (%d raza)\n", i, arr[i]);
	return;
}