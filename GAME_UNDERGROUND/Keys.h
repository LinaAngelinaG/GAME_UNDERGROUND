#include "Tools.h"
#pragma once

class Keys : public Tool {
private:
	int number_of_keys;
public:
	Keys(int n, std::string str) :number_of_keys(n), Tool(str) {};
	Keys(int n) :number_of_keys(n), Tool("DEFALT_NAME_FOR_KEYS") {};
	Keys() :number_of_keys(1), Tool("DEFALT_NAME_FOR_KEYS") {};

	int get_num_of_keys() { return number_of_keys; }
	void set_num_of_keys(int n) { number_of_keys = n; }

	int use(std::string); //��������� ���-�� ������ �� 1 - �������� ��� ��������

	inline bool isArtefact() { return false; }
};