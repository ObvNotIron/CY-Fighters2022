#include <stdbool.h>

#define nb_stats 5	// defines the number of base stastics (hp,atk,def,speed) for each character (subject to change)
#define nb_fighters 6	// defines the number of playable fighters in the game
#define size_team 3


typedef struct		// structure containing base stats and infos for each character
{
	char name[256];
	float hp;	// if reaches 0, alive switches to false making the fighter unusable in combat
	float atk;	// the target's def is subtracted from base atk making damage points, this variable is then substracted from hp
	float def;	// damage reduction rate
	float speed;	// rate at wich energy builds up
	bool available;	// makes sure a character isn't selected twice (might be removed in the future)	// 
	float energy;	// fighters can perform actions once it reaches 100 and then resets to 0
	bool alive;	// switches to false when character's hp goes down to 0
    int nb_spe; // nb of special techniques used 
    int spe[]; // table of techniques number
} fighter; 

typedef struct
{
	char name[256];		// username for the player
	fighter team[size_team];	// points to array containing chosen fighters
    int token;	// granted every turn, used to perform attacks and various actions, an additionnal one is given if the fighter remains idle. 
    bool defeated; // boolean which indicates the defeat or not
} player;
