#include "CharmedWeapon.h"

int CharmedWeapon::use(ENEMY name) {
	int base = Weapon::use(name);

	switch (charm) {
	case(Damned):
		if (name == Humanlikely) {
			return base + 1;
		}
		break;
	case(Burning):
		if (name == Witch) {
			return base + 1;
		}
		break;
	case(Blessed):
		if (name == Demon) {
			return base + 2;
		}
		break;
	case(Drying):
		if (name == Slug) {
			return base + 1;
		}
		break;
	}
	return base;
}

std::string CharmedWeapon::get_charm() {
	switch (charm) {
	case(Damned):
		return "Damned";
		break;
	case(Burning):
		return "Burning";
		break;
	case(Blessed):
		return "Blessed";
		break;
	case(Drying):
		return "Drying";
		break;
	}
}