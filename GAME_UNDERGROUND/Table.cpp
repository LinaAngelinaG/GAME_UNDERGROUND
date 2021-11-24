#include "Table.h"

Table::Table() {
	n = 5;
	info power = { "Power in points", 1 };
	table.insert({ "Power", power });
	info health = { "Health in points", 10 };
	table.insert({ "Health", health });
	info cur_health = { "Current health in points", 10 };
	table.insert({ "CurrentHealth", cur_health });
	info agility = { "Agility in points", 1 };
	table.insert({ "Agility", agility });
	info resistance = { "Resistance in points", 1 };
	table.insert({ "Resistance", resistance });
}