#include <iostream>
#include "Table.h"
#include "Tools.h"

class Hero {
private:
	int experience;
	Table* parameters;
	Weapon* weapon;
	std::map<std::string, Equipment&> equipment;
	Potion* potions;
	int max_potion;
	int keys;

public:
	inline void set_weapon(Weapon* w) { weapon = w; }
	inline void set_table(Table* t) { parameters = t; }
	inline void set_experince(int n) { experience = n; }
	inline void set_max_potion(int n) { max_potion = n; }
	inline void set_keys(int n) { keys = n; }
	void set_equipment(std::map<std::string, Equipment&>&);
	void set_potion(Potion*);
	Hero();


	inline Weapon& get_weapon() { return *weapon; }
	inline Table& get_table() { return *parameters; }
	inline int get_experince() { return experience; }
	inline int get_max_potion() { return max_potion; }
	inline int get_keys() { return keys; }
	inline std::map<std::string, Equipment&>& get_equipment() { return equipment; }
	inline Potion& get_potion() { return *potions; }

	void take_tool(Tool*); //взять предмет
	void drink_potion(int); //выпить зелье под номером
	int generate_damage();  //сгенерировать урон на основании всей экип-ки и бонусов
	void gain_damage(int); //получить урон с учетом защиты
	void upgrate_param(std::string); //улучшить характеристику(по короткому имени) за счет уменьшения опыта
};