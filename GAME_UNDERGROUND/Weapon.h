#include "Tools.h"
#include "ENUMS.h"
#pragma once

class Weapon : virtual public Tool {
protected:
	WEAPON_NAME name;

public:
	inline virtual int use(ENEMY Name) { return name; }   //возвращает величину урона

	Weapon(WEAPON_NAME Name) : name(Name) { Tool::type_of_obj = "weapon"; };
	~Weapon() = default;

	virtual std::string getname();
	inline bool isArtefact() { return false; }
};