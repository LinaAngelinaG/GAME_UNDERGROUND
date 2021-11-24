#include "Tools.h"
#include "Weapon.h"
#include "Enemy.h"
#pragma once

class CharmedWeapon : public Weapon {
protected:
	bool charmes[4] = { false, false, false, false };
public:
	inline bool get_charm(int n) { return charmes[n % 4]; }
	
	inline void becomeDamned() { charmes[0] = true; }
	inline void becomeBurning() { charmes[1] = true; } //ведьм у нас сжигают
	inline void becomeBlessed() { charmes[2] = true; }
	inline void becomeDrying() { charmes[3] = true; }

	CharmedWeapon(int n) :Weapon(n) {};
	CharmedWeapon(int n, std::string name) :Weapon(n, name) {};

	int use(std::string); //возвращает величину урона, использует массив charmes
};