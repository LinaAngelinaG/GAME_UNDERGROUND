/**
\file ArtefactedCharmedWeapon.h
\brief Header-file with a description of the charmed weapon that is artefact at the same time.
Subclass for charmed weapon and artefacts.
*/

#include "Tools.h"
#include "Artefact.h"
#include "CharmedWeapon.h"
#include "ENUMS.h"
#pragma once

/**
 *  \brief     Class that desribes all the weapon that upgrates the hero's characteristics and that gives the special bonus against some enemies.
 *  \details   Contains the map-like-class Modificate that includes parameters and values in which
 *  \details   these parameters change(from the artefact class). And containes the table of charmes and its bonus' values.
 *  \details   Builds with the name of the weapon, the charm's name (optional using value of the charm) the name of the parameter and its value.
 *  \author    LinaAngelinaG
 *  \date      15.12.2021
 */
class ArtefactedCharmedWeapon : public CharmedWeapon, public Artefact {
public:
	/**
	* Builds with the name of the weapon, the charm's name the name of the parameter and its value.
	*/
	ArtefactedCharmedWeapon(WEAPON_NAME Name1, CHARM Name2, CHARACTERS Name3, int val) :CharmedWeapon(Name1, Name2), Artefact(Name3, val) {};
	
	/**
	Builds with the name of the weapon, the charm's name (using value of the charm) the name of the parameter and its value.
	*/
	ArtefactedCharmedWeapon(WEAPON_NAME Name1, CHARM Name2, int val1, CHARACTERS Name3, int val2) :CharmedWeapon(Name1, Name2, val1), Artefact(Name3, val2) {};
	
	/**
	* Virtual function (for correct gaining of the name).
	Lets to get the full name of the artefacted weapon that contains artefact's parameters and charmed weapon's name.
	\param no arguments
	\return String with the full name.
	*/
	inline virtual std::string getname() { return get_feature() + " " + CharmedWeapon::getname(); }
	
	/**
	* Virtual function (for correct using).
	* Calculates tha value of damage that depends on the type of the weapon and the name of enemy acting with.
	\param The name of the enemy that hero is acting with.
	\return The integer value of damage.
	*/
	inline virtual int use(ENEMY enemy) { return CharmedWeapon::use(enemy); }
};