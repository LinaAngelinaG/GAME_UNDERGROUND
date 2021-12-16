/**
\file Keys.cpp
\brief File with some functions of the keys.
*/
#include "Keys.h"

/**
	Give a chance to open the box. Can be broken at all with special possibility.
	\param Enum ENEMY name.
	\return Always returns 0.
	*/
int Keys::use(ENEMY name) {
	int prob_false = 99 - rand() % 20;
	int random = rand() % 100;
	if (random > prob_false) {
		number_of_keys--;
	}
	return 0;
}