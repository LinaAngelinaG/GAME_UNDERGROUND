#include "Weapon.h"

std::string Weapon::getname() {
	switch (name) {
	case(Sword):
		return "Sword";
		break;
	case(Axe):
		return "Axe";
		break;
	case(Baton):
		return "Baton";
		break;
	}
}