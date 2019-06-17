#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define InitialCount 100


char name1[64],name2[64],name3[64],name4[64];
char* name;
int Count, Num;
size_t Opponents;
bool wexist, Correct;


int main(){
	srand(time(0));
	int Player, NumOfPlayers, Opponents;
	Player=1;
	wexist = true;


	while (wexist){

			printf ("Число оппонентов\n");
			scanf("%d", &Opponents);
			printf ("Число игроков \n");
			scanf("%d", &NumOfPlayers);
				if (NumOfPlayers>Opponents) {
					printf("Упс.Число игроков не может быть больше числа оппонетов\n");
					NumOfPlayers = Opponents;
				}

			Count = InitialCount;
			switch (Player){
			default: printf ("There's something wrong with this code..\n");
					break;
			case 1: printf ("Player %s выйграл \n", name1);
					break;
			case 2:	printf ("Player %s выйграл \n", name2);
					break;
			case 3: printf ("Player %s выйграл \n", name3);
					break;
			case 4: printf ("Player %s iвыйграл \n", name4);
					break;
			}
	}

	return 0;
}

