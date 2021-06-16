#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define NAME_LEN 25

int num_parts = 0;
struct part {
	int number;
	char name[NAME_LEN + 1];
	int on_hand;
}*inventory=(struct part*)malloc(sizeof(struct part)*(num_parts+1));


int read_line(char str[], int n);
int find_part(int);
void insert();
void search();
void update();
void print();

int main()
{
	char code;
	for (;;) {
		printf("vvedite kod oper(i, s, u, p, q):");
	    scanf_s(" %c", &code);
		while (getchar() != '\n');
		switch (code)
		{
		case 'i': insert(); break;
		case 's': search(); break;
		case 'u': update(); break;
		case 'p': print(); break;
		case 'q': {free(inventory);
			return 0; }
		default: printf("neverniy vvod\n");
		}
		printf("\n");
	}
} 

int read_line(char str[], int n)
{
	int ch, i = 0;
	while (isspace(ch = getchar()))
		;
	while (ch != '\n' && ch != EOF) {
		if (i < n)
			str[i++] = ch;
		ch = getchar();
	}
	str[i] = '\0';
	return i;
}

int find_part(int number)
{
	int i;
	for (i = 0; i < num_parts; i++)
		if (inventory[i].number == number)
			return i;
	return -1;
}

void insert() {
	FILE*fp = fopen("doub", "ab");
	int part_number;
	printf("vvedite kod tovara: ");
	scanf_s("%d", &part_number);
	if (find_part(part_number) >= 0) {
		printf("takoy element uge est\n");
		return;
	}
	inventory[num_parts].number = part_number;
	printf("vvedite nazvanie tovara: ");
	read_line(inventory[num_parts].name, NAME_LEN);
	printf("vvedite kol-vo tovara v nalichii: ");
	scanf_s("%d", &inventory[num_parts].on_hand);
	fprintf(fp, "%d%s%d", inventory[num_parts].number, inventory[num_parts].name, inventory[num_parts].on_hand);
	num_parts++;
	inventory = (struct part*)realloc(inventory, sizeof(struct part)*(num_parts+1));
	fclose(fp);
}

void search()
{
	int i, number;
	printf("vvedite kod tovara: ");
	scanf_s("%d", &number);
	i = find_part(number);
	if (i >= 0) {
		printf("Nazvanie: %s\n", inventory[i].name);
		printf("V nalichii: %d\n", inventory[i].on_hand);
	}
	else
		printf("Net tovara s takim kodom\n");
}

void update()
{
	int i, number, change;
	printf("vvedite kod tovara: ");
	scanf_s("%d", &number);
	i = find_part(number);
	if (i >= 0) {
		printf("naskolko izmenit kol-vo: ");
		scanf_s("%d", &change);
		inventory[i].on_hand += change;
	}
	else
		printf("net takogo tovara\n");
}

void print()
{
	FILE*fp = fopen("testi.txt", "w");
	FILE*file = fopen("doub.txt", "rb");
	int i;
	char gh[25];
	int j, m;
	printf("kod tovara    Nazvanie                         V nalichii\n");
	fprintf(fp, "kod tovara    Nazvanie                         V nalichii\n");
	for (i = 0; i < num_parts; i++) {
		printf("%7d        %-25s%11d\n", inventory[i].number, inventory[i].name, inventory[i].on_hand);
		fscanf(file, "%d%s%d", &j, gh, &m);
		fprintf(fp, "%d%s%d", j, gh, m);
	}
	fclose(fp);
	fclose(file);
}