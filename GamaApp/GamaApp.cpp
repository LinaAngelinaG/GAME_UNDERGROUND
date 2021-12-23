#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "Hero.h"
#include "Underground.h"
#include "View.h"
#pragma once

using namespace sf;


int main() {
	
	RenderWindow window(sf::VideoMode(640, 480), "MyTragicGame");
	Views v;
	sf::View * view = v.getView();
	(*view).reset(sf::FloatRect(0, 0, 640, 480));//������ "����" ������ ��� �������� ������� ���� ������. (����� ����� ������ ��� �����) ��� �� ���� �������������.
	Image map_image;//������ ����������� ��� �����
	map_image.loadFromFile("images/map.png");//��������� ���� ��� �����
	Texture map;//�������� �����
	map.loadFromImage(map_image);//�������� �������� ���������
	Sprite s_map;//������ ������ ��� �����
	s_map.setTexture(map);//�������� �������� ��������

	Table table;
	Hero p("myhero.png", 45., 47., 32.0, 32.0, table);
	Underground u(&p);
	Weapon weapon(Sword);
	Weapon weapon1(Baton);
	Weapon weapon2(Axe);
	p.set_weapon(weapon);

	String* tm = u.getMap();
	Enemy e(Slug);
	Enemy e1(Witch);
	Enemy e2(Demon);
	u.getObjects()->insert({ {2,19},&weapon1 });
	u.getObjects()->insert({ {3,6},&e });
	u.getObjects()->insert({ {3, 17},&e1 });
	u.getObjects()->insert({ {5, 18},&e2 });
	
	//u.getObjects()->insert({ {4,21},&e });

	/*try {
		Enemy* e11 = dynamic_cast<Enemy*>(u.getObjects()->at({ 4, 21 }));
		std::cout << "DAMAGE IS   " << std::endl;
		int dam = p.generate_damage(e11->get_type_enemy());
		e11->harm(dam);
		std::cout << "DAMAGE IS   " << dam << " CUR HEALTH" << e11->get_cur_health() << std::endl;
		std::cout << " CUR HEALTH" << p.get_table().get_val_of_param(Cur_health) << std::endl;
	}
	catch (std::exception e) {
		std::cout << "Exception" << std::endl;
	}*/

	float CurrentFrame = 0;
	Clock clock;

	while (window.isOpen())
	{

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		///////////////////////////////////////////���������� ���������� � ���������////////////////////////////////////////////////////////////////////////
		if ((Keyboard::isKeyPressed(Keyboard::Left))) {
			p.setDir(1);
			p.setSpeed(0.08);
			CurrentFrame += 0.008 * time;
			if (CurrentFrame > 10) CurrentFrame -= 10;
			(*p.getSprite()).setTextureRect(IntRect(32 * (1 + int(CurrentFrame)), 64, -32, 32));
		}

		if ((Keyboard::isKeyPressed(Keyboard::Right))) {
			p.setDir(0); 
			p.setSpeed(0.08);
			CurrentFrame += 0.008 * time;
			if (CurrentFrame > 10) CurrentFrame -= 10;
			(*p.getSprite()).setTextureRect(IntRect(32 * int(CurrentFrame), 64, 32, 32));
		}

		if ((Keyboard::isKeyPressed(Keyboard::Up))) {
			p.setDir(3);
			p.setSpeed(0.08);
			CurrentFrame += 0.008 * time;
			if (CurrentFrame > 10) CurrentFrame -= 10;
			(*p.getSprite()).setTextureRect(IntRect(32 * int(CurrentFrame), 64, 32, 32));
		}

		if ((Keyboard::isKeyPressed(Keyboard::Down))) {
			p.setDir(2);
			p.setSpeed(0.08);
			CurrentFrame += 0.008 * time;
			if (CurrentFrame > 10) CurrentFrame -= 10;
			(*p.getSprite()).setTextureRect(IntRect(32 * int(CurrentFrame), 64, 32, 32));
		}

		v.getplayercoordinateforview(p.getX(), p.getY());//�������� ���������� ������ � ������� ���������� �������

		p.update(time, tm, *u.getObjects());
		v.viewmap(time);//������� ���������� �����, �������� �� ����� sfml

		window.setView(*view);//"��������" ������ � ���� sfml
		window.clear();
		int key = 0;

		/////////////////////////////������ �����/////////////////////
		for (int i = 0; i < HEIGHT_MAP; i++) {
			for (int j = 0; j < WIDTH_MAP; j++){
				if (tm[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 45, 45)); //���� ��������� ������ ������, �� ������ 1� ���������
				if (tm[i][j] == '0')  s_map.setTextureRect(IntRect(45, 0, 45, 45));//���� ��������� ������ s, �� ������ 2� ���������
				if ((tm[i][j] == 's')) s_map.setTextureRect(IntRect(100, 0, 45, 45));//���� ��������� ������ 0, �� ������ 3� ���������}
				if ((tm[i][j] == 'k')) s_map.setTextureRect(IntRect(135, 0, 45, 45));//���� ��������� ������ 0, �� ������ 3� ���������
				if ((tm[i][j] == 'w')) s_map.setTextureRect(IntRect(175, 0, 45, 45));//���� ��������� ������ 0, �� ������ 3� ���������
				if ((tm[i][j] == 'e')) s_map.setTextureRect(IntRect(225, 0, 45, 45));//���� ��������� ������ 0, �� ������ 3� ���������
				if ((tm[i][j] == 'b')) s_map.setTextureRect(IntRect(280, 0, 45, 45));//���� ��������� ������ 0, �� ������ 3� ���������

				s_map.setPosition(j * 45, i * 45);//�� ���� ����������� ����������, ��������� � �����. �� ���� ������ ������� �� ��� �������. ���� ������, �� ��� ����� ���������� � ����� �������� 32*32 � �� ������ ���� �������
				window.draw(s_map);//������ ���������� �� �����
			}
		}
		
		std::ostringstream potionAmount, keysAmount;    // �������� ���������� �������� � �������
		potionAmount << p.get_potion_val();		//��������� ������
		keysAmount << p.get_keys();
		Text text;
		text.setString("�����: " + potionAmount.str() + "\n���-�� ������: " + keysAmount.str());//������ ������ ������ � �������� �������������� ���� ������ ������� .str()

		text.setPosition(0, 0);//������ ������� ������, �������� �� ������ ������
		
		window.draw(text);//����� ���� �����
		window.draw((*p.getSprite()));

		window.display();
	}
	
	/*Table t;
	Hero p(t);
	Underground u(&p);
	Weapon weapon(Sword);
	p.set_weapon(weapon);

	Enemy e(Slug);
	u.getObjects()->insert({ {4,21},&e });
	u.getObjects()->insert({ {2,19},&weapon });

	try {
		Enemy* e1 = dynamic_cast<Enemy*>(u.getObjects()->at({ 4, 21 }));
		std::cout << "DAMAGE IS   " << std::endl;
		//under.insert({ { i,j }, e });
		int dam = p.generate_damage(e1->get_type_enemy());
		e1->harm(dam);
		std::cout << "DAMAGE IS   " << dam << " CUR HEALTH" << e1->get_cur_health() << std::endl;
		std::cout << " CUR HEALTH" << p.get_table().get_val_of_param(Cur_health) << std::endl;

		//18:45 �215
	}
	catch (std::exception e) {
		std::cout << "Exception" << std::endl;
	}
	*/

	return 0;
}