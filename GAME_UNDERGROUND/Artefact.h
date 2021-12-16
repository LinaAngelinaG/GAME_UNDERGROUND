/**
\file Artefact.
\brief Header-file with a description of the artefacts.
Subclass for class Tool.
*/

#include "Tools.h"
#include <iostream>
#include "Container.h"
#include "ENUMS.h"
#pragma once

/**
 *  \brief     Abstract class that desribes all the artefacts.
 *  \details   Contains the map-like-class Modificate that includes parameters and values in which
 *  \details   these parameters change. Builds with the name of the parameter and its value.
 *  \author    LinaAngelinaG
 *  \date      15.12.2021
 */

class Artefact : virtual public Tool{
protected:
	typedef Container<CHARACTERS> Modificate;
	Modificate modification;
	int value = 0;
public:

	/**
	Makes the artefact changing the hero's characteristic in a current value.
	\param character, value
	\return nothing to return
	*/
	inline void becomeUpTo(CHARACTERS character, int value) { modification.insert(character , value);}

	/**
	Allows to get the table of the artefact-object.
	\param no arguments
	\return the table of all parameters and their values
	*/
	inline const Modificate & get_modif() const { return modification; }

	/**
	Build a name of an artefact that contains all the names of changing parameters.
	\param no arguments
	\return string (name)
	*/
	std::string get_feature() const;

	/**
	Shows the value of changing parameter.
	\param The name of the parameter (character).
	\return (int) value
	*/
	int get_feature_val(CHARACTERS) const;
	
	/**
	Constructor needs enum CHARACTERS characteristic and its value.
	*/
	Artefact(CHARACTERS art, int n) { modification.insert(art, n); }
};