#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM_SUITS 4
#define NUM_RANKS 13

int main()
{
	int in_hand[NUM_SUITS][NUM_RANKS] = { 0 }, dve_pari[NUM_RANKS] = {0};
	int num_cards, rank, suit, k;
	const char rank_kode[] = { '2','3','4','5','6','7','8','9','t','j','q','k','a' };
	const char suit_code[] = {'c','d','h','s'};
	srand(time(NULL));
	for (int i = 1; i < 5; i++)
	{
		printf("karti %d-go igroka: ", i);
		num_cards = 6;
		k = 1;
		for (int i = 0; i < NUM_RANKS; i++)
			dve_pari[i] = 0;
		while (num_cards > 0)
		{
			suit = rand() % NUM_SUITS;
			rank = rand() % NUM_RANKS;
			if (!in_hand[suit][rank]){
				in_hand[suit][rank] = 1;
				if (dve_pari[rank] == 1)
					dve_pari[rank] = 2;
				else
					dve_pari[rank] = 1;
				num_cards--;
				printf("%c%c ", rank_kode[rank], suit_code[suit]);
			}
		}
		for (int i = 0; i < NUM_RANKS; i++) {
			if (dve_pari[i] == 2)
				k++;
		}
		if (k == 3) {
			printf("- u vas dve pari!");
		}
		putchar('\n');
	}
}