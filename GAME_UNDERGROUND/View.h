#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;


class Views {
private:
	sf::View view;//�������� sfml ������ "���", ������� � �������� �������

public:
	inline sf::View* getView() { return &view; }
	Views() {};
	void getplayercoordinateforview(float x, float y);

	void viewmap(float time);

	void changeview();
};
