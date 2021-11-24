#include <iostream>
#include "Tools.h"

class Equipment : virtual public Tool {
protected:
	int save;
	std::string type;

public:
	Equipment(int n) :Tool(EQUIPMENT_NAMES[n - 1]), save(n + 3), type(TYPE_EQ[n]) {};
	Equipment(int n, std::string name) :Tool(name), save(n + 3), type(TYPE_EQ[n]) {};

	inline bool isArtefact() { return false; }
	int use(std::string); //возвращает величину защиты
};