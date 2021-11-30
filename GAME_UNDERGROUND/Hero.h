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
	std::map <TYPE, Equipment*> equipment;
	std::map <int, Potion&> potions;
	int potion_val = 0;
	int max_potion = 3;
	int keys = 0;

	Table* parameters = nullptr;

public:
	inline void set_weapon(Weapon& w) { weapon = &w; }
	inline void set_table(Table& t) { parameters = &t; }
	inline void set_experince(int n) { experience = n; }
	inline void set_max_potion(int n) { max_potion = n; }
	inline void set_keys(int n) { keys = n; }

	void set_equipment(Equipment& equip){equipment.insert({ equip.get_type(), &equip });}
	void set_potion(Potion&);
	
	Hero() {};
	Hero(Weapon& w) :weapon(&w) {};
	Hero(Equipment& eq) { set_equipment(eq); }

	inline Weapon& get_weapon() { return *weapon; }
	inline Table& get_table() { return *parameters; }
	inline int get_experince() { return experience; }
	inline int get_max_potion() { return max_potion; }
	inline int get_keys() { return keys; }

	const Potion* get_potion(int);
	
	const Equipment* get_equipment(TYPE);
	inline int generate_damage(ENEMY enemy) { return weapon->use(enemy); }  //сгенерировать урон на основании всей экип-ки и бонусов
	void gain_damage(int); //получить урон с учетом защиты
	void drink_potion(int); //выпить зелье под номером
	void upgrate_param(CHARACTERS);
	/*
	void take_tool(Tool&); //взять предмет
	*/
};