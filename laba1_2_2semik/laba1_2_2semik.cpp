#include<stdio.h>
#define g 2//константа ширины купе

void prikol();

int main()
{
	int m, k, a, b;//m - место в вагоне; k - коефициент, необходимый для нахождения расстояния к туалету;a - расстояние к первому туалету; b - расстояние ко ворому туалету 
	double x;
	printf("vvedite nomer svoego mesta v vagone: ");
	scanf_s("%d", &m);
	if (m>54 || m<=0)//проверка коректности ввода и завершение в случае ошибки
	{
		prikol();
		printf("vvedeno nekorektnoe mesto\n");
		prikol();
		return 1;
	}
	prikol();
	(m % 2 == 0) ? printf("vasha polka - verhnyya\n") : printf("vasha polka - nignyaya\n");
	prikol();
	(m >= 1 && m <= 36) ? printf("vashe mesto v kupe\n") : printf("vashe mesto bokovoe\n");
	prikol();
	if (m >= 0 && m <= 36)//вывод номера купе
	{
		printf("nomer vashego kupe: ");
		x = m;
		x = x / 4;
		    (x <= 1) ? printf("I"):
			(x <= 2) ? printf("II") : 
			(x <= 3) ? printf("III") : 
			(x <= 4) ? printf("IV") : 
			(x <= 5) ? printf("V") : 
			(x <= 6) ? printf("VI") : 
			(x <= 7) ? printf("VII") :
			(x <= 8) ? printf("VIII") : printf("IX");
			printf("\n");
			prikol();
	}
	x = m;
	x = x / 2;
	   (x <= 2 || x >= 26.5) ? k = 1: 
		(x <= 4 || x >= 25.5) ? k = 2:
		(x <= 6 || x >= 24.5) ? k = 3:
		(x <= 8 || x >= 23.5) ? k = 4: 
		(x <= 10 || x >= 22.5) ? k = 5 :
		(x <= 12 || x >= 21.5) ? k = 6 : 
		(x <= 14 || x >= 20.5) ? k = 7 :
		(x <= 16 || x >= 19.5) ? k = 8 : k=9;

	a = g * k - g / 2 + g;//формула для расстояния от первого туалета, где g - ширина одного купе,
	//k - номер купе; также отнимается половина ширины купе и добавляется ширина купе проводника, взятая как 2 метра  
	b = g * (10 - k)-g/2;//формула расстояния до второго туалета
	printf("blizhayshi tualet v %d metrah ot vashego kupe\n", (a < b) ? a : b); 
	prikol();
}
void prikol()
{
	unsigned short i;
	for (i = 0; i < 50; i -= -1)
		putchar('*');
	putchar('\n');
}