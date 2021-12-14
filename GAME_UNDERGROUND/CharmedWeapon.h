#include "Tools.h"
#include "Weapon.h"
#include "ENUMS.h"
#include "Container.h"
#pragma once


class CharmedWeapon : public Weapon {
protected:
	CHARM charm;
	//std::map<CHARM, int> charms;
	typedef Container<CHARM> Charms;
	Charms charms;
public:
	std::string get_charm() const;

	inline void becomeCharmed(CHARM charm ,int n) { charms.insert(charm, n ); }

	CharmedWeapon(WEAPON_NAME Name, CHARM Charm, int n) :Weapon(Name) { charms.insert( Charm, n > 0 ? n : 0 ); };
	CharmedWeapon(WEAPON_NAME Name, CHARM Charm) :Weapon(Name) { charms.insert( Charm, Charm ); };

	virtual int use(ENEMY); //возвращает величину урона, использует charmes

	inline Charms& get_charms() { return charms; }
	//inline std::map<CHARM, int> get_charms() { return charms; }
	inline virtual std::string getname() { return get_charm() + " " + Weapon::getname();}
};