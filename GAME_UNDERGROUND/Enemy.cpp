#include "Enemy.h"

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