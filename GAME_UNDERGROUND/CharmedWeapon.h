/**
\file CharmedWeapon.h
\brief Header-file with a description of the charmed weapon.
Subclass for the class Object.
*/
#include "Tools.h"
#include "Weapon.h"
#include "ENUMS.h"
#include "Container.h"
#pragma once

/**
 *  \brief     Class that desribes charmed weapon that describes the weapon with the specific characteristics.
 *  \details   Holds the container-class with charms that this weapon is being described. Also contains the tool that is hold inside.
 *  \details   Builds with the name of the weapon. name of charm (the value of charm is optional).
 *  \author    LinaAngelinaG
 *  \date      15.12.2021
 */
class CharmedWeapon : public Weapon {
protected:
	typedef Container<CHARM> Charms;
	Charms charms;
public:
	/**
	Lets to know the full list of all charms for the exact weapon.
	\param No arguments.
	\return String with all charms.
	*/
	std::string get_charm() const;

	/**
	Lets to set the charm with an exact value.
	\param The type of charm and its value.
	\return Nothing.
	*/
	inline void becomeCharmed(CHARM charm ,int value) { charms.insert(charm, value); }


	/** Builds with the name of the weapon, name of charm.
		*/
	CharmedWeapon(WEAPON_NAME Name, CHARM Charm, int n) :Weapon(Name) { charms.insert( Charm, n > 0 ? n : 0 ); };
	
	/** Builds with the name of the weapon, name of charm(with the value of the charm).
		*/
	CharmedWeapon(WEAPON_NAME Name, CHARM Charm) :Weapon(Name) { charms.insert( Charm, Charm ); };

	/**
	Lets to use the weapon with some bonus for the enemy that is associated with the weapon's charm.
	\param Enemy's name.
	\return Integer value of damage.
	*/
	virtual int use(ENEMY); //возвращает величину урона, использует charmes

	/**
	Lets to get the container of the charmed weapon.
	\param No arguments.
	\return Container with charms and its values.
	*/
	inline Charms& get_charms() { return charms; }
	
	/**
	Lets to get the full name of the charmed weapon.
	\param No arguments.
	\return String full name.
	*/
	inline virtual std::string getname() { return get_charm() + " " + Weapon::getname();}
};