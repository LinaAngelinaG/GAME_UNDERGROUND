#pragma once
#include "Tools.h"
#include "Box.h"
#include "Hero.h"
#include "Enemy.h"
#pragma once

struct smth {
	Tool* t;
	Box* b;
};

struct Cell {
	FIELD typeOfField;
	Object* objectOnCell;
};

class Underground
{
private:
	Hero* hero;

	int level;
	int length;
	int width;

	std::map <point, Cell&> field;

	//point & coor_hero;
	/*std::map<point, Enemy*> enemies;
	std::map<point, smth> cells; // разреженная матрица хранения сундуков и предметов
	std::map<point, FIELD> field;  //разреженная матрица поля*/
	//inline void setSize(int l, int w) { length = l; width = w; }
	int checkPoint(point&);
	int checkStairsAndCorrect(); // проверить, что лестница вверх совпадает с лестницей вниз
public:	
	Underground(Hero*);

	//inline void setField(std::map<point, Cell&>* c) { field = *c; }
	//inline void set_coor_hero(point& p) { coor_hero = p; }
	//inline point& get_coor_hero() { return coor_hero; }
	inline std::map<point, Cell&> & getField() { return field; }

	void setCell(point&, Cell&);
	//void set_enemy(point&, Enemy*);
	//std::string get_enemy(point&); //возвращает имя врага, стоящего на клетке
	Cell& getCell(point&);

	void openDoor(point&);
	void closeDoor(point&);

	void uploadUnderground(std::string filename);
	void saveUnderground(std::string filename);
};