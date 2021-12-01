#include "Artefact.h"
#include "Enemy.h"
#pragma once

class Potion : public Artefact {
protected:
	std::string type_of_obj = "potion";
	inline int use(ENEMY e) { return 0; }
public:
	Potion(CHARACTERS art, int val) :Artefact(art, val) {};
	//ARTEFACTED
	//��� ������� �� ����� ������, ��� ����� ����� ������ ������, ���
	//��� ������ ��� ����������� � ������������ ������
	//�������� ���������� ����� ����� �������� �������� get_map()
	//������� ������ ������ �� ���� � ����������������, ������� ����� ������
	inline std::string getname() { return get_feature() + " potion"; }
};