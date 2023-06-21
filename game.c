#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "display.h"
#include "game.h"

void game(player *player1, player *player2)
{
	int i,indice1,indice2,test;

	do
	{
		display_team(*player1);
		display_team(*player2);
		for (i=0;i<size_team;i++)
		{
			player1->team[i].energy += player1->team[i].speed;
			player2->team[i].energy += player2->team[i].speed;
		}
			test=true;
			while (test) {
			printf("Player %s, which fighter do you want to use ?",player1->name);
			scanf("%d",&indice1);
				if (player1->team[indice1].alive==false) 
			{
			printf("The fighter is ko ; select a new one");
			test=true;
			}	
			else test=false;
			};
			test=true;
			while (test) {
			printf("Player %s, which fighter do you want to attack ?",player1->name);
			scanf("%d",&indice2);
			if (player2->team[indice2].alive==false) 
			{
			printf("The fighter is ko ; select a new one");
			test=true;
			}	
			else test=false;
			};
			if (player1->team[indice1].energy >= 100)
			{
				printf("\n******special attack**********\n");
				special_attack(player1,player2,indice1,indice2);
				player1->team[i].energy = 0;
			}
			else {printf("\n/******classic attack**********/\n");
			common_attack(player1,player2,indice1,indice2);
			}
			test=true;
			while (test) {
			printf("Player %s, which fighter do you want to use ?",player2->name);
			scanf("%d",&indice1);
				if (player2->team[indice1].alive==false) 
			{
			printf("The fighter is ko ; select a new one");
			test=true;
			}	
			else test=false;
			};
			test=true;
			while (test) {
			printf("Player %s, which fighter do you want to attack ?",player2->name);
			scanf("%d",&indice2);
			if (player1->team[indice2].alive==false) 
			{
			printf("The fighter is ko ; select a new one");
			test=true;
			}	
			else test=false;
			};
			if (player2->team[indice1].energy >= 100)
			{
			printf("\n******special attack**********\n");
			special_attack(player2,player1,indice1,indice2);
			player1->team[i].energy = 0;
			}
			else {printf("\n/******classic attack**********/\n");
			common_attack(player2,player1,indice1,indice2);}
	// Test if fighters of player 1 and 2 are KO
	test_defeat(player1);
	test_defeat (player2);
	} while (player1->defeated == false || player2->defeated == false);
}

void test_defeat(player *player)
{
int cpt=0;
int i;
for (i=0;i<size_team;i++)
	if (player->team[i].hp<=0) 
		cpt ++;
if (cpt==size_team) player->defeated=true;
}

void common_attack(player *player_attack, player *player_defender, int i,int j){
player_defender->team[j].hp-=player_attack->team[i].atk*player_defender->team[j].def;
if (player_defender->team[j].hp <=0) player_defender->team[j].alive=false;

} 

void special_attack(player *player_attack, player *player_defender, int i,int j){
int damage;
damage=player_attack->team[i].atk*2*player_defender->team[j].def;
player_defender->team[j].hp-= damage;
player_attack->team[i].hp += 0.2*damage;
if (player_defender->team[j].hp <=0) player_defender->team[j].alive=false;
}
