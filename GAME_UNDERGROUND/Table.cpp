#include "Table.h"

Table::Table() {
	n = 5;

	info* power = new info{ POWER, 1 };
	table.insert({ Power, *power });

	info* health = new info { HEALTH, 10 };
	table.insert({ Health, *health });

	info* cur_health = new info { CURRENT_HEALTH, 10 };
	table.insert({ Cur_health, *cur_health });

	info* agility = new info{ AGILITY, 1 };
	table.insert({ Agility, *agility });

	info* resistance = new info{ RESISTANCE, 1 };
	table.insert({ Resistance, *resistance });
}

Table::~Table() {
	for (std::map<CHARACTERS, info&>::iterator it = table.begin(); it != table.end(); ++it) {
		delete[] &(*it).second;
	}
}

void Table::set_val_of_param(CHARACTERS charact, int val) {
	for (std::map<CHARACTERS, info&>::iterator it = table.begin(); it != table.end(); ++it) {
		if ((*it).first == charact) {
			(*it).second.value = val;
			break;
		}
	}
}