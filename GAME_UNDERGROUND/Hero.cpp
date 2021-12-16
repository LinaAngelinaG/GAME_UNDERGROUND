/**
\file Hero.cpp
\brief File with some methods of the hero.
*/
#include "Hero.h"

/**
	Allows to set the potion.
	\param Potion-class object.
	\return Nothing.
	*/
void Hero::set_potion(Potion& potion) {
	if (potion_val < max_potion) {
		++potion_val;
		potions.insert({ potion_val, potion });
	}
}

/**
	Allows to get the potion.
	\param Integer parameter of the number of the potion.
	\return Potion pointer object.
	*/
const Potion* Hero::get_potion(int n) const {
	if (n <= potion_val) 
		return &potions.at(n);
	return nullptr;
}

/**
	Allows to get the equipment.
	\param Enum TYPE type of the equipment.
	\return Equipment pointer object.
	*/
const Equipment* Hero::get_equipment(TYPE type) const {
	try {
		return equipment.at(type);
	}
	catch (std::exception ex) {
		return nullptr;
	}
}

/**
	Allows to gain the damage from the enemy.
	\param Integer value of the damage.
	\return Nothing.
	*/
void Hero::gain_damage(int damage) { 
	int save = 0;
	for (std::map<TYPE, Equipment*>::const_iterator it = equipment.cbegin(); it != equipment.cend(); ++it) {
		save += (*it).second->use(Witch);
	}
	damage -= save;
	save = parameters->get_val_of_param(Cur_health) - damage;
	parameters->set_val_of_param(Cur_health, save < 0 ? 0 : save);
}

/**
	Allows to drink the existing potion.
	\param Integer value of the potion.
	\return Nothing.
	*/
void Hero::drink_potion(int number) {
	if (potion_val >= number) {
		Potion& needed_potion = potions.at(number);
		for (Container<CHARACTERS>::ConstIterator it = needed_potion.get_modif().cbegin(); it != needed_potion.get_modif().cend(); ++it) {
			int cur = parameters->get_val_of_param((*it).key);
			parameters->set_val_of_param((*it).key, cur + (*it).value);
		}

		potions.erase(number); //erase used potion
		--potion_val;
	}
}

/**
	Allows to upgrate the basic parameters in the table with the experince points.
	\param Enum CHARACTERS characteristic for changing.
	\return Nothing.
	*/
void Hero::upgrate_param(CHARACTERS charact) {
	switch (charact) {
	case(Power):
		if (experience > 1) {
			int cur = parameters->get_val_of_param(Power);
			parameters->set_val_of_param(Power, cur +1);
			experience -= 2;
		}
		break;
	case(Agility):
		if (experience > 0) {
			int cur = parameters->get_val_of_param(Agility);
			parameters->set_val_of_param(Agility, cur+1);
			--experience;
		}
		break;
	case(Resistance):
		if (experience > 1) {
			int cur = parameters->get_val_of_param(Resistance);
			parameters->set_val_of_param(Resistance, cur+1);
			experience -= 2;
		}
		break;
	case(Health):
		if (experience > 1) {
			int cur = parameters->get_val_of_param(Health);
			parameters->set_val_of_param(Health, cur+1);
			experience -= 2;
		}
		break;
	case(Cur_health):
		if (experience > 0) {
			int cur = parameters->get_val_of_param(Cur_health);
			parameters->set_val_of_param(Cur_health, cur+1);
			experience -= 2;
		}
		break;
	}
}

/**
	Allows to take the found tool.
	\param Reference to the tool.
	\return Nothing.
	*/
void Hero::take_tool(Tool& tool) {
	std::string name = tool.get_type_of_obj();

	if (name == "potion") {
		set_potion(*dynamic_cast<Potion*>(&tool));
	}
	else if (name == "equipment") {
		set_equipment(*dynamic_cast<Equipment*>(&tool));
	}
	else if (name == "weapon") {
		set_weapon(*dynamic_cast<Weapon*>(&tool));
	}
}
