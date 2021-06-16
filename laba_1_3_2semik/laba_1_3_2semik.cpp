#include<stdio.h>
#include<stdlib.h>

void proverka(int);
void stars();

int main()//8 квартир на этаже, 5 этажей, всего 40 квартир, 4 подьезда 
{
	int n, etag, pod, kol_komnat, arr[] = { 1,2,3,4,5 };
	float x;
	printf("vvedite nomer vashey kvartiri: ");
	scanf_s("%d", &n);
	stars();
	proverka(n);

	(n%-4==1) ? pod =1 : (n%-4 == 2) ? pod = 2 : (n%-4 == 3) ? pod = 3 :pod=4 ;
	printf("nomer vashego podjezda:%2d\n", pod);
	stars();

	x = n;
	x = x / 8;
	for (int i=4; i>=0; i--)
		if (x <= arr[i])
		{
			etag = arr[i];
		}
	printf("nomer vashego etaja:%2d\n",etag);
	stars();

	((n-6)%-8 == 0 || (n-7) %-8 == 0) ? kol_komnat = 4 : kol_komnat = 6;
	printf("kolichestvo komnat v vashey kvartire:%2d\n", kol_komnat);
	stars();
	printf("v vashey kvartire 1 balkon\n");//формула не нужна так как в каждой квартире только один балкон
	stars();
}
void stars()
{
	for (int i = 0; i <= 50; i++)
		putchar('*');
	putchar('\n');
}
void proverka(int a)
{
	if (a > 40 || a <= 0) 
	{
		printf("nekorektniy vvod\n");
		stars();
		exit(1);
	}
	return;
}