#include "Tools.h"
#include <iostream>

class Artefact : virtual public Tool {
protected:
	std::map<std::string, int> changed_values;  //name of the characteristic and the value that it changes

public:

	void becomeUpToPower(int);
	void becomeUpToResistance(int);
	void becomeUpToAgility(int);

	inline bool isArtefact(int) { return true; }
	inline std::map<std::string, int>& get_map() { return changed_values; }

	Artefact() :Tool("DEFALT_NAME_FOR_ARTEFACT") {};
	Artefact(std::string name) : Tool(name) {};

	//как повышать за счет артефактов первичные характеристики?
	//зачарованное оружие сразу даст скорректированный урон
	//нужна какая-то проверка на артефактность и получение мапы изменяемых величин
};