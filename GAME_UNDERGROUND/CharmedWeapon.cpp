#include "CharmedWeapon.h"

int CharmedWeapon::use(std::string name) {
	int base = damage;
	if (name.compare(ENEMY_NAMES[0])==0 && get_charm(0)) {
		base += 1;
	}
	else if (name.compare(ENEMY_NAMES[1]) == 0 && get_charm(1)) {
		base += 1;
	}
	else if (name.compare(ENEMY_NAMES[2]) == 0 && get_charm(2)) {
		base += 2;
	}
	else if (name.compare(ENEMY_NAMES[3]) == 0 && get_charm(3)) {
		base += 1;
	}
	return base;
}
