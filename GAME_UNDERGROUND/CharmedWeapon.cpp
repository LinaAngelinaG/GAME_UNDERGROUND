/**
\file CharmedWeapon.cpp
\brief File with some methods of the chamed weapon.
*/
#include "CharmedWeapon.h"

int CharmedWeapon::use(ENEMY name) {
	int base = Weapon::use(name);
	for (Container<CHARM>::ConstIterator it = charms.cbegin(); it != charms.cend(); ++it) {
		switch ((*it).key) {
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

std::string CharmedWeapon::get_charm() const{
	std::string s = "";
	for (Container<CHARM>::ConstIterator it = charms.cbegin(); it != charms.cend(); ++it) {
		switch ((*it).key) {
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