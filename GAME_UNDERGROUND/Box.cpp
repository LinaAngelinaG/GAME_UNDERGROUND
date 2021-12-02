#include "Box.h"

bool Box::open(int agility ) { 
	/// method allows open the box with the exact probability that depends on the box level
	/// uses agility of hero as a parameter
	int prob_false = 99 - PROBABILITY[level - 1];
	int random = rand()%100 + agility%10;
	return random > prob_false;
}