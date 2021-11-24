#include <iostream>
#include <map>
class Table
{
private:
	int n=0;
	std::map<std::string, info&>* table;
public:
	Table(); //����� �������-�� ����, ��������, ������������, ������������ ��������, ������� ��������
	~Table();

	inline int get_col_param() { return n; }

	int get_val_of_param(std::string);
	void set_val_of_param(std::string, int);
};

typedef struct info {
	std::string longname;
	int value;
};

//Power
//Agility
//Resistance