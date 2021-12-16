/**
\file Box.cpp
\brief File with some methods of the Box.
*/

#include "Box.h"

/**
	Give a chance to open the box(the probability of this action depends on the level of the box mostly).
	\param Integer value of the hero's agility.
	\return The result of an opening attemp.
	*/
bool Box::open(int agility ) { 
	/// method allows open the box with the exact probability that depends on the box level
	/// uses agility of hero as a parameter
	int prob_false = 99 - level;
	int random = rand()%100 + agility%10;
	return random > prob_false;
}