#include <iostream>
#include "Tools.h"
#pragma once

static std::string EQUIPMENT_NAMES[3] = { "Helmet","Gloves", "Ring" };
static std::string TYPE_EQ[3] = { "Head", "Hands", "Finger" };

class Equipment : virtual public Tool {
protected:
	int save;
	std::string type;

public:
	Equipment(int n) :Tool(EQUIPMENT_NAMES[n - 1]), save(n + 3), type(TYPE_EQ[n]) {};
	Equipment(int n, std::string name) :Tool(name), save(n + 3), type(TYPE_EQ[n]) {};

	inline bool isArtefact() { return false; }
	inline int use(std::string) { return save; }; //возвращает величину защиты
};