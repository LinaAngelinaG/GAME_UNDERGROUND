/**
\file Enemy.h
\brief Header-file with a description of the enemy.
Subclass for the class Object.
*/
#include <iostream>
#include "ENUMS.h"
#include "Tools.h"
#pragma once

/**
 *  \brief     Class that desribes enemies.
 *  \details   Contains the name of the enemy, its power, health, current_health, experience, the amount outcomes and the pointer of the tool tha the enemy holds.
 *  \details   Builds with the name of the enemy, other basic parameters are declared for each enemy, but you can change it.
 *  \author    LinaAngelinaG
 *  \date      15.12.2021
 */
class Enemy: virtual public Object{
private:
	ENEMY name;
	int power;
	int health; int cur_health;
	int experience;
	int outcomes = 0;
	Tool* tool = nullptr;
public:

	/** Builds with the name of the enemy, other basic parameters are declared for each enemy, but you can change it.
	*/
	Enemy(ENEMY Name) :power(Name -9), name(Name), health(Name), cur_health(Name), experience(Name-9) {};

	/**
	Allows to gain the damage from the hero.
	\param Integer value of the damage.
	\return Nothing.
	*/
	inline void harm(int n) { cur_health -= n;} 

	/**
	Allows to attack the hero.
	\param No arguments.
	\return Integer value of the damage.
	*/
	inline int attack() { outcomes++; return power; } //атаковать

	/**
	Allows to set the power.
	\param Integer value of the power.
	\return Nothing.
	*/
	inline void set_power(int n) { power = n; }

	/**
	Allows to set the health.
	\param Integer value of the health.
	\return Nothing.
	*/
	inline void set_health(int n) { health = n; }

	/**
	Allows to set the experience.
	\param Integer value of the experience.
	\return Nothing.
	*/
	inline void set_experince(int n) { experience = n; }

	/**
	Allows to set the name.
	\param The enum ENEMY name.
	\return Nothing.
	*/
	inline void set_name(ENEMY Name) { name = Name; }

	/**
	Allows to set the tool that the enemy holds.
	\param The pointer to the tool.
	\return Nothing.
	*/
	inline void set_tool(Tool* t) { tool = t; }

	/**
	Allows to get the power.
	\param No arguments.
	\return Ineteger value of the power.
	*/
	inline int get_power() { return power; }

	/**
	Allows to get the health.
	\param No arguments.
	\return Ineteger value of the health.
	*/
	inline int get_health() { return health; }

	/**
	Allows to get the cur_health.
	\param No arguments.
	\return Ineteger value of the cur_health.
	*/
	inline int get_cur_health() { return cur_health; }

	/**
	Allows to get the experience.
	\param No arguments.
	\return Ineteger value of the experience.
	*/
	inline int get_experince() { return experience; }

	/**
	Allows to get the amount outcomes.
	\param No arguments.
	\return Ineteger amount of the outcomes.
	*/
	inline int get_outcomes() { return outcomes; }

	std::string get_name();

	/**
	Allows to get the tool that the enemy holds.
	\param No arguments.
	\return The tool's reference.
	*/
	inline Tool& get_tool() { return *tool; }

	/**
	Allows to get the type of the enemy.
	\param No arguments.
	\return Enum ENEMY value of the name.
	*/
	inline ENEMY get_type_enemy() { return name; }

	/**
	Allows to get the type of the object.
	\param No arguments.
	\return Always return enum objectType with the value 'enemy'.
	*/
	inline objectType getObjectType() override { return enemy; };
};
