#include <iostream>
#include <map>
#include "ENUMS.h"
#pragma once

class Tool {
protected:
	std::string type_of_obj;
public:
	virtual int use(ENEMY) = 0;
	virtual bool isArtefact() = 0;
	virtual std::string getname() = 0;
	inline std::string get_type_of_obj() { return type_of_obj; }
};