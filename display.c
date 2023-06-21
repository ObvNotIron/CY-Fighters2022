#include "display.h"
#include <stdio.h>
//#include <stdbool.h>

void display_fighter_list(fighter *list, int list_size) // displays infos for all fighters in the game
{
	int i;
	for (i=0;i<list_size;i++)
	{
		display_fighter(list,i); // i defines the element in list
	}
}

void display_fighter(fighter *list, int i)	// displays infos for a single fighter structure
{
	printf("\n----------------------------------------------------------------------------------------------------\n");
	printf(" %s \n",(*(list+i)).name);
	printf("hp : %d \n",(int)(*(list+i)).hp);
	printf("atk : %d \n",(int)(*(list+i)).atk);
	printf("def : %f \n",(*(list+i)).def);
	printf("speed : %d \n",(int)(*(list+i)).speed);
	printf("----------------------------------------------------------------------------------------------------\n");

}

void display_team(player a_player)
{
int i;	
printf("The %d fighters of player %s are: \n",size_team,a_player.name);
for(i=0;i<size_team;i++)
{
	printf("\n%d : %s\n",i,a_player.team[i].name);
    printf("\n%d : %i\n",i,a_player.team[i].alive);
     printf("\n%d : %f\n",i,a_player.team[i].hp);

} 
}

