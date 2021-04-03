#include "Labyrinth.h"
#include <iostream>

bool isPathToFreedom(MazeCell* start, const std::string& moves) {
	bool spellbook = false;
	bool wand = false;
	bool potion = false;
	
    for(int i = 0; i < moves.size(); i++)
	{
	    if(moves[i] == 'S')
		{
			start = start->south;
		}
		else if(moves[i] == 'E')
		{
			start = start->east;
		}
		else if(moves[i] == 'N')
		{
			start = start->north;
		}
		else if(moves[i] == 'W')
		{
			start = start->west;
		}
		if(start == nullptr)
		{
			return false;
		}
		if(start->whatsHere == Item::SPELLBOOK)
		{
			spellbook = true;
		}
		else if(start->whatsHere == Item::WAND)
		{
			wand = true;
		}
		else if(start->whatsHere == Item::POTION)
		{
			potion = true;
		}
	}
	if(spellbook && wand && potion)
	{
		return true;
	}
    return false;
}
