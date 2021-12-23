#pragma once
#include "View.h"

void Views::getplayercoordinateforview(float x, float y) { //функция для считывания координат игрока
	float tempX = x; float tempY = y;//считываем коорд игрока и проверяем их, чтобы убрать края

	if (x < 320) tempX = 320;//убираем из вида левую сторону
	if (y < 240) tempY = 240;//верхнюю сторону
	if (y > 950) tempY = 950;//нижнюю сторону	

	view.setCenter(tempX, tempY); //следим за игроком, передавая его координаты. 

}

void Views::viewmap(float time) { //функция для перемещения камеры по карте. принимает время sfml


	if (Keyboard::isKeyPressed(Keyboard::D)) {
		view.move(0.1 * time, 0);//скроллим карту вправо
	}

	if (Keyboard::isKeyPressed(Keyboard::S)) {
		view.move(0, 0.1 * time);//скроллим карту вниз 
	}

	if (Keyboard::isKeyPressed(Keyboard::A)) {
		view.move(-0.1 * time, 0);//скроллим карту влево
	}
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		view.move(0, -0.1 * time);//скроллим карту вправо
	}

}

void Views::changeview() {

	if (Keyboard::isKeyPressed(Keyboard::U)) {
		view.zoom(1.0100f); //масштабируем, уменьшение
		//view.zoom(1.0006f); //тоже самое помедленнее соответственно
	}

	if (Keyboard::isKeyPressed(Keyboard::I)) {
		view.setSize(640, 480);//устанавливает размер камеры (наш исходный)
	}

	if (Keyboard::isKeyPressed(Keyboard::P)) {
		view.setSize(540, 380);//например другой размер
	}

}