#include "Tools.h"
#include "Artefact.h"
#include "Equipment.h"
#pragma once


class ArtefactedEquipment : public Equipment, public Artefact {
public:
	inline bool isArtefact() { return true; }
	ArtefactedEquipment(EQUIPMENT Name1, ARTEFACTED Name2, int val) :Equipment(Name1), Artefact(Name2, val) {};
	virtual std::string getname() { return get_feature() + " " + Equipment::getname(); }
};