#pragma once
#include "View.h"

void Views::getplayercoordinateforview(float x, float y) { //������� ��� ���������� ��������� ������
	float tempX = x; float tempY = y;//��������� ����� ������ � ��������� ��, ����� ������ ����

	if (x < 320) tempX = 320;//������� �� ���� ����� �������
	if (y < 240) tempY = 240;//������� �������
	if (y > 950) tempY = 950;//������ �������	

	view.setCenter(tempX, tempY); //������ �� �������, ��������� ��� ����������. 

}

void Views::viewmap(float time) { //������� ��� ����������� ������ �� �����. ��������� ����� sfml


	if (Keyboard::isKeyPressed(Keyboard::D)) {
		view.move(0.1 * time, 0);//�������� ����� ������
	}

	if (Keyboard::isKeyPressed(Keyboard::S)) {
		view.move(0, 0.1 * time);//�������� ����� ���� 
	}

	if (Keyboard::isKeyPressed(Keyboard::A)) {
		view.move(-0.1 * time, 0);//�������� ����� �����
	}
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		view.move(0, -0.1 * time);//�������� ����� ������
	}

}

void Views::changeview() {

	if (Keyboard::isKeyPressed(Keyboard::U)) {
		view.zoom(1.0100f); //������������, ����������
		//view.zoom(1.0006f); //���� ����� ����������� ��������������
	}

	if (Keyboard::isKeyPressed(Keyboard::I)) {
		view.setSize(640, 480);//������������� ������ ������ (��� ��������)
	}

	if (Keyboard::isKeyPressed(Keyboard::P)) {
		view.setSize(540, 380);//�������� ������ ������
	}

}