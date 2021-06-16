#include<stdio.h>
#include <string.h>
#define NUM_PLANETS 9

int main(int argc, char *argv[])
{
	const char *planets[] = { "Mercury", "Venus", "Earth",
		"Mars", "Jupiter", "Saturn",
		"Uranus", "Neptune", "Pluto" };
	int i, j;
	if (argc == 1)
		printf("aboba");
	for (i = 1; i < argc; i++) {
		for (j = 0; j < NUM_PLANETS; j++)
			if (strcmp(argv[i], planets[j]) == 0) {
				printf("%s is planet number%d\n", argv[i], j + 1);
				break;
			}
		if (j == NUM_PLANETS)
			printf("%s not a planet\n", argv[i]);
	}
	return 0;
}