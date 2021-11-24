#include "Equipment.h"

int Equipment::use(std::string enemy) {
	if (get_name() == EQUIPMENT_NAMES[0] || get_name() == EQUIPMENT_NAMES[2]) {
		return 2;
	}
	else if (get_name() == EQUIPMENT_NAMES[1]) {
		return 3;
	}
	else {
		return 1;
	}
}