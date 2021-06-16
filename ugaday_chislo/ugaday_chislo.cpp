#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define NAME_LEN 40

int num_parts = 0, delet_num_parts=0;
struct rabotyaga{
	int number;
	char name[NAME_LEN + 1];
	int data[3];
	double stavka;
	double basic_zp;
}*sotrudniki = (struct rabotyaga*)malloc(sizeof(struct rabotyaga)*(num_parts + 1)),
*delet_sotr = (struct rabotyaga*)malloc(sizeof(struct rabotyaga)*(delet_num_parts + 1));

int read_line(char[], int);
int find_part(int);
void insert();
void udalit();
void update();
void print();
void after_date();
void diap_zp();
void vostanov();

int main()
{
	char code;
	for (;;) {
		printf("i - dobavit novogo sotrudnika i ego dannie\n"
		"d - udalit sotrudnika iz bazi dannih\n"
		"u - izmenit dannie o sotrudnike\n"
		"p - prosmotr vseh sotrudnikov i ih dannih\n"
		"a - prosmotr sotrudnikov prinyatih posle zadanoi dati\n"
		"m - prosmotr sotrudnikov s zarabotnoi platoi v zadanom diapazone\n"
		"r - vostanovit udalennogo sotrudnika\n"
		"q - vihod\nvvedite kod oper(i, d, u, p, a, m, r, q):");
		scanf_s(" %c", &code);
		while (getchar() != '\n');
		switch (code) {
		case 'i': insert(); break;
		case 'd': udalit(); break;
		case 'u': update(); break;
		case 'p': print(); break;
		case 'a': after_date(); break;
		case 'm': diap_zp(); break;
		case 'r': vostanov(); break;
		case 'q': {free(sotrudniki); free(delet_sotr); return 0; }
		default: printf("neverniy vvod\n");
		}
		system("cls");
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
		if (sotrudniki[i].number == number)
			return i;
	return -1;
}

int find_del_part(int number)
{
	int i;
	for (i = 0; i < delet_num_parts; i++)
		if (delet_sotr[i].number == number)
			return i;
	return -1;
}

void insert() {
	int sotr_number;
	printf("vvedite kod sotrudnika: ");
	scanf_s("%d", &sotr_number);
	if (find_part(sotr_number) >= 0) {
		printf("etot sotrudnik uge vnesen\n");
		return;
	}
	sotrudniki[num_parts].number = sotr_number;
	printf("vvedite imya sotrudnika: ");
	read_line(sotrudniki[num_parts].name, NAME_LEN);
	printf("vvedite datu postupleniya sotudnika:\n");
	printf("vvedite god: ");
	scanf_s("%d", &sotrudniki[num_parts].data[0]);
	printf("vvedite nomer mesyaca: ");
	scanf_s("%d", &sotrudniki[num_parts].data[1]);
	printf("vvedite den': ");
	scanf_s("%d", &sotrudniki[num_parts].data[2]);
	printf("vvedite stavku sotrudnika: ");
	scanf_s("%lf", &sotrudniki[num_parts].stavka);
	printf("vvedite bazovuyu zp sotrudnika: ");
	scanf_s("%lf", &sotrudniki[num_parts].basic_zp);
	num_parts++;
	sotrudniki = (struct rabotyaga*)realloc(sotrudniki, sizeof(struct rabotyaga)*(num_parts + 1));
}

void update()
{
	int i, number;
	printf("vvedite kod sotrudnika: ");
	scanf_s("%d", &number);
	i = find_part(number);
	if (i >= 0) {
		printf("vvedite novuyu stavku sotrudnika: ");
		scanf_s("%f", &sotrudniki[i].stavka);
		printf("vvedite novuyu zarplatu sotrudnika: ");
		scanf_s("%f", &sotrudniki[i].basic_zp);
	}
	else
		printf("net takogo sotrudnica\n");
}

void print()
{
	FILE*fp = fopen("database.txt", "w");
	int i;
	fprintf(fp, "Kod sotrudnika    Imya                         Stavka          Bazovaya zp       Data postupleniya\n");
	for (i = 0; i < num_parts; i++) {
		fprintf(fp, "%7d          %-25s%9g%18g%18d.%2d.%2d\n", sotrudniki[i].number, sotrudniki[i].name, sotrudniki[i].stavka, sotrudniki[i].basic_zp, sotrudniki[i].data[0], sotrudniki[i].data[1], sotrudniki[i].data[2]);
	}
	fclose(fp);
}

void udalit()
{
	int i, number;
	printf("vvedite kod sotrudnika, kotorogo nugno udalit: ");
	scanf_s("%d", &number);
	i = find_part(number);
	if (i >= 0)
	{
		delet_sotr[delet_num_parts] = sotrudniki[i];
		for (i; i < num_parts; i++)
			sotrudniki[i] = sotrudniki[i + 1];
		num_parts--;
		sotrudniki = (struct rabotyaga*)realloc(sotrudniki, sizeof(struct rabotyaga)*(num_parts + 1));
		delet_num_parts++;
		delet_sotr = (struct rabotyaga*)realloc(delet_sotr, sizeof(struct rabotyaga)*(delet_num_parts + 1));
	}
	else
		printf("net takogo sotrudnica\n");
}

void after_date()
{
	FILE*fp = fopen("database.txt", "w");
	int i, arr[3];
	printf("vvedite cherez probel god mesyac i den'(xxxx yy zz): ");
	for (int j = 0; j < 3; j++)
		scanf_s("%d", &arr[j]);
	fprintf(fp, "Kod sotrudnika    Imya                         Stavka          Bazovaya zp       Data postupleniya\n");
	for (i = 0; i < num_parts; i++) {
		if(sotrudniki[i].data[0] > arr[0])
			fprintf(fp, "%7d          %-25s%9g%18g%18d.%2d.%2d\n", sotrudniki[i].number, sotrudniki[i].name, sotrudniki[i].stavka, sotrudniki[i].basic_zp, sotrudniki[i].data[0], sotrudniki[i].data[1], sotrudniki[i].data[2]);
		else if (sotrudniki[i].data[0] == arr[0]) {
			if(sotrudniki[i].data[1] > arr[1])
				fprintf(fp, "%7d          %-25s%9g%18g%18d.%2d.%2d\n", sotrudniki[i].number, sotrudniki[i].name, sotrudniki[i].stavka, sotrudniki[i].basic_zp, sotrudniki[i].data[0], sotrudniki[i].data[1], sotrudniki[i].data[2]);
			else if (sotrudniki[i].data[1] == arr[1])
			{
				if(sotrudniki[i].data[2] > arr[2])
					fprintf(fp, "%7d	        %-25s%9g%18g%18d.%2d.%2d\n", sotrudniki[i].number, sotrudniki[i].name, sotrudniki[i].stavka, sotrudniki[i].basic_zp, sotrudniki[i].data[0], sotrudniki[i].data[1], sotrudniki[i].data[2]);
			}
		}
	}
	fclose(fp);
}

void diap_zp()
{
	FILE*fp = fopen("database.txt", "w");
	int i;
	double a, b;
	printf("vvedite nachalo diapazona: ");
	scanf_s("%lf", &a);
	printf("vvedite konec diapazona: ");
	scanf_s("%lf", &b);
	fprintf(fp, "Kod sotrudnika    Imya                         Stavka          Bazovaya zp       Data postupleniya\n");
	for (i = 0; i < num_parts; i++) {
		if (sotrudniki[i].stavka*(sotrudniki[i].basic_zp) >= a && sotrudniki[i].stavka*(sotrudniki[i].basic_zp)<=b)
			fprintf(fp, "%7d          %-25s%9g%18g%18d.%2d.%2d\n", sotrudniki[i].number, sotrudniki[i].name, sotrudniki[i].stavka, sotrudniki[i].basic_zp, sotrudniki[i].data[0], sotrudniki[i].data[1], sotrudniki[i].data[2]);
	}
	fclose(fp);
}

void vostanov()
{
	int i, number;
	printf("vvedite kod udalennogo sotrudnika: ");
	scanf_s("%d", &number);
	i = find_del_part(number);
	if (i >= 0) {
		sotrudniki[num_parts] = delet_sotr[i];
		for (i; i < num_parts; i++)
			delet_sotr[i] = delet_sotr[i + 1];
		num_parts++;
		delet_num_parts--;
		sotrudniki = (struct rabotyaga*)realloc(sotrudniki, sizeof(struct rabotyaga)*(num_parts + 1));
		delet_sotr = (struct rabotyaga*)realloc(delet_sotr, sizeof(struct rabotyaga)*(delet_num_parts + 1));
	}
	else
		printf("net takogo udalennogo sotrudnica\n");
}