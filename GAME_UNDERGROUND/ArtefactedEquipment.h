#include "Tools.h"
#include "Artefact.h"
#include "Equipment.h"
#pragma once


class ArtefactedEquipment : public Equipment, public Artefact {
public:
	inline bool isArtefact() { return true; }
	ArtefactedEquipment(int n) :Artefact(), Equipment(n) {};
	ArtefactedEquipment(int n, std::string name) :Equipment(n, name), Artefact(name) {};
};