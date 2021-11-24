#include <iostream>
#include <map>

std::string WEAPON_NAMES[3] = { "Sword","Axe", "Baton" };
std::string EQUIPMENT_NAMES[3] = { "Helmet","Gloves", "Ring" };
std::string TYPE_EQ[3] = { "Head", "Hands", "Finger" };

class Tool {
protected:
	std::string name;
public:
	Tool() :name("DEFALTE_NAME") {};
	Tool(std::string str) :name(str) {};

	inline void set_name(std::string str) { name = str; }
	inline std::string get_name() { return name; }

	virtual int use(std::string) = 0;
	virtual bool isArtefact() = 0;
};