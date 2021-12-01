#include "CharmedWeapon.h"

int CharmedWeapon::use(ENEMY name) {
	int base = Weapon::use(name);
	for (std::map<CHARM, int>::iterator it = charms.begin(); it != charms.end(); ++it) {
		switch ((*it).first) {
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
	}
	return base;
}

std::string CharmedWeapon::get_charm() {
	/*switch (charm) {
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
	}*/
	std::string s = "";
	for (std::map<CHARM, int>::iterator it = charms.begin(); it != charms.end(); ++it) {
		switch ((*it).first) {
		case(Damned):
			s = s + "Damned" + " ";
			break;
		case(Burning):
			s = s + "Burning" + " ";
			break;
		case(Blessed):
			s = s + "Blessed" + " ";
			break;
		case(Drying):
			s = s + "Drying" + " ";
			break;
		}
	}
	if (s == "")
		return "NoneUp";
	s = s.substr(0, s.length() - 1);
	return s;
}