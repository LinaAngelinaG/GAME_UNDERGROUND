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
	std::map <int, Potion&> potions;          // todo:: make as a list
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
	
	Hero(Table& tab) :parameters(&tab) {};
	Hero(Weapon& w, Table& tab) :weapon(&w), parameters(&tab) {};
	Hero(Equipment& eq, Table& tab):parameters(&tab) { set_equipment(eq); }

	inline const Weapon& get_weapon() const { return *weapon; }
	inline const Table& get_table() const{ return *parameters; } 
	inline int get_experince() const { return experience; }
	inline int get_max_potion() const { return max_potion; }
	inline int get_keys() const { return keys; }
	inline int get_potion_val() const { return potion_val; }

	const Potion* get_potion(int) const;
	
	const Equipment* get_equipment(TYPE) const;

	inline int generate_damage(ENEMY enemy) const { return weapon->use(enemy); }  //������������� ���� �� ��������� ���� ����-�� � �������
	void gain_damage(int); //�������� ���� � ������ ������ 
	void drink_potion(int); //������ ����� ��� ������� //---
	void upgrate_param(CHARACTERS);

	void take_tool(Tool&); //����� �������
};