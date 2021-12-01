#include "Table.h"

Table::Table() {
	n = 5;

	info power = { POWER, 1 };
	table.insert({ Power, power });

	info health = { HEALTH, 10 };
	table.insert({ Health, health });

	info cur_health = { CURRENT_HEALTH, 10 };
	table.insert({ Cur_health, cur_health });

	info agility = { AGILITY, 1 };
	table.insert({ Agility, agility });

	info resistance = { RESISTANCE, 1 };
	table.insert({ Resistance, resistance });
}