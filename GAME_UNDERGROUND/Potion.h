#include "Artefact.h"
#pragma once

class Potion : public Artefact {
public:
	Potion() :Artefact("DEFALT_NAME_FOR_POTION") {};
	Potion(std::string name) : Artefact(name) {};
	//эта функция не имеет смысла, она нужна здесь только потому, что
	//она задана как виртуальная в родительском классе
	//основной функционал зелья можно получить функцией get_map()
	//которая вернет ссылку на мапу с характеристиками, которые зелье меняет
	inline int use(std::string s) { return 0; }
};