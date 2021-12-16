/**
\file Potion.h
\brief Header-file with a description of the potion.
Subclass for the class Artefact.
*/
#include "Artefact.h"
#include "Enemy.h"
#pragma once

/**
 *  \brief     Subclass (for Artefact) that desribes potion.
 *  \details   Holds the container-class from the artefact.
 *  \details   Builds with the name of the enum CHARACTERS characteristic and its value.
 *  \author    LinaAngelinaG
 *  \date      15.12.2021
 */
class Potion : public Artefact {
protected:

	/**
	Need to override virtual fuction from the abstract class 'Tool'.
	\param Enum ENENY name.
	\return Always returns 0.
	*/
	inline int use(ENEMY e) { return 0; }
public:

	/** Builds with the name of the enum CHARACTERS characteristic and its value.
	*/
	Potion(CHARACTERS art, int val) :Artefact(art, val) { Tool::type_of_obj = "potion";};
	
	/**
	Allows to get the full name of the potion.
	\param No parameters.
	\return String full name.
	*/
	inline std::string getname() { return get_feature() + " potion"; }
};