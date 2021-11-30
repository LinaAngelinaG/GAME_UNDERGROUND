#include "Tools.h"
#include <map>
#include <iostream>
#include "ENUMS.h"
#pragma once

class Artefact : virtual public Tool { //����������� �����
protected:
	
    //name of the characteristic and the value that it changes
	ARTEFACTED artefact = NONE;
	int value = 0;
public:
	inline void becomeUpToPower(int n) { artefact = POWERUP; value = n; }
	inline void becomeUpToResistance(int n) { artefact = RESISTANCEUP; value = n; }
	inline void becomeUpToAgility(int n) { artefact = AGILITYUP; value = n; }

	inline bool isArtefact() { return true; }

	std::string get_feature();
	int get_feature_val() { return value; }

	Artefact(ARTEFACTED art, int n):artefact(art), value(n) { };

	//��� �������� �� ���� ���������� ��������� ��������������?
	//������������ ������ ����� ���� ����������������� ����
	//����� �����-�� �������� �� ������������� � ��������� ���� ���������� �������
};