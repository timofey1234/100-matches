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

void start(int NumOfPlayers){
	printf ("Please, enter names of all players \n");
	printf ("Player 1: \n");
	scanf("%s", name1);
	if (NumOfPlayers >= 2) {
		printf ("Player 2: \n");
		scanf("%s", name2);
	} else strncpy(name2,"AI1",sizeof(name3)-1);
	if (NumOfPlayers >= 3) {
		printf ("Player 3: \n");
		scanf("%s", name3);
	} else strncpy(name3,"AI2",sizeof(name3)-1);;
	if (NumOfPlayers >= 4) {
		printf ("Player 4: \n");
		scanf("%s", name4);
	} else strncpy(name4,"AI3",sizeof(name3)-1);;

}

int PlayerControl(int Player, int Opponents){
	int n;
	switch (Opponents) {
		case 1: n=2; break;
		case 2: n=2; break;
		case 3: n=3; break;
		default: n=4; break;
	}
		if (Player > n) Player = 1;
		return Player;
}


int check(int value){

	do {
			Correct = scanf("%d", &value);
			while (getchar() != '\n');
			if (Correct != 1) printf("Incorrect value, please use number value \n");
			if (value<1) printf("Incorrect value, please use positive value\n");
		} while (Correct != 1 || value<1) ;


	return value;
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
		Num = check(Num);
		break;
	case 2:
		name = name2;
		printf("It's %s turn! \n", name);
		if (NumOfPlayers>=2) {
			printf ("Table has %d matches, how much would you take?\n", Count);
			Num = check(Num);
		} else {
			AITurn();
		}
		break;
	case 3:
		name = name3;
		printf("It's %s turn! \n", name);
		if (NumOfPlayers>=3) {
			printf ("Table has %d matches, how much would you take?\n", Count);
			Num = check(Num);

		} else {
			AITurn();
		}
		break;
	case 4:
		name = name4;
		printf("It's %s turn! \n", name);
		if (NumOfPlayers>=4) {
			printf ("Table has %d matches, how much would you take?\n", Count);
			Num = check(Num);

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
		Player = PlayerControl(Player, Opponents);
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

			start(NumOfPlayers);
			Count = InitialCount;
			Player = game(Player, NumOfPlayers, Opponents);
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

	return 0;
}

