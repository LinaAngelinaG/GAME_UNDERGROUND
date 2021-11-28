#include "Tools.h"
#include "Artefact.h"
#include "CharmedWeapon.h"
#pragma once

class ArtefactedCharmedWeapon : public CharmedWeapon, public Artefact {
public:
	inline bool isArtefact() { return true;}
	ArtefactedCharmedWeapon(WEAPON_NAME Name1, CHARM Name2, ARTEFACTED Name3, int val) :CharmedWeapon(Name1, Name2), Artefact(Name3, val) {};
	//ArtefactedCharmedWeapon() :CharmedWeapon() { /*name = Name;*/ };
	inline virtual std::string getname() { return get_feature() + " " + CharmedWeapon::getname(); }
	inline virtual int use(ENEMY enemy) { return CharmedWeapon::use(enemy); }
};