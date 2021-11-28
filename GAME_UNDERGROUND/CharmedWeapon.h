#include "Tools.h"
#include "Weapon.h"
#include "ENUMS.h"
#pragma once


class CharmedWeapon : public Weapon {
protected:
	CHARM charm;
public:
	std::string get_charm();
	
	inline void becomeDamned() { charm = Damned; }
	inline void becomeBurning() { charm = Burning; }    //����� � ��� �������)
	inline void becomeBlessed() { charm = Blessed; }
	inline void becomeDrying() { charm = Drying; }

	//CharmedWeapon(WEAPON_NAME Name) :Weapon(Name) {  };

	CharmedWeapon(WEAPON_NAME Name, CHARM Charm) :Weapon(Name),charm(Charm) {};

	virtual int use(ENEMY); //���������� �������� �����, ���������� charmes
	
	inline virtual std::string getname() { return get_charm() + " " + Weapon::getname();}
};