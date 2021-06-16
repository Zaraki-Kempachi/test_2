#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	printf("Pravila:\n"
		"Igrok nazivaet lyboe chislo ot 2 do 12 i stavku\n");
	int kubik_1, kubik_2, num, sum_kubik, ochki = 100, stavka, zapros;
	srand(time(NULL));
	while (ochki > 0) {
		printf("nazovite vashe chislo(2-12): ");
		scanf_s("%d", &num);
		while (num > 12 || num < 2) {
			printf("vashe chislo ne vhodit v diapazon\nvvedite novoe: ");
			scanf_s("%d", &num);
		}
		printf("sdelayte stavku(u vas est %d ochkov): ", ochki);
		scanf_s("%d", &stavka);
		while (stavka > ochki  || stavka <= 0) {
			printf("vasha stavka bolshe kol-va ochkov ili menshe chem 1\nvvedite novuyu: ");
			scanf_s("%d", &stavka);
		}
		kubik_1 = rand() % 6 + 1;
		kubik_2 = rand() % 6 + 1;
		printf("znachenie pervogo kubika - %d\n", kubik_1);
		printf("znachenie vtorogo kubika - %d\n", kubik_2);
		sum_kubik = kubik_1 + kubik_2;
		if (sum_kubik == num) {
			ochki += stavka * 4;
			printf("vi ugadali!!\nstavka umnogaetsya na 4\nu vas %d ochkov\n", ochki);
		}
		else if ((sum_kubik < 7 && num < 7) || (sum_kubik > 7 && num > 7)) {
			ochki += stavka;
			printf("vi vigrali stavku\nu vas %d ochkov\n", ochki);
		}
		else
		{
			ochki -= stavka;
			printf("vi proigrali stavku\nu vas %d ochkov\n", ochki);
		}
		printf("hotite prodolgat?\n1 - da\n2 - net\n");
		scanf_s("%d", &zapros);
		if(zapros==1)
			system("cls");
		else exit(0);
	}
	printf("zakonchilis ochki :(");
}