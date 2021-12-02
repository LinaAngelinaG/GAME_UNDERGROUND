#include <iostream>
#include <map>
#include "ENUMS.h"
#pragma once

struct info {
	CHARACTERISTICS longname;
	int value;
};

class Table
{
protected:
	int n=0;
	std::map<CHARACTERS, info&> table;
public:
	Table(); //будут инициал-ны сила, ловкость, выносливость, максимальное здоровье, текущее здоровье
	~Table();
	inline int get_col_param() const { return n; }
	inline int get_val_of_param(CHARACTERS param) const { return table.at(param).value; }
	void set_val_of_param(CHARACTERS param, int value);
};