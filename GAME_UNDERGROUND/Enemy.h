#include <iostream>
#include "ENUMS.h"
#include "Tools.h"
#pragma once

class Enemy
{
private:
	ENEMY name;
	int power;
	int health; int cur_health;
	int experience;
	int outcomes = 0;
	Tool* tool = nullptr;
public:
	Enemy(ENEMY Name) :power(Name -9), name(Name), health(Name), cur_health(Name), experience(Name-9) {}; //добавить настройку предмета


	inline void harm(int n) { cur_health -= n;} //получить от врага
	inline int attack() { outcomes++; return power; } //атаковать

	inline void set_power(int n) { power = n; }
	inline void set_health(int n) { health = n; }
	inline void set_experince(int n) { experience = n; }
	inline void set_name(ENEMY Name) { name = Name; }
	inline void set_tool(Tool* t) { tool = t; }

	inline int get_power() { return power; }
	inline int get_health() { return health; }
	inline int get_cur_health() { return cur_health; }
	inline int get_experince() { return experience; }
	inline int get_outcomes() { return outcomes; }
	std::string get_name();
	inline Tool& get_tool() { return *tool; }
};
