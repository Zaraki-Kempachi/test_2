#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define X 20
/**
*	Проверка коректности ввода и конвертация телефонного номера
*
*	@param phone вхідний рядок
*	@param n кол-во симвлов рядка
*	@return 1, якщо номер коректно введений і перетворення успішне
*   @return 0, якщо номер введено некоректно
*/
int process_phone(char *, int);
/**
*	Ввод рядка
*
*	@param str[] вхідний рядок
*   @param n максимальное кол-во символов
*	@return i кол-во символов рядка
*/
int read_line(char str[], int n);

int main()
{
	int i;
	char str[X];
	printf("vvedite nomer: ");
	i = read_line(str, X);
	if (process_phone(str, i))
		printf("%s - otkonvertirovaniy nomer\n", str);
	else
		printf("nomer vveden nekorektno\n");
}

int process_phone(char * phone, int n)
{
	char str1[X] = "+38";
	char str2[X];
	switch (n)
	{
	case 10: {
		for (int i = 0; i < 10; i++) {
			if (isdigit(phone[i]) == 0)
				return 0;
		}
		break;
	}
	case 12: {
		for (int i = 0; i < 12; i++) {
			if (phone[0] != '(')
				return 0;
			if (phone[4] != ')')
				return 0;
			if (phone[0] == '(')
				continue;
			if (phone[4] == ')')
				continue;
			if (isdigit(phone[i]) == 0)
				return 0;
		}
		break;
	}
	case 13: {
		for (int i = 0; i < 13; i++) {
			if (phone[3] != '-')
				return 0;
			if (phone[7] != '-')
				return 0;
			if (phone[10] != '-')
				return 0;
			if (phone[3] == '-')
				continue;
			if (phone[7] == '-')
				continue;
			if (phone[10] == '-')
				continue;
			if (isdigit(phone[i]) == 0)
				return 0;
		}
		break;
	}
	case 14: {
		for (int i = 0; i < 14; i++) {
			if (phone[0] != '(')
				return 0;
			if (phone[4] != ')')
				return 0;
			if (phone[8] != '-')
				return 0;
			if (phone[11] != '-')
				return 0;
			if (phone[0] == '(')
				continue;
			if (phone[4] == ')')
				continue;
			if (phone[8] == '-')
				continue;
			if (phone[11] == '-')
				continue;
			if (isdigit(phone[i]) == 0)
				return 0;
		}
		break;
	}
	default: return 0; break;
	}
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (isdigit(phone[i]))
			str2[k++] = phone[i];
	}
	str2[k] = '\0';
	strncat(str1, str2, sizeof(str1) - strlen(str1) - 1);
	strcpy(phone, str1);
	return 1;
}

int read_line(char str[], int n)
{
	int ch, i = 0;
	while ((ch = getchar()) != '\n')
		if (i < n)
			str[i++] = ch;
	str[i] = '\0';
	return i;
}
