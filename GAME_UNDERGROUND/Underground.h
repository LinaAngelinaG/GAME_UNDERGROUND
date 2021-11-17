#pragma once
#include "Tools.h"
#include "Box.h"
#include "Hero.h"
#include "Enemy.h"
//0 - пол, 1 - открытая дверь, 2 - закрытая дверь
//3 - лестница вверх, 4 - лестница вниз
//5 - предмет, 6 - сундук

class Underground
{
private:
	Hero* hero;

	int level;
	int length;
	int width;

	point& coor_hero;
	std::map<point, Enemy*> enemies;

	std::map<point, smth> cells; // разрешенная матрица хранения сундуков и предметов
	std::map<point, int> field;  //разреженная матрица поля
	int check_stairs(); // проверить, что лестница вверх совпадает с лестницей вниз
public:	
	inline void set_size(int l, int w) { length = l; width = w; }
	inline void set_field(std::map<point, int>* c) { field = *c; }
	inline void set_coor_hero(point& p) { coor_hero = p; }
	inline point& get_coor_hero() { return coor_hero; }
	inline std::map<point, int> & get_field() { return field; }

	void set_cell(point&, smth&);
	void set_enemy(point&, Enemy*);
	std::string get_enemy(point&); //возвращает имя врага, стоящего на клетке
	smth& get_cell(point&);

	void open_door(point&);
	void close_door(point&);
};

class smth {
	Tool* t;
	Box* b;
};
class point {
	int x;
	int y;
};