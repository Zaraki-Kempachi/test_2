#include <stdio.h>
#define N 4

void quicksort(int arr[], int low, int high);
int rozdelenie(int arr[], int low, int hidh);

int main() {
	int arr[N], i; 
	printf("vvedite %d chisel dlya sortirovki: ", N);
	for (i = 0; i < N; i++)
		scanf_s("%d", &arr[i]);
	quicksort(arr, 0, N - 1);
	printf("otsortirovanie chisla: ");
	for (i = 0; i < N; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}

void quicksort(int arr[], int low, int high) 
{
	int middle;
	if (low >= high) return;
	middle = rozdelenie(arr, low, high);
	quicksort(arr, low, middle - 1);
	quicksort(arr, middle +1, high);
}

int rozdelenie(int arr[], int low, int high)
{
	int part_element = arr[low];
	for (;;)
	{
		while (low < high && part_element >= arr[high])
			high--;
		if (low >= high) break;
		arr[low++] = arr[high];
		while (low < high && arr[low] >= part_element)
			low++;
		if (low >= high) break;
		arr[high--] = arr[low];
	}
	arr[high] = part_element;
	return high;
}