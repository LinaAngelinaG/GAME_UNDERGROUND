#include <iostream>
#include "Table.h"
#include "Tools.h"
#include "Artefact.h"
#include "Equipment.h"
#include "Potion.h"
#include "Weapon.h"

class Hero {
private:
	int experience;
	Table* parameters;
	Weapon* weapon;
	std::map<std::string, Equipment&> equipment;
	Potion* potions;
	int max_potion;
	int keys;

public:
	inline void set_weapon(Weapon* w) { weapon = w; }
	inline void set_table(Table* t) { parameters = t; }
	inline void set_experince(int n) { experience = n; }
	inline void set_max_potion(int n) { max_potion = n; }
	inline void set_keys(int n) { keys = n; }

	void set_equipment(std::map<std::string, Equipment&>&);
	void set_potion(Potion*);
	
	Hero();


	inline Weapon& get_weapon() { return *weapon; }
	inline Table& get_table() { return *parameters; }
	inline int get_experince() { return experience; }
	inline int get_max_potion() { return max_potion; }
	inline int get_keys() { return keys; }
	inline std::map<std::string, Equipment&>& get_equipment() { return equipment; }
	inline Potion& get_potion() { return *potions; }

	void take_tool(Tool*); //����� �������
	void drink_potion(int); //������ ����� ��� �������
	int generate_damage();  //������������� ���� �� ��������� ���� ����-�� � �������
	void gain_damage(int); //�������� ���� � ������ ������
	void upgrate_param(std::string); //�������� ��������������(�� ��������� �����) �� ���� ���������� �����
};