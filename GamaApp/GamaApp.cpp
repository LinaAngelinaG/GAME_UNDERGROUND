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
	(*view).reset(sf::FloatRect(0, 0, 640, 480));//размер "вида" камеры при создании объекта вида камеры. (потом можем менять как хотим) Что то типа инициализации.
	Image map_image;//объект изображения для карты
	map_image.loadFromFile("images/map.png");//загружаем файл для карты
	Texture map;//текстура карты
	map.loadFromImage(map_image);//заряжаем текстуру картинкой
	Sprite s_map;//создаём спрайт для карты
	s_map.setTexture(map);//заливаем текстуру спрайтом

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


		///////////////////////////////////////////Управление персонажем с анимацией////////////////////////////////////////////////////////////////////////
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

		v.getplayercoordinateforview(p.getX(), p.getY());//передаем координаты игрока в функцию управления камерой

		p.update(time, tm);
		v.viewmap(time);//функция скроллинга карты, передаем ей время sfml

		window.setView(*view);//"оживляем" камеру в окне sfml
		window.clear();
		int key = 0;
		/////////////////////////////Рисуем карту/////////////////////
		for (int i = 0; i < HEIGHT_MAP; i++) {
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (tm[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 45, 45)); //если встретили символ пробел, то рисуем 1й квадратик
				if (tm[i][j] == '0')  s_map.setTextureRect(IntRect(45, 0, 45, 45));//если встретили символ s, то рисуем 2й квадратик
				if ((tm[i][j] == 's')) s_map.setTextureRect(IntRect(100, 0, 45, 45));//если встретили символ 0, то рисуем 3й квадратик}
				if ((tm[i][j] == 'k')) s_map.setTextureRect(IntRect(150, 0, 45, 45));//если встретили символ 0, то рисуем 3й квадратик


				s_map.setPosition(j * 45, i * 45);//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат

				window.draw(s_map);//рисуем квадратики на экран
			}
		}

		std::ostringstream potionAmount, keysAmount;    // объявили переменную здоровья и времени
		potionAmount << p.get_potion_val();		//формируем строку
		keysAmount << p.get_keys();
		Text text;
		text.setString("Зелий: " + potionAmount.str() + "\nКол-во ключей: " + keysAmount.str());//задаем строку тексту и вызываем сформированную выше строку методом .str()

		text.setPosition((*view).getCenter().x, (*view).getCenter().y);//задаем позицию текста, отступая от центра камеры

		window.draw((*p.getSprite()));
		window.draw(text);//рисую этот текст

		window.display();
	}


	return 0;
}