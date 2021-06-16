#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int find_kol_elem(double *array, int n, int * kol_less, int * kol_equal, int * kol_more);

int main()
{
	int n, kol_less, kol_equal, kol_more, how_input;
	double array[100], *p;
	printf("input size of array(<100): ");
	scanf_s("%d", &n);
	printf("1 - input array from keyboard\n2 - array with random numbers\n");
	scanf_s("%d", &how_input);
	if (how_input == 1) {
		printf("input your array: ");
		for (p = array; p < array + n; p++)
			scanf_s("%lf", p);
	}
	else if (how_input == 2) {
		srand(time(NULL));
		for (p = array; p < array + n; p++)
			*p = rand()%1000-500;
		printf("your array: ");
		for (p = array; p < array + n; p++)
			printf("%5g", *p);
		printf("\n");
	}
	else {
		printf("input error");
		return 0;
	}
	if(find_kol_elem(array, n, &kol_less, &kol_equal, &kol_more))
		printf("\nkol-vo elem < middle num - %d \nkol-vo elem equal middle num - %d \nkol-vo elem > middle num - %d", kol_less, kol_equal, kol_more);
}

int find_kol_elem(double *array, int n, int * kol_less, int * kol_equal, int * kol_more) 
{
	double *p, s = 0;
	double middle;
	*kol_less = *kol_equal = *kol_more = 0;
	for (p = array; p < array + n; p++)
	{
		s += *p;
	}
	middle = s / n;
	for (p = array; p < array + n; p++)
	{
		if (*p > middle)
			*kol_more+=1;
		else if (*p < middle)
			*kol_less+=1;
		else
			*kol_equal+=1;
	}
	return 1;
}