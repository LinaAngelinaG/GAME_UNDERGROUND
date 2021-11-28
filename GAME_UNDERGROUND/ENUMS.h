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