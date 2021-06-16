#include <stdio.h>
extern "C" {
#include "sds.h"
}
#include <ctype.h>

/**
*	Ввод рядка
*
*	@param str вхідний рядок
*   @param n максимальное кол-во символов
*	@return i кол-во символов рядка
*/

int read_line(sds, int);
/**
*	Проверка коректности ввода и конвертация телефонного номера
*
*	@param phone вхідний рядок
*	@param n кол-во симвлов рядка
*	@return 1, якщо номер коректно введений і перетворення успішне
*   @return 0, якщо номер введено некоректно
*/
int process_phone(sds, int);

int main() 
{
	sds mystring = sdsnewlen("", 14);
	int x;
	printf("vvedite vash nomer: ");
	x=read_line(mystring, sdslen(mystring));
	if(process_phone(mystring, x))
		printf("vash nomer - %s \n ", mystring);
	else 
		printf("nomer vveden nekorektno\n");
	sdsfree(mystring);
}

int read_line(sds str, int n)
{
	int ch, i = 0;
	while ((ch = getchar()) != '\n')
		if (i < n)
			str[i++] = ch;
	str[i] = '\0';
	return i;
}

int process_phone(sds phone, int n)
{
	sds s = sdsnewlen("\0", 10);
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
			s[k++] = phone[i];
	}
	for (int i = 0; i < 10; i++)
		phone[i] = '\0';
	s[k] = '\0';
	sds s2 = sdsnew("+38");
	s2=sdscatsds(s2, s);
	sdscpy(phone, s2);
	sdsfree(s);
	sdsfree(s2);
	return 1;
}