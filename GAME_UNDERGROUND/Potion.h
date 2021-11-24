#include "Artefact.h"
#include <iostream>

class Potion : public Artefact {
public:
	Potion() :Artefact("DEFALT_NAME_FOR_POTION") {};
	Potion(std::string name) : Artefact(name) {};

	inline int use(std::string s) { return 0; }
};