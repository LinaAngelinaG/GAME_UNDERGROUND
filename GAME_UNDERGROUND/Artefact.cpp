#include "Artefact.h"
#include <iostream>

/*std::string Artefact:: get_feature() {
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
}*/


std::string Artefact::get_feature()const {
	std::string s = "";

	for (std::map<CHARACTERS, int>::const_iterator it = modification.cbegin(); it != modification.cend(); ++it) {
		switch ((*it).first) {
		case(Power):
			s = s + "POWERUP"+" ";
			break;
		case(Resistance):
			s = s  + "RESISUP" + " ";
			break;
		case(Agility):
			s = s + "AGILITYUP" + " ";
			break;
		case(Health):
			s = s  + "HEALTHUP" + " ";
			break;
		case(Cur_health):
			s = s + "CURHEALTHUP" + " ";
			break;
		}
	}
	if (s == "")
		return "NoneUp";
	s = s.substr(0, s.length() - 1);
	return s;
}

int Artefact::get_feature_val(CHARACTERS character)const {
	try {
		return modification.at(character);
	}
	catch (_exception ex) {
		return 0;
	}
}
