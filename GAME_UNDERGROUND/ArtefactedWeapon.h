#include "Tools.h"
#include "Artefact.h"
#include "Weapon.h"
#pragma once


class ArtefactedWeapon : public Weapon, public Artefact {
public:
	inline bool isArtefact() { return true; }
	//использует use, определенный в Weapon
	ArtefactedWeapon(WEAPON_NAME Name1, ARTEFACTED Name2,int val) :Weapon(Name1), Artefact(Name2, val) {};
	std::string getname() { return Artefact::get_feature() + " " + Weapon::getname(); }
};