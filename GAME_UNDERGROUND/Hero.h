#include <iostream>
#include "Table.h"
#include "Tools.h"
#include "Equipment.h"
#include "Potion.h"
#include "Weapon.h"
#pragma once

class Hero {
private:
	int experience = 0;
	Weapon* weapon = nullptr;
	std::map <TYPE, EQUIPMENT*> equipment;
	Potion** potions = nullptr;
	int max_potion = 3;
	int keys = 0;

	Table* parameters;

public:
	inline void set_weapon(Weapon* w) { weapon = w; }
	inline void set_table(Table* t) { parameters = t; }
	inline void set_experince(int n) { experience = n; }
	inline void set_max_potion(int n) { max_potion = n; }
	inline void set_keys(int n) { keys = n; }

	void set_equipment(std::map<std::string, Equipment*>&);
	void set_potion(Potion*);
	
	Hero();
	Hero(Weapon* w) :weapon(w);
	Hero(Equipment* eq) { set_equipment(eq); }

	inline Weapon& get_weapon() { return *weapon; }
	inline Table& get_table() { return *parameters; }
	inline int get_experince() { return experience; }
	inline int get_max_potion() { return max_potion; }
	inline int get_keys() { return keys; }
	inline Potion& get_potion(int n) { return **(potions+n); }

	Equipment& get_equipment(TYPE);
	void take_tool(Tool*); //взять предмет
	void drink_potion(int); //выпить зелье под номером
	int generate_damage();  //сгенерировать урон на основании всей экип-ки и бонусов
	void gain_damage(int); //получить урон с учетом защиты
	void upgrate_param(std::string); //улучшить характеристику(по короткому имени) за счет уменьшения опыта
};