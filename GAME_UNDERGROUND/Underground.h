#include "Tools.h"
#include "Box.h"
#include "Hero.h"
#include "Enemy.h"
#include <SFML/Graphics.hpp>

#pragma once

static const int HEIGHT_MAP = 30;
static const int WIDTH_MAP = 40;

struct smth {
	Tool* t;
	Box* b;
};

struct Cell {
	FIELD typeOfField;
	Object* objectOnCell;
};

class Underground{
private:
	Hero * hero;

	int level;
	int length;
	int width;
	std::map <point, Cell&> field;

	//point & coor_hero;
	//typedef bool my_predicate(const std::map < point, Object*>::iterator iter1, const std::map < point, Object*>::iterator iter2);
	//auto comp = [](const point& a, const point& b) { return (a.x() < b.x()); };
	std::map<point, Object*> objects;

	std::map<point, Enemy*> enemies;
	std::map<point, smth> cells; // разреженная матрица хранения сундуков и предметов
	//std::map<point, FIELD> field;  //разреженная матрица поля
	//inline void setSize(int l, int w) { length = l; width = w; }

	int checkPoint(point&);
	int checkStairsAndCorrect(); // проверить, что лестница вверх совпадает с лестницей вниз

	String TileMap[HEIGHT_MAP] = {

	"0000000000000000000000000000000000000000",
	"0      sk0   b                         0",
	"00000    0         w         w         0",  // 2, 19 // 2, 29
	"0     e    b     e                     0",  // 3, 6. //3,11 //3,17 
	"000000000000000                        0",  
	"0      0      0   e                    0",  //5,18
	"0             0000000                  0",
	"0                                      0",
	"0       0        0000000000000000   0000",
	"0        0                             0",
	"0         0           k                0",
	"0                                      0",
	"0     000000          0                0",
	"0                    0                 0",
	"0                   0                  0",
	"0        e                             0",
	"0                                      0",
	"0     k                                0",
	"0                                      0",
	"0                          w           0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                   0000               0",
	"0           000000000000               0",
	"0           000000000000               0",
	"0           000000000000               0",
	"0000000000000000000000000000000000000000",
	};
public:	
	Underground(Hero*);
	inline String* getMap() { return TileMap; }
	
	//inline void setField(std::map<point, Cell&>* c) { field = *c; }
	//inline void set_coor_hero(point& p) { coor_hero = p; }
	//inline point& get_coor_hero() { return coor_hero; }

	inline std::map<point, Cell&> & getField() { return field; }

	std::map<point, Object*> * getObjects() { return &objects; }

	//void addObject(Object* obj, point p) { objects.insert({ p, obj }); }

	void setCell(point&, Cell&);
	//void set_enemy(point&, Enemy*);
	//std::string get_enemy(point&); //возвращает имя врага, стоящего на клетке
	Cell& getCell(point&);

	//inline void addEnemy(Enemy* e, point& p) { enemies.insert({p,e});}
	void openDoor(point&);
	void closeDoor(point&);

	void uploadUnderground(std::string filename);
	void saveUnderground(std::string filename);

};
