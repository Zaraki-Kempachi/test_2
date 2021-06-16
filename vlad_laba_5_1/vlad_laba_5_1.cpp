#include <stdio.h>

int split_serial_num(long num, int * size_diag, int * year, int * seria, int * type);

int main()
{
	long serial_num;
	int size_diag, year, seria, type;
	printf("input serial nomer of TV: ");
	scanf_s("%ld", &serial_num);
	if (split_serial_num(serial_num, &size_diag, &year, &seria, &type))
		printf("size of giagonal - %d, last digit of year - %d, seria - %d, type of tuner - %d", size_diag, year, seria, type);
	else
		printf("incorect input");
	printf("\n");
}

int split_serial_num(long serial_num, int * size_diag, int * year, int * seria, int * type) 
{
	if (serial_num < 100000 || serial_num>999999)
		return 0;
	*size_diag = serial_num/10000;
	*year = (serial_num-(*size_diag*10000))/1000;
	*seria = (serial_num - (*size_diag * 10000)- (*year*1000))/10;
	*type = serial_num - (*size_diag * 10000) - (*year * 1000) - (*seria*10);
	return 1;
}