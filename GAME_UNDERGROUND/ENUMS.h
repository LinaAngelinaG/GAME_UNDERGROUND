#pragma once

enum ENEMY {  //name of the enemy: contains health, power and experience are equal and = health-9
	Humanlikely = 10,
	Witch,
	Slug,
	Demon
};

enum CHARM { ////typename of the charm
	Burning,
	Blessed,
	Damned,
	Drying
};

enum  WEAPON_NAME //константный параметр - это и есть величина урона
{ //typename of the weapon
	Axe = 5,
	Baton = 6,
	Sword = 4
};

enum TYPE { //the part of the body that uses this equipment
	Head = 1,
	Hands,
	Finger
};
enum EQUIPMENT { //typename of the equipment
	Helmet = Head,
	Gloves = Hands,
	Ring = Finger
};

enum CHARACTERS {   //short name of characteristics
	Power,
	Resistance,
	Agility,
	Health,
	Cur_health
};

enum CHARACTERISTICS { //long name of characteristics
	POWER,
	RESISTANCE,
	AGILITY,
	HEALTH,
	CURRENT_HEALTH
};

enum FIELD {
	//0 - пол, 1 - открытая дверь, 2 - закрытая дверь
	//3 - лестница вверх, 4 - лестница вниз
	//5 - предмет, 6 - сундук
	Floor,
	OpenedDoor,
	ClosedDoor,
	UpStairs,
	DownStairs
};

struct point {
	int x;
	int y;
};

enum objectType {
	enemy,
	box,
	tool
};