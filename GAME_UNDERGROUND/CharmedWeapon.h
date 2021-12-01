#include "Tools.h"
#include "Weapon.h"
#include "ENUMS.h"
#pragma once


class CharmedWeapon : public Weapon {
protected:
	CHARM charm;
	std::map<CHARM, int> charms;
public:
	std::string get_charm();
	
	inline void becomeDamned(int n) { charms.insert({ Damned, n }); }
	inline void becomeBurning(int n) { charms.insert({ Burning, n }); }    //ведьм у нас сжигают)
	inline void becomeBlessed(int n) { charms.insert({ Blessed, n }); }
	inline void becomeDrying(int n) { charms.insert({ Drying, n }); }

	CharmedWeapon(WEAPON_NAME Name, CHARM Charm, int n) :Weapon(Name) { charms.insert({ Charm, n > 0 ? n : 0 }); };
	CharmedWeapon(WEAPON_NAME Name, CHARM Charm) :Weapon(Name) { charms.insert({ Charm, Charm }); };

	virtual int use(ENEMY); //возвращает величину урона, использует charmes

	inline std::map<CHARM, int> get_charms() { return charms; }
	inline virtual std::string getname() { return get_charm() + " " + Weapon::getname();}
};