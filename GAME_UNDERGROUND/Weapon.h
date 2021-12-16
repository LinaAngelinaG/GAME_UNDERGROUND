/**
\file Weapon.h
\brief Header-file with a description of the weapon.
Subclass for the class Tool.
*/
#include "Tools.h"
#include "ENUMS.h"
#pragma once

/**
 *  \brief     Subclass(for basic class Tool) to contain weapon.
 *  \details   Containes only the type of an weapon, each of which has its own value of damage.
 *  \datails   Builds with the enum WEAPON_NAME name.
 *  \author    LinaAngelinaG
 *  \date      15.12.2021
 */
class Weapon : virtual public Tool {
protected:
	WEAPON_NAME name;

public:

	/**
	Allows to get the value of the damage.
	\param Enum ENEMY name.
	\return The Integer value of damage of the current weapon.
	*/
	inline virtual int use(ENEMY Name) { return name; }   //возвращает величину урона

	/** Builds with the enum WEAPON_NAME name.
	*/
	Weapon(WEAPON_NAME Name) : name(Name) { Tool::type_of_obj = "weapon"; };
	~Weapon() = default;

	virtual std::string getname();
};