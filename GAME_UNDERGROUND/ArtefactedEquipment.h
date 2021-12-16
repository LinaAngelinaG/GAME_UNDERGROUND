/**
\file ArtefactedEquipment.h
\brief Header-file with a description of the charmed weapon that is artefact at the same time.
Subclass for equipment and artefacts.
*/

#include "Tools.h"
#include "Artefact.h"
#include "Equipment.h"
#pragma once

/**
 *  \brief     Class that desribes all the equipment that upgrates the hero's characteristics.
 *  \details   Contains the map-like-class Modificate that includes parameters and values in which
 *  \details   these parameters change(from the artefact class). Also contains function use() from the class equipment.
 *  \details   Builds with the name of the equipment, the name of the parameter and its value.
 *  \author    LinaAngelinaG
 *  \date      15.12.2021
 */
class ArtefactedEquipment : public Equipment, public Artefact {
public:
	/** Builds with the name of the equipment, the name of the parameterand its value.
	*/
	ArtefactedEquipment(EQUIPMENT Name1, CHARACTERS Name2, int val) :Equipment(Name1), Artefact(Name2, val) {};

	/**
	* Virtual function (for correct gaining of the name).
	Lets to get the full name of the artefacted equipment that contains artefact's parameters and equipment's name.
	\param no arguments
	\return String with the full name.
	*/
	virtual std::string getname() { return get_feature() + " " + Equipment::getname(); }
};