#include "Tools.h"
#pragma once

static std::string WEAPON_NAMES[3] = { "Sword","Axe", "Baton" };

class Weapon : virtual public Tool {
protected:
	int damage;
public:
	inline int use(std::string) { return damage; }   //���������� �������� �����

	Weapon(int n) :Tool(WEAPON_NAMES[n - 1]), damage(n + 7) {};
	Weapon(int n, std::string name) :Tool(name), damage(n + 7) {};

	inline bool isArtefact() { return false; }
};