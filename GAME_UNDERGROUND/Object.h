/**
\file Object.h
\brief Header-file with a description of the object.
*/
#pragma once
#include "ENUMS.h"

/**
 *  \brief     Abstract class to contain Enemy, Box and Tools.
 *  \details   Containes only pure virtual method to gain the object type.
 *  \author    LinaAngelinaG
 *  \date      15.12.2021
 */
class Object
{
	/**
	Allows to get the type of the object.
	\param No arguments.
	\return Enum objectType with one of the values {enemy, box, tool}.
	*/
	virtual objectType getObjectType() = 0;
};

