#include "display.h"
#include <stdio.h>
#include <string.h>
fighter *get_fighters() // gets info from multiple txt files and creates an array of fighter structures
{
	FILE* fighter_info = NULL;
	float stat;
	int i,j;
	fighter *list = NULL;	// pointer to array containing all fighters, returned by function
	list = malloc(nb_fighters*sizeof(fighter));
	for (i=0;i<nb_fighters;i++)
	{
		char source[256];	// file path
		sprintf(source,"fighters/fighter %d",(i+1)); // txt files for fighters are name "fighter + a number"
		fighter_info = fopen(source,"r");
		//char name[256];		// name of the fighter
		int *p = NULL;
		p = calloc(nb_stats, sizeof(float));	// temporarily stores stats to be assigned to the correct fighter structure
		if (fighter_info != NULL)
		{
			fscanf(fighter_info,"%s",list[i].name);		// gets name
			//strncpy(list[i].name,name,strlen(name));  // asigns name to fighter
			for (j=0;j<nb_stats;j++)
			{
				fscanf(fighter_info,"%f",&stat);
				*(p+j) = stat;
			}
			list[i].hp = *p;
			list[i].atk = *(p+1);
			list[i].def = *(p+2);
			list[i].speed = *(p+3);
			list[i].available = true;
			//printf("%f \n",list[j].hp);
		}
		//printf("%f \n",list[1].hp);
		free(p);
	}
	fclose(fighter_info);
	//printf("%f \n",list[0].hp);
	return list;
}
