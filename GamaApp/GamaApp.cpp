#pragma once
#include <SFML/Graphics.hpp>
#include <iostream> 
#include "Hero.h"
#include "Underground.h"
#include "View.h"
#pragma once

using namespace sf;

/*class SpriteManager {//��� ����� �� ��������� �����,����� �� �������� �������� �� ��� ���������)
public:
	Image image;
	Texture texture;
	Sprite sprite;
	String name;
	String file;
	int widthOfSprite;
	int heightOfSprite;
	SpriteManager(String File, String Name) {
		file = File;
		name = Name;
		image.loadFromFile("images/" + file);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
	}
};*/

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
			v.getplayercoordinateforview(p.getX(), p.getY());//�������� ���������� ������ � ������� ���������� �������
		}

		if ((Keyboard::isKeyPressed(Keyboard::Right))) {
			p.setDir(0); 
			p.setSpeed(0.08);
			CurrentFrame += 0.008 * time;
			if (CurrentFrame > 10) CurrentFrame -= 10;
			(*p.getSprite()).setTextureRect(IntRect(32 * int(CurrentFrame), 64, 32, 32));
			v.getplayercoordinateforview(p.getX(), p.getY());//�������� ���������� ������ � ������� ���������� �������
		}

		if ((Keyboard::isKeyPressed(Keyboard::Up))) {
			p.setDir(3); 
			p.setSpeed(0.08);
			CurrentFrame += 0.008 * time;
			if (CurrentFrame > 10) CurrentFrame -= 10;
			(*p.getSprite()).setTextureRect(IntRect(32 * int(CurrentFrame), 64, 32, 32));
			v.getplayercoordinateforview(p.getX(), p.getY());//�������� ���������� ������ � ������� ���������� �������
		}

		if ((Keyboard::isKeyPressed(Keyboard::Down))) {
			p.setDir(2); 
			p.setSpeed(0.08);
			CurrentFrame += 0.008 * time;
			if (CurrentFrame > 10) CurrentFrame -= 10;
			(*p.getSprite()).setTextureRect(IntRect(32 * int(CurrentFrame), 64, 32, 32));
			v.getplayercoordinateforview(p.getX(), p.getY());//�������� ���������� ������ � ������� ���������� �������
		}



		p.update(time);
		v.viewmap(time);//������� ���������� �����, �������� �� ����� sfml

		window.setView(*view);//"��������" ������ � ���� sfml
		window.clear();

		/////////////////////////////������ �����/////////////////////
		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 45, 45)); //���� ��������� ������ ������, �� ������ 1� ���������
				if (TileMap[i][j] == '0')  s_map.setTextureRect(IntRect(45, 0, 45, 45));//���� ��������� ������ s, �� ������ 2� ���������
				if ((TileMap[i][j] == 's')) s_map.setTextureRect(IntRect(90, 0, 45, 45));//���� ��������� ������ 0, �� ������ 3� ���������


				s_map.setPosition(j * 45, i * 45);//�� ���� ����������� ����������, ��������� � �����. �� ���� ������ ������� �� ��� �������. ���� ������, �� ��� ����� ���������� � ����� �������� 32*32 � �� ������ ���� �������

				window.draw(s_map);//������ ���������� �� �����
			}


		window.draw((*p.getSprite()));
		window.display();
	}


	return 0;
}