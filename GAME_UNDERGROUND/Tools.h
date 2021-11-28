#include <iostream>
#include <map>
#include "ENUMS.h"
#pragma once

class Tool {
public:
	virtual int use(ENEMY) = 0;
	virtual bool isArtefact() = 0;
	virtual std::string getname() = 0;
};