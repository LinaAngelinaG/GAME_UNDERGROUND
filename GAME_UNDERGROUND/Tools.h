/**
\file Tool.h
\brief Header-file with a description of the tools.
*/
#include <iostream>
#include <map>
#include "ENUMS.h"
#include "Object.h"
#pragma once

/**
* Subclass for the class Object.
 *  \brief     Abstact class that describes all the tools that can exist.
 *  \details   Holds the string that describe the type of the object.
 *  \details   Builds with the no parameters.
 *  \author    LinaAngelinaG
 *  \date      15.12.2021
 */
class Tool: virtual public Object {
protected:
	std::string type_of_obj = "object";
public:
	/** Builds with no parameters.
	*/
	Tool() {};

	/**
	Virtual function use() that spreads throw all the tools.
	\param Enum ENEMY name.
	\return	Integer value of the result.
	*/
	virtual int use(ENEMY) = 0;

	/**
	Lets to get the full name of the tool.
	\param No arguments.
	\return String with the full name.
	*/
	virtual std::string getname() = 0;

	/**
	Lets to get the type of object.
	\param No arguments.
	\return Always return 'tool'.
	*/
	inline objectType getObjectType() override { return tool; };

	/**
	Lets to get the type of object.
	\param No arguments.
	\return String type of the tool.
	*/
	inline std::string get_type_of_obj() { return type_of_obj; }
};