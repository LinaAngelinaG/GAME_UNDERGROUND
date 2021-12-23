#include "Tools.h"
#include "Box.h"
#include "Hero.h"
#include "Enemy.h"
#include <SFML/Graphics.hpp>
const int HEIGHT_MAP = 30;
const int WIDTH_MAP = 40;

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
	std::map<point, smth> cells; // ����������� ������� �������� �������� � ���������
	std::map<point, FIELD> field;  //����������� ������� ����*/
	//inline void setSize(int l, int w) { length = l; width = w; }

	int checkPoint(point&);
	int checkStairsAndCorrect(); // ���������, ��� �������� ����� ��������� � ��������� ����

	String TileMap[HEIGHT_MAP] = {

	"0000000000000000000000000000000000000000",
	"0      sk0                             0",
	"00000    0                             0",
	"0                                      0",
	"000000000000000                        0",
	"0      0      0                        0",
	"0             0000000                  0",
	"0                                      0",
	"0       0        0000000000000000   0000",
	"0        0                             0",
	"0         0           k                0",
	"0                                      0",
	"0     000000          0                0",
	"0                    0                 0",
	"0                   0                  0",
	"0                                      0",
	"0                                      0",
	"0     k                                0",
	"0                                      0",
	"0                                      0",
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

	void setCell(point&, Cell&);
	//void set_enemy(point&, Enemy*);
	//std::string get_enemy(point&); //���������� ��� �����, �������� �� ������
	Cell& getCell(point&);

	void openDoor(point&);
	void closeDoor(point&);

	void uploadUnderground(std::string filename);
	void saveUnderground(std::string filename);
	
};
