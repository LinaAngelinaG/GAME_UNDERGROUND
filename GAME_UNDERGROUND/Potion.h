#include "Artefact.h"
#include "Enemy.h"
#pragma once

class Potion : public Artefact {
protected:
	inline int use(ENEMY e) { return 0; }
public:
	Potion(ARTEFACTED art, int val) :Artefact(art, val) {};
	//эта функция не имеет смысла, она нужна здесь только потому, что
	//она задана как виртуальная в родительском классе
	//основной функционал зелья можно получить функцией get_map()
	//которая вернет ссылку на мапу с характеристиками, которые зелье меняет
	inline std::string getname() { return get_feature() + " potion"; }
};