#include <iostream>
#include "Tools.h"
#include "Enemy.h"
#pragma once

enum TYPE {
	Head = 1,
	Hands,
	Finger
};
enum EQUIPMENT {
	Helmet = Head,
	Gloves = Hands,
	Ring = Finger
};
class Equipment : virtual public Tool {
protected:
	EQUIPMENT equip;

public:
	Equipment(EQUIPMENT eq) : equip(eq) {};
	~Equipment() = default;
	inline bool isArtefact() { return false; }
	inline int use(ENEMY en) { return equip; }; //возвращает величину защиты
	virtual std::string getname();
};