#include <iostream>
#include "Tools.h"
#include "ENUMS.h"
#pragma once

class Equipment : virtual public Tool {
protected:
	EQUIPMENT equip;

public:
	Equipment(EQUIPMENT eq) : equip(eq) {};
	~Equipment() = default;
	inline bool isArtefact() { return false; }
	inline int use(ENEMY en) { return equip; }; //возвращает величину защиты
	virtual std::string getname();
	inline TYPE get_type() { return TYPE(equip); }
};