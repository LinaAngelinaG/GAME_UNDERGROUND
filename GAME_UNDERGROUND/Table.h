#include <iostream>
#include <map>
#pragma once

typedef struct info {
	std::string longname;
	int value;
};

class Table
{
protected:
	int n=0;
	std::map<std::string, info> table;
public:
	Table(); //����� �������-�� ����, ��������, ������������, ������������ ��������, ������� ��������
	~Table();

	inline int get_col_param() { return n; }
	inline int get_val_of_param(std::string param) { return table.at(param).value; }
	inline void set_val_of_param(std::string param, info& value) { table.insert({ param, value }); }
};