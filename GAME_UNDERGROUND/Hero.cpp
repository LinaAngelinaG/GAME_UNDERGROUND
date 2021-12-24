/**
\file Hero.cpp
\brief File with some methods of the hero.
*/
#pragma once
#include "Hero.h"
#include "View.h"
#include "Box.h"

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

Hero::Hero(String F, float X, float Y, float W, float H, Table& tab) :parameters(&tab) {
	dx = 0; dy = 0; speed = 0; dir = 0;
	File = F;
	w = W; h = H;
	image.loadFromFile("images/" + File);
	image.createMaskFromColor(Color(41, 33, 59));
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	x = X; y = Y;
	sprite.setTextureRect(IntRect(0, 0, w, h));
}

void Hero::interactionWithMap(String* TileMap, std::map<point, Object*> under){//�-��� �������������� � ������
	for (int i = y / 45; i < (y + h) / 45; i++) {//���������� �� ��������, �������������� � �������, �� ���� �� ���� ����������� 
		
		for (int j = x / 45; j < (x + w) / 45; j++)//��� ����� �� 45, ��� ����� �������� ����� ���������, � ������� �������� �������������.
		{
			if (TileMap[i][j] == '0')//���� ��� ��������� ������������� ������� 0 (�����), �� ��������� "����������� ��������" ���������:
			{
				if (dy > 0)//���� �� ��� ����,
				{
					y = i * 45 - h;//�� �������� ���������� ����� ���������. ������� �������� ���������� ������ ���������� �� �����(�����) � ����� �������� �� ������ ������� ���������.
				}
				if (dy < 0)
				{
					y = i * 45 + 45;//���������� � ������� �����. dy<0, ������ �� ���� ����� (���������� ���������� ������)
				}
				if (dx > 0)
				{
					x = j * 45 - w;//���� ���� ������, �� ���������� � ����� ����� (������ 0) ����� ������ ���������
				}
				if (dx < 0)
				{
					x = j * 45 + 45;//���������� ���� �����
				}
			}

			if (TileMap[i][j] == 's') { //���� ������ ����� 's'
				TileMap[i][j] = ' ';//�������,- ����� �����
				++potion_val;
			}
			if (TileMap[i][j] == 'k') { //���� ������ ����� 'k'
				TileMap[i][j] = ' ';//�������,- ����� �����
				keys+=5;
			}
			if (TileMap[i][j] == 'w') { //new weapon
				if (!weapon) {
					try {
						weapon = dynamic_cast<Weapon*>(under.at({ i, j }));
						TileMap[i][j] = ' ';
					}
					catch (std::exception e) {
					}
				}
				else{
					try {
						Object* obj = under.at({ i, j });
						Weapon* w = dynamic_cast<Weapon*>(under.at({ i, j }));
						
						under.insert({ { i,j }, weapon });
						weapon = w;
					}
					catch (std::exception e) {
					}
				}
			}
			if (TileMap[i][j] == 'e') { //���� enemy
				try {
					Enemy* e = dynamic_cast<Enemy*>(under.at({ i, j }));
					std::cout << "DAMAGE IS   " << std::endl;
					std::cout << " CUR HEALTH" << parameters->get_val_of_param(Cur_health) << std::endl;
					gain_damage(e->attack());
					//under.insert({ { i,j }, e });
					int dam = generate_damage(e->get_type_enemy());
					e->harm(dam);
					std::cout << "DAMAGE IS   " << dam <<" CUR HEALTH" << e->get_cur_health() << std::endl;
					std::cout <<" CUR HEALTH" << parameters->get_val_of_param(Cur_health) << std::endl;

					if (e->get_cur_health() < 0) {
						TileMap[i][j] = ' ';
					}
				}
				catch (std::exception e) {
					std::cout << "Exception"<<std::endl;
				}
			}
			if (TileMap[i][j] == 'b') { //Box
				try {
					Box* b = dynamic_cast<Box*>(under.at({ i, j }));
					std::cout << "KEYS IS   " << keys << std::endl;
					if (keys > 0) {
						int prob_false = 99 - rand() % 20;
						int random = rand() % 100;
						if (random > prob_false) {
							--keys;
						}
						if (b->open(1)) {
							Tool* tool = b->get_tool();
							std::string name = tool->get_type_of_obj();
							std::cout << "KEYS IS   " << keys << std::endl;
							TileMap[i][j] = ' ';
							if (name == "potion") {
								TileMap[i][j+1] = 'p';
							}
							else if (name == "weapon") {
								TileMap[i][j+1] = 'w';
							}
							Weapon* w = dynamic_cast<Weapon*>(tool);
							under.erase({ i,j });
							std::cout << "NAME   " << w->getname() << std::endl;
							under.insert({ { i,j +1}, b->get_tool() });
							w = dynamic_cast<Weapon*>(under.at({ i,j+1 }));
							if (w == nullptr)
								std::cout << "Strange null" << std::endl;
						}
					}
				}
				catch (std::exception e) {
					std::cout << "Exception" << std::endl;
				}
			}
		}
	}
}

void Hero::update(double time, String* tm, std::map<point, Object*> under)
{
	switch (dir)
	{
	case 0:
		dx = speed;
		dy = 0;
		break;
	case 1:
		dx = -speed;
		dy = 0;
		break;
	case 2:
		dx = 0;
		dy = speed;
		break;
	case 3:
		dx = 0;
		dy = -speed;
		break;
	}

	x += dx * time;
	y += dy * time;

	speed = 0;
	sprite.setPosition(x, y);
	interactionWithMap(tm, under);//�������� �������, ���������� �� �������������� � ������
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
