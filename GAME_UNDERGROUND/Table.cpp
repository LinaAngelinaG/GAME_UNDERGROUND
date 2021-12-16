/**
\file Table.cpp
\brief File with some methods of the table.
*/
#include "Table.h"

/**
	Constructor of the Table: sets some basic values of parameters.
	*/
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

/**
	Destructor of the Table: delete the parameters from the table.
	*/
Table::~Table() {
	for (std::map<CHARACTERS, info&>::iterator it = table.begin(); it != table.end(); ++it) {
		delete[] &(*it).second;
	}
}

/**
	Lets to set the value for the exact characteristics of the hero.
	\param Enum CHARACTERS characteristic and its Integer value.
	\return Nothing.
	*/
void Table::set_val_of_param(CHARACTERS charact, int val) {
	for (std::map<CHARACTERS, info&>::iterator it = table.begin(); it != table.end(); ++it) {
		if ((*it).first == charact) {
			(*it).second.value = val;
			break;
		}
	}
}