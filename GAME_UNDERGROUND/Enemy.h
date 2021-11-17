#include <iostream>
#include "Tools.h"
std::string ENEMY_NAMES[4] = { "Humanlikely", "Witch", "Demon", "Slug" };
int CHAR[4][3] = { {1,10,1}, {2, 12,2} , {5, 15,4}, {1,18,1} };
class Enemy
{
private:
	std::string name;
	int power;
	int health;
	int outcomes = 0;
	int cur_health;
	int experience;
	Tool* tool;
public:
	Enemy(int n) :power(CHAR[n][0]), name(ENEMY_NAMES[n]), health(CHAR[n][1]), cur_health(CHAR[n][1]), experience(CHAR[n][2]){}; //добавить настройку предмета
	Enemy(int n, std::string s) :power(CHAR[n][0]), name(s), health(CHAR[n][1]), cur_health(CHAR[n][1]), experience(CHAR[n][2]) {}; //добавить настройку предмета
	
	inline void harm(int n) { cur_health -= n;} //получить от врага
	inline int attack() { outcomes++; return power; } //атаковать

	inline void set_power(int n) { power = n; }
	inline void set_health(int n) { health = n; }
	inline void set_experince(int n) { experience = n; }
	inline void set_name(std::string s) { name = s; }
	inline void set_tool(Tool* t) { tool = t; }

	inline int get_power() { return power; }
	inline int get_health() { return health; }
	inline int get_experince() { return experience; }
	inline std::string get_name() { return name; }
	inline Tool& get_tool() { return *tool; }
};
