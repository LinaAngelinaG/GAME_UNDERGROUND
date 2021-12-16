/**
\file Weapon.cpp
\brief File with some functions of the weapon.
*/
#include "Weapon.h"

/**
Allows to get the full name of the weapon.
\param No arguments.
\return String full name.
*/
std::string Weapon::getname() {
	switch (name) {
	case(Sword):
		return "Sword";
		break;
	case(Axe):
		return "Axe";
		break;
	case(Baton):
		return "Baton";
		break;
	}
}