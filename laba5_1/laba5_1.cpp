#include <stdio.h>

/**
* Получение года и месяца выпуска из серийного номера
*
* @param num серийный номер
* @param year год выпуска
* @param week неделя выпуска
* @param nomer номер выпуска
* @return 1, если операция успешна
*/
int year_week_nom(int, int*, int*, int*);

int clean_stdin() {
	while (getchar() != '\n');
	return 1;
}

int main()
{
	long num;
	char c;
	int year, week, nomer;
	do {
	printf("vvedite seriyniy nomer iz 7 cifr: ");
	} while
		(((scanf_s("%ld%c", &num, &c) != 2 || c != '\n') && clean_stdin()));
		if (year_week_nom(num, &year, &week, &nomer)) {
			if (year >= 0 && year <= 20)
				year += 2000;
			else
				year += 1900;
			printf("god - %d, nomer nedeli - %d, poryadkoviy nomer - %d", year, week, nomer);
			putchar('\n');
		}
		else
			printf("neverniy vvod");
}

int year_week_nom(int num, int*year, int*week, int*nomer) 
{
	*year = num/100000;
	if (*year < 0 || *year > 99)
		return 0;
	*week = (num- (*year*100000))/1000;
	if (*week > 53 || *week < 0)
		return 0;
	*nomer = num-*year*100000-*week*1000;
	if(*nomer<1 || *nomer>999)
		return 0;
	return 1;
}
