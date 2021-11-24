#include "Tools.h"
#include <random>
#include "Table.h"
#pragma once

static int PROBABILITY[] = {90,75,45,35,25};

class Box
{
private:
	int level;
	//type of the Tool: using template
	Tool* tool;
public:
	Box(Tool& t) :level(1), tool(&t) {};
	Box(int n, Tool& t) :level(n), tool(&t) {};

	inline int get_level() { return level; }
	inline Tool& get_tool() { return *tool; }
	inline void set_tool(Tool& t) { tool = &t; }
	inline void set_level(int n) { level = n; }

	bool open(int);
};