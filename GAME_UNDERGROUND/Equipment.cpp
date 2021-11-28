#include "Equipment.h"

std::string Equipment::getname() {
	switch (equip) {
	case(Helmet):
		return "Helmet";
		break;
	case(Gloves):
		return "Gloves";
		break;
	case(Ring):
		return "Ring";
		break;
	}
}