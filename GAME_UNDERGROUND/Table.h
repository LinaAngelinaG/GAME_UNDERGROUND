/**
\file Table.h
\brief Header-file with a description of the table.
*/
#include <iostream>
#include <map>
#include "ENUMS.h"
#pragma once

/**
 *  \brief     Structure that desribes information about each parameter: long and short name of characteristic and its value.
 *  \details   Builds with the long and short name of characteristic and its value.
 *  \author    LinaAngelinaG
 *  \date      15.12.2021
 */
struct info {
	CHARACTERISTICS longname;
	int value;
};

/**
 *  \brief     Class that desribes information about the hero.
 *  \details   Contains the map of parameters, their values and number.
 *  \details   Builds without any parameters, there is an ability to set all the parameters.
 *  \author    LinaAngelinaG
 *  \date      15.12.2021
 */
class Table
{
protected:
	int n=0;
	std::map<CHARACTERS, info&> table;
public:
	Table(); //будут инициал-ны сила, ловкость, выносливость, максимальное здоровье, текущее здоровье
	~Table();

	/**
	Allows to get the number of parameters.
	\param No arguments.
	\return Ineteger number.
	*/
	inline int get_col_param() const { return n; }

	/**
	Allows to get the value of the exact parameter.
	\param Enum CHARACTERS parameter name.
	\return Ineteger value of the parameter.
	*/
	inline int get_val_of_param(CHARACTERS param) const { return table.at(param).value; }

	void set_val_of_param(CHARACTERS param, int value);
};