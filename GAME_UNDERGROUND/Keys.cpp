#include "Keys.h"

int Keys::use(ENEMY name) {
	int prob_false = 99 - rand() % 20;
	int random = rand() % 100;
	if (random > prob_false) { //при таком условии ключ ломается
		number_of_keys--;
	}
	return 0;
}