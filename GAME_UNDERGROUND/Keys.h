#include "Tools.h"
#include "Enemy.h"
#include <string>
#pragma once

class Keys : public Tool {
private:
	int number_of_keys;
public:
	Keys(int n) :number_of_keys(n) {};
	
	int get_num_of_keys() { return number_of_keys; }
	void set_num_of_keys(int n) { number_of_keys = n; }

	int use(ENEMY); //уменьшить кол-во ключей на 1 - ломаетс€ или остаетс€
	std::string getname() { return std::to_string(number_of_keys) + " keys"; }
	inline bool isArtefact() { return false; }
};