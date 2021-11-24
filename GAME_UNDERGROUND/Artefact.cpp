#include "Artefact.h"

void Artefact::becomeUpToPower(int n) {
	//changed_values.count("Power") == 0 ? changed_values.insert({ "Power",n }) : changed_values.at({ "Power",n });
	changed_values.insert({ "Power", n });
}

void Artefact::becomeUpToResistance(int n) {
	changed_values.insert({ "Resistance", n });
}

void Artefact::becomeUpToAgility(int n) {
	changed_values.insert({ "Agility", n });
}