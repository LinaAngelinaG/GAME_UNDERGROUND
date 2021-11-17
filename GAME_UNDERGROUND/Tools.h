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

	void set_name(std::string str) { name = str; }
	std::string get_name() { return name; }
	virtual int use(std::string) = 0;
	virtual bool isArtefact() = 0;
};

class Keys : public Tool {
private:
	int number_of_keys;
public:
	Keys(int n, std::string str) :number_of_keys(n), Tool(str) {};
	Keys() :number_of_keys(0),Tool("DEFALT_NAME_FOR_KEYS") {};

	int get_num_of_keys(){ return number_of_keys; }
	void set_num_of_keys(int n) { number_of_keys = n; }

	int use(std::string); //уменьшить кол-во ключей на 1

	inline bool isArtefact() { return false; }
};

class Artefact : virtual public Tool {
protected:
	std::map<std::string, int> changed_values;  //name of the characteristic and the value that it changes

public:
	
	void becomeUpToPower();
	void becomeUpToResistance();
	void becomeUpToAgility();
	inline bool isArtefact() { return true; }

	Artefact() :Tool("DEFALT_NAME_FOR_ARTEFACT") {};
	Artefact(std::string name) : Tool(name) {};

	//как повышать за счет артефактов первичные характеристики?
	//зачарованное оружие сразу даст скорректированный урон
	//нужна какая-то проверка на артефактность и получение мапы изменяемых величин
	std::map<std::string, int>& get_map() { return changed_values; }
	
};

class Potion : public Artefact {
public:
	Potion() :Artefact("DEFALT_NAME_FOR_POTION") {};
	Potion(std::string name) : Artefact(name) {};

	inline int use(std::string s) { return 0; }
};

class Equipment : virtual public Tool {
protected:
	int save;
	std::string type;

public:
	Equipment(int n) :Tool(EQUIPMENT_NAMES[n - 1]), save(n + 3), type(TYPE_EQ[n]) {};
	Equipment(int n, std::string name) :Tool(name), save(n + 3), type(TYPE_EQ[n]) {};

	int use(std::string); //возвращает величину защиты
	inline bool isArtefact() { return false; }
};

class Weapon: virtual public Tool {
protected:
	int damage;
public:
	int use(std::string); //возвращает величину урона

	Weapon(int n) :Tool(WEAPON_NAMES[n - 1]), damage(n + 7) {};
	Weapon(int n, std::string name) :Tool(name), damage(n + 7) {};

	inline bool isArtefact() { return false; }
};

class CharmedWeapon : public Weapon {
protected:
	bool charmes[4] = { false, false, false, false };
public:
	void becomeBurning();
	void becomeDrying();
	void becomeDamned();
	void becomeBlessed();

	CharmedWeapon(int n) :Weapon(n) {};
	CharmedWeapon(int n, std::string name) :Weapon(n, name) {};

	int use(std::string); //возвращает величину урона, использует массив charmes
};

class ArtefactedWeapon : public Weapon, public Artefact {
public:
	inline bool isArtefact() { return true; }
	//использует use, определенный в Weapon
	ArtefactedWeapon(int n) :Weapon(n), Artefact(WEAPON_NAMES[n - 1]) {};
	ArtefactedWeapon(int n, std::string name) :Weapon(n, name), Artefact(name){};
};

class ArtefactedCharmedWeapon : public CharmedWeapon, public Artefact {
public:
	inline bool isArtefact() { return true; }
	ArtefactedCharmedWeapon(int n) :CharmedWeapon(n), Artefact(WEAPON_NAMES[n - 1]) {};
	ArtefactedCharmedWeapon(int n, std::string name) :CharmedWeapon(n, name), Artefact(name) {};
};

class ArtefactedEquipment : public Equipment, public Artefact {
public:
	inline bool isArtefact() { return true; }
	ArtefactedEquipment(int n) :Equipment(n), Artefact(WEAPON_NAMES[n - 1]) {};
	ArtefactedEquipment(int n, std::string name) :Equipment(n, name), Artefact(name) {};
};