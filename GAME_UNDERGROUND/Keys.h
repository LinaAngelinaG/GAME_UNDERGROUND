/**
\file Keys.h
\brief Header-file with a description of the keys.
Subclass for the class Tool.
*/
#include "Tools.h"
#include "Enemy.h"
#include <string>
#pragma once

/**
 *  \brief     Subclass(for basic class Tool) to contain keys.
 *  \details   Containes only the number of keys.
 *  \datails   Builds with the Integer number of keys.
 *  \author    LinaAngelinaG
 *  \date      15.12.2021
 */
class Keys : public Tool {
private:
	int number_of_keys;
public:

	/** Builds with the Integer number of keys.
	*/
	Keys(int n) :number_of_keys(n) {};
	
	/**
	Allows to get the number of keys.
	\param No arguments.
	\return Integer number of keys.
	*/
	inline int get_num_of_keys() { return number_of_keys; }

	/**
	Allows to set the number of keys.
	\param Integer number of keys.
	\return No arguments.
	*/
	inline void set_num_of_keys(int n) { number_of_keys = n; }

	int use(ENEMY); //уменьшить кол-во ключей на 1 - ломаетс€ или остаетс€

	/**
	Allows to get the full name of the keys.
	\param No arguments.
	\return String full name.
	*/
	inline std::string getname() { return std::to_string(number_of_keys) + " keys"; }
};