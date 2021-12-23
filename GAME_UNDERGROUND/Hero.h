/**
\file Hero.h
\brief Header-file with a description of the hero.
*/
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Table.h"
#include "Tools.h"
#include "Equipment.h"
#include "Potion.h"
#include "Weapon.h"

using namespace sf;

#pragma once

/**
 *  \brief     Class to contain the hero.
 *  \details   Contains the name of the hero, its coordinates, the pointer to the table with the basic parameters, the pointer of the weapon, the number of keys, the potion number, max potion number and 2 map-s with equipment and potion.
 *  \datails   Builds with the Table OR with the Table + weapon OR with the Table + weapon  + equipment.
 *  \author    LinaAngelinaG
 *  \date      15.12.2021
 */
class Hero {
private:
	point coor = { 0,0 };
	int experience = 0;
	Weapon* weapon = nullptr;
	std::map <TYPE, Equipment*> equipment;
	std::map <int, Potion&> potions;          
	int potion_val = 0;
	int max_potion = 3;
	int keys = 0;

	float x, y, w, h, dx, dy, speed;
	int dir;
	String File;
	Image image;
	Texture texture;
	Sprite sprite;

	/*float w, h, dx, dy, x, y, speed;
	bool life, isMove, onGround;//добавили переменные состояния нахождения на земле
	enum { left, right, up, down, jump, stay } state;//добавляем тип перечисления - состояние объекта
	std::string File;
	Image image;
	Texture texture;
	Sprite sprite;*/

	Table* parameters = nullptr;
public:

	/**
	Allows to set the weapon.
	\param Pointer to the weapon.
	\return Nothing.
	*/
	inline void set_weapon(Weapon& w) { weapon = &w; }

	/**
	Allows to set the power.
	\param Table-class object.
	\return Nothing.
	*/
	inline void set_table(Table& t) { parameters = &t; } 

	/**
	Allows to set the experience.
	\param Integer value of the experience.
	\return Nothing.
	*/
	inline void set_experince(int n) { experience = n; }

	/**
	Allows to set the max number of potions.
	\param Integer value of the .
	\return Nothing.
	*/
	inline void set_max_potion(int n) { max_potion = n; }

	/**
	Allows to set the number of keys.
	\param Integer value of the number of keys.
	\return Nothing.
	*/
	inline void set_keys(int n) { keys = n; }

	/**
	Allows to set the coordinates.
	\param Integer value of the coordinates.
	\return Nothing.
	*/
	inline void set_coor(int x, int y) { coor = { x,y };} 

	/**
	Allows to set the equipment.
	\param Equipment-class object.
	\return Nothing.
	*/
	inline void set_equipment(Equipment& equip){equipment.insert({ equip.get_type(), &equip });}

	void set_potion(Potion&);

	//Hero(String F, float X, float Y, float W, float H, Table& tab);
	//void update(float time);

	void interactionWithMap(String*, std::map<point, Object*>);
	inline int getDir() { return dir; }
	inline void setDir(int d) { dir = d; }
	inline void setSpeed(double sp) { speed = sp; }
	inline Sprite* getSprite() { return &sprite; }
	inline double getX() { return x; }
	inline double getY() { return y; }

	Hero(String F, float X, float Y, float W, float H, Table& tab);

	/** Builds with the Table.
	*/
	Hero(Table& tab) :parameters(&tab) {};

	/** Builds with the Table + weapon.
	*/
	Hero(Weapon& w, Table& tab) :weapon(&w), parameters(&tab) {};

	/** Builds with the Table + weapon  + equipment.
	*/
	Hero(Equipment& eq, Table& tab):parameters(&tab) { set_equipment(eq); }

	/**
	Allows to get the weapon.
	\param No parameters.
	\return Constant refference to the weapon.
	*/
	inline const Weapon& get_weapon() const { return *weapon; }

	/**
	Allows to get the table.
	\param No parameters.
	\return Constant refference to the table.
	*/
	inline const Table& get_table() const{ return *parameters; } 

	/**
	Allows to get the experience.
	\param No parameters.
	\return Integer value of the experience.
	*/
	inline int get_experince() const { return experience; }

	/**
	Allows to get the max value of the potions.
	\param No parameters.
	\return Integer value of the max value of the potions.
	*/
	inline int get_max_potion() const { return max_potion; }

	/**
	Allows to get the value of keys.
	\param No parameters.
	\return Integer value of keys.
	*/
	inline int get_keys() const { return keys; }

	/**
	Allows to get the value of potions.
	\param No parameters.
	\return Integer value of the value of potions.
	*/
	inline int get_potion_val() const { return potion_val; }

	/**
	Allows to get the coordinates.
	\param No parameters.
	\return Constant refference to the point.
	*/
	inline point& get_coor() { return coor; }

	const Potion* get_potion(int) const;
	
	const Equipment* get_equipment(TYPE) const;

	/**
	Allows to get the damage to attack.
	\param Enum ENEMY name.
	\return Integer value of the damage.
	*/
	inline int generate_damage(ENEMY enemy) const { if (weapon) return weapon->use(enemy); else return 0; }  //сгенерировать урон на основании всей экип-ки и бонусов
	
	void gain_damage(int); //получить урон с учетом защиты 
	void drink_potion(int); //выпить зелье под номером //---
	void upgrate_param(CHARACTERS);
	void update(double, String *, std::map<point, Object*>);
	void take_tool(Tool&); //взять предмет
};