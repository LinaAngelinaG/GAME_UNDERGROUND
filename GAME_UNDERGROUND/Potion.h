#include "Artefact.h"
#pragma once

class Potion : public Artefact {
public:
	Potion() :Artefact("DEFALT_NAME_FOR_POTION") {};
	Potion(std::string name) : Artefact(name) {};
	//��� ������� �� ����� ������, ��� ����� ����� ������ ������, ���
	//��� ������ ��� ����������� � ������������ ������
	//�������� ���������� ����� ����� �������� �������� get_map()
	//������� ������ ������ �� ���� � ����������������, ������� ����� ������
	inline int use(std::string s) { return 0; }
};