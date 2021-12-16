/**
\file Enemy.cpp
\brief File with some methods of the enemy.
*/
#include "Enemy.h"

/**
	Lets to get the full name of the enemy.
	\param No arguments.
	\return String full name.
	*/
std::string Enemy::get_name() {
	switch (name) {
	case(Humanlikely):
		return "Humanlikely";
		break;
	case(Witch):
		return "Witch";
		break;
	case(Demon):
		return "Demon";
		break;
	case(Slug):
		return "Slug";
		break;
	}
}