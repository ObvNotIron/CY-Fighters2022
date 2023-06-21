#include "types_main.h"
#include "character_select.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void character_select(fighter *list, player *player1, player *player2, bool ordi)
{
	int cpt=nb_fighters ; //number of available fighters
	int i,j,select;
	bool test;
    player1->defeated=false;
    player2->defeated=false;
	for (i=0;i<size_team;i++)
	{
		// player  selects a fighter
		test=true;
		while (test) {
		printf("\n Player %s : Choose the fighter among the above list of available fighters",player1->name);
		for (j=0;j<nb_fighters;j++)
			if (list[j].available==true) printf("\n %d. %s\n",j,list[j].name);
		scanf("%d",&select);
		if (list[select].available==false) 
			{
			printf("The fighter %d is not available ; try again",select);
			test=true;
			}	
		else test=false;
		};
		player1->team[i]=list[select] ; // create fighter for player 
		list[select].available=false;
		// player 2  selects a fighter
        // The second player is not a computer 
        if (!ordi){
		test=true;
		while (test) {
		printf("\n Player %s : Choose the fighter number among the above list of available fighters",player2->name);
		for (j=0;j<nb_fighters;j++)
			if (list[j].available==true) printf("\n %d. %s\n",j,list[j].name);
		scanf("%d",&select);
		if (list[select].available==false) 
			{
			printf("The fighter %d is not available ; try again",select);
			test=true;
			}	
		else test=false;
		};
		player2->team[i]=list[select] ; // create fighter for player 2 
		list[select].available=false;	
        }
        else //The second player is a computer
         {
            test=true;
             while (test) {
		select=rand()%(nb_fighters+1);
		if (list[select].available==false) 
			test=true;
		else test=false;
		};
		player2->team[i]=list[select] ; // create fighter for player 2 
		list[select].available=false;	



         }
	}
}