#include <stdio.h>
//#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "display.h"
#include "get_and_select.h"
#include "character_select.h"

//#define nb_stats 5	// defines the number of base stastics (hp,atk,def,speed) for each character (subject to change)
//#define nb_fighters 6	// defines the number of playable fighters in the game
//#define size_team 3

int main();
void main_menu();
void gamemode();
void bot_lvl();
void game();

void main_menu(bool* prun,fighter *list)	// main menu (user types a number between 1 and 3 to select what they want to do)
{
	int select;
	player player1,player2;
	printf("\n 1. Play \n 2. Characters \n 3. Quit \n");
	scanf("%d",&select);
	switch(select)
	{
		case 1 : 
			gamemode(list,&player1,&player2);	// start a game
			break ;
		case 2 : 
			display_fighter_list(list,nb_fighters); // displays all available characters and their stats
			break ;
		case 3 : 
			*prun = false ; // shuts off program
			break ;
		default : 
			printf("\n Please enter a number between 1 and 3. \n"); 
			break;
	}
}

void gamemode(fighter *list, player *player1, player *player2)		// user types a number between 1 and 2 to choose whether they want to play agaisnt a player or a bot
{
	int select;
	bool stop = false;
	do
	{
		printf("\n 1. Player VS Player \n 2. Player VS AI \n 3. Go back \n");
		scanf("%d",&select);
		switch(select)
		{
			case 1 : 
				//player name
				printf("\n player 1 : type your name ");
				scanf("%s",player1->name);
				printf("\n player 2 : type your name ");
				scanf("%s",player2->name);
				character_select(list, player1,player2,false);
				display_team(*player1);
				display_team(*player2);
                game(player1,player2);
				stop = true;
				break ;
			case 2 :
				printf("\n player 1 : type your name ");
				scanf("%s",player1->name);
				bot_lvl(list, player1,player2); // bot difficulty selection
				display_team(*player1);
				display_team(*player2);
                stop = true;
				break;
			case 3 :
				stop = true; // goes back to main menu
				break;
			default : 
				printf("\n Please enter a number between 1 and 2. \n"); 
				break ;
		}
	} while (stop == false);
}

void bot_lvl(fighter *list, player *player1, player *player2)	// user types a number between 1 and 2 to set bot difficulty
{
	int select;
	bool stop = false;
	printf("\n 1. Easy \n 2. Medium \n 3. Hard \n 4. Go back \n");
	scanf("%d",&select);
	do
	{
		switch(select)
		{
			case 1 : 
				printf("\n You are playing against bot Athalin \n"); // easy
				strcpy(player2->name,"Athalin");
				character_select(list, player1,player2,true);
				stop = true;
				break ;
			case 2 : 
				printf("\n You are playing against bot Maxou. \n"); // medium
				strcpy(player2->name,"Maxou");
				character_select(list, player1,player2,true);
				stop = true;
				break ;
			case 3 :					
				printf("\n You are playing against bot Valentin. \n"); // hard
				strcpy(player2->name,"Valentin");
				character_select(list, player1,player2,true);
				stop = true;
				break;
			case 4 :
				stop = true; // goes back to main menu
				break;
			default : 
				printf("\n Please enter a number between 1 and 3. \n"); 
				break ;
		}
	} while (stop == false);
}



int main()
{
	bool run = true;
	bool* prun = &run; // points to run so that run variable can be switched to false within the rest of the program
	fighter *list = NULL;
	list=get_fighters();
	while (run == true) // game stops if set to false
	{
		main_menu(prun,list);
	}
	free(list);
}
