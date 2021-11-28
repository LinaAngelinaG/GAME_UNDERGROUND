#include "Artefact.h"
#include "Enemy.h"
#pragma once

class Potion : public Artefact {
protected:
	inline int use(ENEMY e) { return 0; }
public:
	Potion(ARTEFACTED art, int val) :Artefact(art, val) {};
	//��� ������� �� ����� ������, ��� ����� ����� ������ ������, ���
	//��� ������ ��� ����������� � ������������ ������
	//�������� ���������� ����� ����� �������� �������� get_map()
	//������� ������ ������ �� ���� � ����������������, ������� ����� ������
	inline std::string getname() { return get_feature() + " potion"; }
};