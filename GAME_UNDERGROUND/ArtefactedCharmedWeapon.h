#include "Tools.h"
#include "Artefact.h"
#include "CharmedWeapon.h"
#pragma once


class ArtefactedCharmedWeapon : public CharmedWeapon, public Artefact {
public:
	inline bool isArtefact() { return true; }
	ArtefactedCharmedWeapon(int n) :CharmedWeapon(n), Artefact(WEAPON_NAMES[n - 1]) {};
	ArtefactedCharmedWeapon(int n, std::string name) :CharmedWeapon(n, name), Artefact(name) {};
};