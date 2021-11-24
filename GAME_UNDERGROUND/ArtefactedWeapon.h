#include "Tools.h"
#include "Artefact.h"
#include "Weapon.h"
#pragma once


class ArtefactedWeapon : public Weapon, public Artefact {
public:
	inline bool isArtefact() { return true; }
	//использует use, определенный в Weapon
	ArtefactedWeapon(int n) :Weapon(n), Artefact(WEAPON_NAMES[n - 1]) {};
	ArtefactedWeapon(int n, std::string name) :Weapon(n, name), Artefact(name) {};
};