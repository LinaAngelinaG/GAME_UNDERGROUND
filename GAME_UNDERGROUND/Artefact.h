#include "Tools.h"
#include <map>
#include <iostream>
#include "Container.h"
#include "ENUMS.h"
#pragma once

class Artefact : virtual public Tool{ //абстрактный класс
protected:
	//typedef std::map<CHARACTERS, int> modificate;
    //name of the characteristic and the value that it changes
	typedef Container<CHARACTERS> Modificate;
	Modificate modification;
	int value = 0;
public:
	inline void becomeUpTo(CHARACTERS character, int n) { modification.insert(character ,n);}

	inline bool isArtefact() { return true; }
	inline const Modificate & get_modif() const { return modification; }
	std::string get_feature() const;
	int get_feature_val(CHARACTERS) const;
	
	Artefact(CHARACTERS art, int n) { modification.insert(art, n); }
	//~Artefact() { delete &modification; }
	//можно добавить создание по неограниченному кол-ву параметров

	//как повышать за счет артефактов первичные характеристики?
	//зачарованное оружие сразу даст скорректированный урон
	//нужна какая-то проверка на артефактность и получение мапы изменяемых величин
};