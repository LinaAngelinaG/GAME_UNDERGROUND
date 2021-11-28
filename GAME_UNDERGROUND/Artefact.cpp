#include "Artefact.h"
#include <iostream>

std::string Artefact:: get_feature() {
	switch (artefact) {
	case(POWERUP):
		return "POWERUP";
		break;
	case(RESISTANCEUP):
		return "RESISTANCEUP";
		break;
	case(AGILITYUP):
		return "AGILITYUP";
		break;
	case(NONE):
		return "NONEUP";
		break;
	}
}