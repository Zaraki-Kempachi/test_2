#include<stdio.h>

void result(int);

int main(void)
{
	int x;
	printf("vvedite kolichestvo balow (1-100): ");
	scanf_s("%d", &x);
	if (x > 100 || x < 0) {
		printf("vvedena nekorektnaya ocenka");
		return 1;
	}//проверка правильности введенного числа
	printf("vasha ocenka: ");
	result(x);
}
void result(int a)//функция сопоставляющая оценку
{
	 (a <= 100 && a >= 90) ? putchar('A') :
		(a >= 82 && a <= 89) ? putchar('B') :
		(a >= 75 && a <= 81) ? putchar('C') :
		(a >= 64 && a <= 74) ? putchar('D') :
		(a >= 60 && a <= 63) ? putchar('E') :
		(a >= 35 && a <= 59) ? putchar('F'), putchar('X') : putchar('F');
	return;
}