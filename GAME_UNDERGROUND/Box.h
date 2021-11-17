#include "Tools.h"

class Box
{
private:
	int level;
	//type of the Tool: using template
	Tool& tool;
public:
	Box(Tool& t) :level(1), tool(t) {};
	Box(int n, Tool& t) :level(n), tool(t) {};

	int get_level() { return level; }
	Tool& get_tool() { return tool; }
	void set_tool(Tool& t) { tool = t; }
	void set_level(int n) { level = n; }
	bool open();
};

int main() {
	std::string  s = "jkfdv";
	Weapon& r1 = g;
	Weapon* r2 = &g;
	Tool* t1 = &g;
	t1->use(s);
	Keys k;
	Tool& t2 = k;
	t2.use(s);
	CharmedWeapon cw1(1,s);
	ArtefactedCharmedWeapon acw1(1);
	ArtefactedEquipment ae1(1);
	ArtefactedWeapon aw1(1);
	Potion p;
}