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
	String* tm = u.getMap();

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

		p.update(time, tm);
		v.viewmap(time);//������� ���������� �����, �������� �� ����� sfml

		window.setView(*view);//"��������" ������ � ���� sfml
		window.clear();
		int key = 0;
		/////////////////////////////������ �����/////////////////////
		for (int i = 0; i < HEIGHT_MAP; i++) {
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (tm[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 45, 45)); //���� ��������� ������ ������, �� ������ 1� ���������
				if (tm[i][j] == '0')  s_map.setTextureRect(IntRect(45, 0, 45, 45));//���� ��������� ������ s, �� ������ 2� ���������
				if ((tm[i][j] == 's')) s_map.setTextureRect(IntRect(100, 0, 45, 45));//���� ��������� ������ 0, �� ������ 3� ���������}
				if ((tm[i][j] == 'k')) s_map.setTextureRect(IntRect(150, 0, 45, 45));//���� ��������� ������ 0, �� ������ 3� ���������


				s_map.setPosition(j * 45, i * 45);//�� ���� ����������� ����������, ��������� � �����. �� ���� ������ ������� �� ��� �������. ���� ������, �� ��� ����� ���������� � ����� �������� 32*32 � �� ������ ���� �������

				window.draw(s_map);//������ ���������� �� �����
			}
		}

		std::ostringstream potionAmount, keysAmount;    // �������� ���������� �������� � �������
		potionAmount << p.get_potion_val();		//��������� ������
		keysAmount << p.get_keys();
		Text text;
		text.setString("�����: " + potionAmount.str() + "\n���-�� ������: " + keysAmount.str());//������ ������ ������ � �������� �������������� ���� ������ ������� .str()

		text.setPosition((*view).getCenter().x, (*view).getCenter().y);//������ ������� ������, �������� �� ������ ������

		window.draw((*p.getSprite()));
		window.draw(text);//����� ���� �����

		window.display();
	}


	return 0;
}