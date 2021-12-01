#include "Tools.h"
#include <map>
#include <iostream>
#include "ENUMS.h"
#pragma once

class Artefact : virtual public Tool { //абстрактный класс
protected:
    //name of the characteristic and the value that it changes
	ARTEFACTED artefact = NONE;
	std::map<CHARACTERS, int> modification;
	int value = 0;
public:
	inline void becomeUpToPower(int n) { modification.insert({ Power,n }); }
	inline void becomeUpToResistance(int n) { modification.insert({ Resistance,n }); }
	inline void becomeUpToAgility(int n) { modification.insert({ Agility,n }); }

	inline bool isArtefact() { return true; }
	inline std::map<CHARACTERS, int> get_modif() const { return modification; }
	std::string get_feature() const;
	int get_feature_val(CHARACTERS) const;


	Artefact(CHARACTERS art, int n) { modification.insert({ art,n }); };
	//можно добавить создание по неограниченному кол-ву параметров

	//как повышать за счет артефактов первичные характеристики?
	//зачарованное оружие сразу даст скорректированный урон
	//нужна какая-то проверка на артефактность и получение мапы изменяемых величин
};