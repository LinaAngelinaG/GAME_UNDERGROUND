#pragma once

enum ENEMY {  //contains health // power and experience are equal and = health-9
	Humanlikely = 10,
	Witch,
	Slug,
	Demon
};

enum CHARM {
	Damned,
	Burning,
	Blessed,
	Drying
};

enum  WEAPON_NAME //константный параметр - это и есть величина урона
{
	Sword = 4,
	Axe,
	Baton
};

enum ARTEFACTED {
	POWERUP,
	RESISTANCEUP,
	AGILITYUP,
	NONE
};

enum TYPE {
	Head = 1,
	Hands,
	Finger
};
enum EQUIPMENT {
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