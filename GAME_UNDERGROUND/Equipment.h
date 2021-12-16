/**
\file Equipment.h
\brief Header-file with a description of the equipment.
Subclass for the class Tool.
*/
#include <iostream>
#include "Tools.h"
#include "ENUMS.h"
#pragma once

/**
 *  \brief     Subclass(for basic class Tool) to contain equipment.
 *  \details   Containes only the type of an equipment, each of which has its own value of safity.
 *  \datails   Builds with the enum EQUIPMENT name.
 *  \author    LinaAngelinaG
 *  \date      15.12.2021
 */
class Equipment : virtual public Tool {
protected:
	EQUIPMENT equip;
public:
	/** Builds with the enum EQUIPMENT name.
	*/
	Equipment(EQUIPMENT eq) : equip(eq) { Tool::type_of_obj = "equipment"; };
	~Equipment() = default;

	/**
	Allows to get the value of the safity.
	\param Enum ENEMY name.
	\return The Integer value of safity of the current equipment.
	*/
	inline int use(ENEMY en) { return equip; }; //возвращает величину защиты
	
	virtual std::string getname();

	/**
	Allows to get the 'wearing' type of the equipment.
	\param No arguments.
	\return Enum TYPE with the value from {Head, Hands, Fingure}.
	*/
	inline TYPE get_type() { return TYPE(equip); }
};