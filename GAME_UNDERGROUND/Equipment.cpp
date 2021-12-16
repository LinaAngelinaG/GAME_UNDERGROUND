/**
\file Equipment.cpp
\brief File with some functions of the equipment.
*/
#include "Equipment.h"

/**
Allows to get the full name of the equipment.
\param No arguments.
\return String full name.
*/
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