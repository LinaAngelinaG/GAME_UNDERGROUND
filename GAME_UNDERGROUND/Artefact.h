#include "Tools.h"
#include <map>
#include <iostream>
#include "ENUMS.h"
#pragma once

class Artefact : virtual public Tool { //����������� �����
protected:
	typedef std::map<CHARACTERS, int> modificate;
    //name of the characteristic and the value that it changes
	modificate modification;
	int value = 0;
public:
	inline void becomeUpTo(CHARACTERS character, int n) { modification.insert({ character ,n }); }

	inline bool isArtefact() { return true; }
	inline const modificate & get_modif() const { return modification; }
	std::string get_feature() const;
	int get_feature_val(CHARACTERS) const;


	Artefact(CHARACTERS art, int n) { modification.insert({ art,n }); };
	//����� �������� �������� �� ��������������� ���-�� ����������

	//��� �������� �� ���� ���������� ��������� ��������������?
	//������������ ������ ����� ���� ����������������� ����
	//����� �����-�� �������� �� ������������� � ��������� ���� ���������� �������
};