/**
\file ArtefactedWeapon.h
\brief Header-file with a description of the weapon that is artefact at the same time.
Subclass for weapon and artefacts.
*/

#include "Tools.h"
#include "Artefact.h"
#include "Weapon.h"
#include "ENUMS.h"
#pragma once

/**
 *  \brief     Class that desribes all the weapon that upgrates the hero's characteristics.
 *  \details   Contains the map-like-class Modificate that includes parameters and values in which
 *  \details   these parameters change(from the artefact class). Also contains function use() from the class weapon.
 *  \details   Builds with the name of the weapon, the name of the parameter and its value.
 *  \author    LinaAngelinaG
 *  \date      15.12.2021
 */
class ArtefactedWeapon : public Weapon, public Artefact {
public:
	/** Builds with the name of the weapon, the name of the parameterand its value.
		*/
	ArtefactedWeapon(WEAPON_NAME Name1, CHARACTERS Name2,int val) :Weapon(Name1), Artefact(Name2, val) {};
	
	/**
	Lets to get the full name of the artefacted weapon that contains artefact's parameters and weapon's name.
	\param no arguments
	\return String with the full name.
	*/
	std::string getname() { return Artefact::get_feature() + " " + Weapon::getname(); }
};