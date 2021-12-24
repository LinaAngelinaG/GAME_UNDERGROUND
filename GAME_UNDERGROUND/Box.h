/**
\file Box.h
\brief Header-file with a description of the Boxes that can contain some tools.
Subclass for the class Object.
*/

#include "Tools.h"
#include <random>
#include "Table.h"
#pragma once

/**
 *  \brief     Class that desribes box that holds the tools that hero can use.
 *  \details   Contains the level for which the probability of opening the box depends on. Also contains the tool that is hold inside.
 *  \details   Builds with the name of the tool, or with the name of the tool with the level of the box.
 *  \author    LinaAngelinaG
 *  \date      15.12.2021
 */
class Box: virtual public Object{
private:
	LEVEL level;
	Tool* tool;
public:
	/** Builds with the name of the tool.
	*/
	Box(Tool& t) :level(ONE), tool(&t) {};

	/** Builds with the name of the tool with the level of the box.
	*/
	Box(LEVEL n, Tool& t) :level(n), tool(&t) {};

	/**
	Lets to know the level of the box.
	\param No arguments.
	\return Level of the box.
	*/
	inline LEVEL get_level() { return level; }

	/**
	Lets to get the tool that it holds in.
	\param No arguments.
	\return The current tool's reference.
	*/
	inline Tool* get_tool() { return tool; }

	/**
	Lets to set the tool that it holds in.
	\param The exact tool's reference.
	\return Nothing to return.
	*/
	inline void set_tool(Tool& t) { tool = &t; }

	/**
	Lets to set the level of the box.
	\param The exact number of level.
	\return Nothing to return.
	*/
	inline void set_level(LEVEL n) { level = n; }

	/**
	Lets to get the type of exact object.
	\param No arguments.
	\return Always return "box" as a type.
	*/
	inline objectType getObjectType() override { return box; };

	bool open(int);
};