#include <iostream>
#include <map>
#include "ENUMS.h"
#include "Object.h"
#pragma once

class Tool: public Object {
protected:
	std::string type_of_obj;
public:
	virtual int use(ENEMY) = 0;
	virtual bool isArtefact() = 0;
	virtual std::string getname() = 0;
	inline objectType getObjectType() override { return tool; };
	inline std::string get_type_of_obj() { return type_of_obj; }
};