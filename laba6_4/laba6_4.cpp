#include <stdio.h>
extern "C" {
#include "sds.h"
}
#include <ctype.h>

int read_line(sds, int);
int process_phone(sds, int);

int main(int argc, sds argv[])
{
	int x;
	if (argc == 1)
	{
		sds mystring = sdsnewlen("", 14);
		printf("vvedite vash nomer: ");
		x = read_line(mystring, sdslen(mystring));
		if (process_phone(mystring, x))
			printf("vash nomer - %s \n ", mystring);
		else
			printf("nomer vveden nekorektno\n");
		sdsfree(mystring);
		return 0;
	}
	if (argv[1][0]=='-' && argv[1][1]=='?' || argv[1][0] == '/' && argv[1][1] == '?') {
		printf("This program can be used to convert one or more\n"
			"numbers of four formats into one common format.\n"
			"For example: \n"
			"0982645156 -> +380982645156\n"
			"(066)6321248 -> +380666321248\n"
			"(095)321-23-98 -> +380953212398\n"
			"096-321-45-78 -> +380963214578\n");
		return 0;
	}
	printf("\xDA---------------\xC2------------------\xC2-----------------\xBF\n");
	printf("|  you inputed  | converted number | function return |\n");
	printf("\xC3---------------\xC5------------------\xC5-----------------\xB4\n");
	for (int i = 1; i < argc; i++) {
		sds mystring = sdsempty();
		sdscpy(mystring, argv[i]);
		if (x=process_phone(mystring, sdslen(mystring)))
			printf("|%15s|%18s|        %d        |\n", argv[i], mystring, x);
		else
			printf("|%15s|         -        |        %d        |\n", argv[i], x);
		if(i!=argc-1)
			printf("\xC3---------------\xC5------------------\xC5-----------------\xB4\n");
	}
	printf("\xC0---------------\xC1------------------\xC1-----------------\xD9\n");
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
	s2 = sdscatsds(s2, s);
	sdscpy(phone, s2);
	sdsfree(s);
	sdsfree(s2);
	return 1;
}