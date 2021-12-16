/**
\file
\brief Contains all static elements.
*/
#pragma once

///typename of the charm
enum LEVEL {
	ONE = 90, ///< The first level for the box with the probability of opening 90%
	TWO = 75, ///< The second level for the box with the probability of opening 75%
	THREE = 45, ///< The third level for the box with the probability of opening 45%
	FOUR = 35, ///< The fourth level for the box with the probability of opening 35%
	FIVE = 25 ///< The fith level for the box with the probability of opening 25%
};

///name of the enemy: contains health, power and experience are equal and = health-9
enum ENEMY {  
	Humanlikely = 10, ///< Enemy that is like a simple human, have 10 points of health, 1 point of experience and 1 point of the power
	Witch, ///< Enemy that have 11 points of health, 2 point of experience and 2 point of the power
	Slug, ///< Enemy that 12 points of health, 3 point of experience and 3 point of the power
	Demon ///< Enemy that have 13 points of health, 4 point of experience and 4 point of the power
};

///typename of the charm
enum CHARM { 
	Burning, ///< Give the bonus against the Witch
	Blessed, ///< Give the bonus against the Demon
	Damned, ///< Give the bonus against the Humanlikely
	Drying ///< Give the bonus against the Slug
};

///typename of the weapon
enum  WEAPON_NAME { 
	Axe = 5, ///< The axe with damage equal to 5
	Baton = 6, ///< The baton with damage equal to 6
	Sword = 4 ///< The sword with damage equal to 4
};

///the part of the body that uses this equipment
enum TYPE { 
	Head = 1, ///< Have to be weared on the head
	Hands, ///< Have to be weared on the hands
	Finger ///< Have to be weared on the finger
};
enum EQUIPMENT { //typename of the equipment
	Helmet = Head, ///< This equipment gives 1 point of safity
	Gloves = Hands, ///< This equipment gives 2 point of safity
	Ring = Finger ///< This equipment gives 3 point of safity
};

///short name of characteristics
enum CHARACTERS {  
	Power,
	Resistance,
	Agility,
	Health,
	Cur_health
};

///long name of characteristics
enum CHARACTERISTICS { 
	POWER,
	RESISTANCE,
	AGILITY,
	HEALTH,
	CURRENT_HEALTH
};

/// All the types of the cells of the underground
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

/// Describes the point of the cell: its coordinates
struct point {
	int x; ///< x-coordinate
	int y; ///< y-coordinate
};

/// Type of the object that can stand on the field
enum objectType {
	enemy,
	box,
	tool
};