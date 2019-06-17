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

void AITurn(){
	if (Num>Count){
		Num=Count;
	} else Num = rand()%10+1;

}

int game(int Player, int NumOfPlayers, int Opponents)
{
	switch (Player){
	default:
		printf("Whooops, bug time!!! \n");
		break;
	case 1:
		name = name1;
		printf("It's %s turn! \n", name);
		printf ("Table has %d matches, how much would you take?\n", Count);
		scanf("%d", Num);
		break;
	case 2:
		name = name2;
		printf("It's %s turn! \n", name);
		if (NumOfPlayers>=2) {
			printf ("Table has %d matches, how much would you take?\n", Count);
			scanf("%d", Num);
		} else {
			AITurn();
		}
		break;
	case 3:
		name = name3;
		printf("It's %s turn! \n", name);
		if (NumOfPlayers>=3) {
			printf ("Table has %d matches, how much would you take?\n", Count);
			scanf("%d", Num));

		} else {
			AITurn();
		}
		break;
	case 4:
		name = name4;
		printf("It's %s turn! \n", name);
		if (NumOfPlayers>=4) {
			printf ("Table has %d matches, how much would you take?\n", Count);
			scanf("%d", Num);

		} else {
			AITurn();
		}
		break;
	}
	printf("%s take %d matches\n", name, Num);
	if((Num>=1) && (Num<=10) && (Num<=Count)){
		Count -= Num;
	if (Count>0) Player+=1;
	} else {
		printf("Incorrect choise, please try again!\n");
	}
	while (Count>0) {
		game(Player, NumOfPlayers, Opponents);
	}

	return Player;
}

int main(){
	srand(time(0));
	int Player, NumOfPlayers, Opponents;
	Player=1;
	wexist = true;


	while (wexist){

			printf ("Number of opponents \n");
			Opponents = check(Opponents);
			printf ("Number of players \n");
			NumOfPlayers = check(NumOfPlayers);
				if (NumOfPlayers>Opponents) {
					printf("Whoops, number of players shouldn't be bigger, than number of opponents \n");
					NumOfPlayers = Opponents;
				}

			Count = InitialCount;
			switch (Player){
			default: printf ("There's something wrong with this code..\n");
					break;
			case 1: printf ("Player %s is winner \n", name1);
					break;
			case 2:	printf ("Player %s is winner \n", name2);
					break;
			case 3: printf ("Player %s is winner \n", name3);
					break;
			case 4: printf ("Player %s is winner \n", name4);
					break;
			}
            printf ("Continue? Y/N\n");
            if (getchar() != 'Y') wexist = false;
	}

	return 0;
}

