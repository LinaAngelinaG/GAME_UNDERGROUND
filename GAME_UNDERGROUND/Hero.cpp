#include "Hero.h"

void Hero::set_potion(Potion& potion) {
	if (potion_val < max_potion) {
		++potion_val;
		potions.insert({ potion_val, potion });
	}
}

const Potion* Hero::get_potion(int n) { 
	if (n <= potion_val) 
		return &potions.at(n);
	return nullptr;
}

const Equipment* Hero::get_equipment(TYPE type) {
	try {
		return equipment.at(type);
	}
	catch (std::exception ex) {
		return nullptr;
	}
}

void Hero::gain_damage(int damage) {
	int save = 0;
	for (std::map<TYPE, Equipment*>::const_iterator it = equipment.cbegin(); it != equipment.cend(); ++it) {
		save += (*it).second->use(Witch);
	}
	damage -= save;
	save = parameters->get_val_of_param(Cur_health) - damage;
	info cur_health = { CURRENT_HEALTH, save < 0 ? 0 : save };
	parameters->set_val_of_param(Cur_health, cur_health);
}

void Hero::drink_potion(int number) {
	if (potion_val >= number) {
		const Potion* needed_potion = get_potion(number);
		//potions.at(n). // должно получать характеристику изменяемую (а вообще мапу характеристик)
		//потом ее нужно вставить в parameters->set_val_of_param(param, val_of_param)
		for (std::map<CHARACTERS, int>::const_iterator iter = (*needed_potion).get_modif().cbegin(); iter != (*needed_potion).get_modif().cend(); ++iter) {
			int cur = parameters->get_val_of_param((*iter).first);
			info inf = { CHARACTERISTICS((*iter).first),cur + (*iter).second };
			parameters->set_val_of_param((*iter).first, inf);
		}
		potions.erase(number); //erase used potion
		--potion_val;
	}
}

void Hero::upgrate_param(CHARACTERS charact) {
	switch (charact) {
	case(Power):
		if (experience > 1) {
			int cur = parameters->get_val_of_param(Power);
			info cur_ = { POWER, cur + 1 };
			parameters->set_val_of_param(Power, cur_);
			experience -= 2;
		}
		break;
	case(Agility):
		if (experience > 0) {
			int cur = parameters->get_val_of_param(Agility);
			info cur_ = { AGILITY, cur + 1 };
			parameters->set_val_of_param(Agility, cur_);
			--experience;
		}
		break;
	case(Resistance):
		if (experience > 1) {
			int cur = parameters->get_val_of_param(Resistance);
			info cur_ = { RESISTANCE, cur + 1 };
			parameters->set_val_of_param(Resistance, cur_);
			experience -= 2;
		}
		break;
	case(Health):
		if (experience > 1) {
			int cur = parameters->get_val_of_param(Health);
			info cur_ = { HEALTH, cur + 2 };
			parameters->set_val_of_param(Health, cur_);
			experience -= 2;
		}
		break;	
	case(Cur_health):
		if (experience > 0) {
			int cur = parameters->get_val_of_param(Cur_health);
			info cur_ = { CURRENT_HEALTH, cur + 4 };
			parameters->set_val_of_param(Cur_health, cur_);
			experience -= 2;
		}
		break;
	}
}

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
