/**
\file Hero.cpp
\brief File with some methods of the hero.
*/
#pragma once
#include "Hero.h"
#include "Underground.h"
#include "View.h"

/*
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
void Hero::update(float time)
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
}*/

/*Hero::Hero(std::string F, float X, float Y, float W, float H, Table& tab) :parameters(&tab) {
	speed = 0; dx = 0; dy = 0;
	life = true; onGround = false; isMove = false; state = stay;
	File = F;
	w = W; h = H;
	image.loadFromFile("images/" + File);
	image.createMaskFromColor(Color(41, 33, 59));
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	x = X; y = Y;
	sprite.setTextureRect(IntRect(0, 134, w, h));
	sprite.setOrigin(w / 2, h / 2);
}

void Hero::control() {
	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		state = left;
		speed = 0.1;
	}
	if (Keyboard::isKeyPressed(Keyboard::Right)) {
		state = right;
		speed = 0.1;
	}

	if ((Keyboard::isKeyPressed(Keyboard::Up)) && (onGround)) {
		dy = -0.4; onGround = false;//�� ��������� ����� ������,�������� � ��������, ��� �� �� �� �����

	}

	if (Keyboard::isKeyPressed(Keyboard::Down)) {
		state = down;
		speed = 0.1;
	}
}
void Hero::update(float time)
{
	control();//������� ���������� ����������
	switch (state)//��� �������� ��������� �������� � ����������� �� ���������
	{
	case right: dx = speed; break;//��������� ���� ������
	case left: dx = -speed; break;//��������� ���� �����
	case up: break;//����� ��������� �������� ������ (�������� �� ��������)
	case down: dx = 0; break;//����� ��������� �� ����� ������ ��������� (�������� �� ��������)
	case stay: break;//� ����� ����		
	}
	x += dx * time;
	checkCollisionWithMap(dx, 0);//������������ ������������ �� �
	y += dy * time;
	checkCollisionWithMap(0, dy);//������������ ������������ �� Y
	sprite.setPosition(x + w / 2, y + h / 2); //������ ������� ������� � ����� ��� ������
	if (parameters->get_val_of_param(Cur_health) <= 0) { life = false; }
	if (!isMove) { speed = 0; }
	dy = dy + 0.0015 * time;//������ ���������� � �����
	if (life) { setPlayerCoordinateForView(x, y); }
}

void Hero::checkCollisionWithMap(float Dx, float Dy)//� ��� �������� ������������ � ������
{
	for (int i = y / 32; i < (y + h) / 32; i++)//���������� �� ��������� �����
		for (int j = x / 32; j < (x + w) / 32; j++)
		{
			if (TileMap[i][j] == '0')//���� ������� ��� ������ �����? ��
			{
				if (Dy > 0) { y = i * 32 - h;  dy = 0; onGround = true; }//�� Y ����=>���� � ���(����� �� �����) ��� ������. � ���� ������ ���� ���������� ��������� � ��������� ��� �� �����, ��� ���� ������� ��� �� �� ����� ��� ����� ����� ����� �������
				if (Dy < 0) { y = i * 32 + 32;  dy = 0; }//������������ � �������� ������ �����(����� � �� �����������)
				if (Dx > 0) { x = j * 32 - w; }//� ������ ����� �����
				if (Dx < 0) { x = j * 32 + 32; }// � ����� ����� �����
			}
		}
}*/

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

void Hero::interactionWithMap(){//�-��� �������������� � ������
	for (int i = y / 45; i < (y + h) / 45; i++)//���������� �� ��������, �������������� � �������, �� ���� �� ���� ����������� ������� 32*32, ������� �� ���������� � 9 �����. ��� ������� ������� ����.
		for (int j = x / 45; j < (x + w) / 45; j++)//��� ����� �� 32, ��� ����� �������� ����� ���������, � ������� �������� �������������. (�� ���� ������ ������� 32*32, ������� ����� ������������ ������ �� ���������� ���������). � j<(x + w) / 32 - ������� ����������� ��������� �� ����. �� ���� ���������� ������ ������� ��������, ������� ������������� � ����������. ����� ������� ���� � ����� ����� ������� �� ����, ������� �� �� ������ �������� (���������������� � ������), �� ������� �������� (���������������� � ������)
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

			if (TileMap[i][j] == 's') { //���� ������ ����� 's' (������)
				x = 300; y = 300;//����� �� ��������... �������� ������������ �����
				TileMap[i][j] = ' ';//������� ������, ���� ����� �����. ����� � �� �������, ������.
			}
		}
}

void Hero::update(double time)
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
	interactionWithMap();//�������� �������, ���������� �� �������������� � ������
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

void init() {
	Table t;
	Hero h(t);
	h.interactionWithMap();
	h.update(0.1);
}
