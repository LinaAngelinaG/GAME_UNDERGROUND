#include <iostream>
#include <map>
#pragma once

struct info {
	std::string longname;
	int value;
};

class Table
{
protected:
	int n=0;
	std::map<std::string, info> table;
public:
	Table(); //будут инициал-ны сила, ловкость, выносливость, максимальное здоровье, текущее здоровье
	~Table();

	inline int get_col_param() { return n; }
	inline int get_val_of_param(std::string param) { return table.at(param).value; }
	inline void set_val_of_param(std::string param, info& value) { table.insert({ param, value }); }
};