#include "Box.h"

bool Box::open(int agility ) {
	int prob_false = 99 - PROBABILITY[level - 1];
	int random = rand()%100 + agility%10;
	return random > prob_false;
}