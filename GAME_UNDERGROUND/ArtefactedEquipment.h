#include "Tools.h"
#include "Artefact.h"
#include "Equipment.h"

class ArtefactedEquipment : public Equipment, public Artefact {
public:
	inline bool isArtefact() { return true; }
	ArtefactedEquipment(int n) :Equipment(n), Artefact(WEAPON_NAMES[n - 1]) {};
	ArtefactedEquipment(int n, std::string name) :Equipment(n, name), Artefact(name) {};
};