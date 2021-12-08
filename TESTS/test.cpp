#pragma once
#include "pch.h"
#include "ArtefactedCharmedWeapon.h"
#include "ArtefactedEquipment.h"
#include "ArtefactedWeapon.h"
#include "Box.h"
#include "CharmedWeapon.h"
#include "Enemy.h"
#include "Hero.h"
#include "Keys.h"
#include "Potion.h"
#include "Table.h"
#include "Container.h"

TEST(TestEquipment, Testall) {

	Equipment eq1(Helmet);
	Equipment eq2(Gloves);
	Equipment eq3(Ring);

	ASSERT_EQ(eq1.getname().compare("Helmet"), 0);
	ASSERT_EQ(eq2.getname().compare("Gloves"), 0);
	ASSERT_EQ(eq3.getname().compare("Ring"), 0);

	ASSERT_EQ(eq1.get_type(), Head);
	ASSERT_EQ(eq2.get_type(), Hands);
	ASSERT_EQ(eq3.get_type(), Finger);

	EXPECT_FALSE(eq1.isArtefact());
	EXPECT_FALSE(eq2.isArtefact());
	EXPECT_FALSE(eq3.isArtefact());
	
	ASSERT_EQ(eq1.use(Humanlikely), 1);
	ASSERT_EQ(eq2.use(Humanlikely), 2);
	ASSERT_EQ(eq3.use(Humanlikely), 3);
}

TEST(TestBox, Testall) {
	Equipment eq(Helmet);
	Box box(eq);
	Box box1(2,eq);
	ASSERT_EQ(box.get_level(), 1);
	ASSERT_EQ(box1.get_level(), 2);
	ASSERT_EQ(box.get_tool().getname().compare("Helmet"), 0);

	int s = 0;
	for (int i = 0; i < 10; i++) {
		s += box.open(1);
	}

	ASSERT_TRUE(s > 7);
	box.set_level(3);
	ASSERT_EQ(box.get_level(), 3);
}

TEST(TestEnemy, Testall) {
	Enemy e1(Humanlikely);
	Enemy e2(Witch);
	Enemy e3(Demon);
	Enemy e4(Slug);

	ASSERT_EQ(e1.get_type_enemy(), Humanlikely);


	ASSERT_EQ(e1.attack(), 1);
	ASSERT_EQ(e2.attack(), 2);
	ASSERT_EQ(e3.attack(), 4);
	ASSERT_EQ(e4.attack(), 3);

	ASSERT_EQ(e1.get_outcomes(), 1);
	ASSERT_EQ(e2.get_outcomes(), 1);
	ASSERT_EQ(e3.get_outcomes(), 1);
	ASSERT_EQ(e4.get_outcomes(), 1);

	ASSERT_EQ(e1.get_health(), 10);
	ASSERT_EQ(e2.get_health(), 11);
	ASSERT_EQ(e3.get_health(), 13);
	ASSERT_EQ(e4.get_health(), 12);

	e1.harm(2);

	ASSERT_EQ(e1.get_cur_health(), 8);
	ASSERT_EQ(e1.get_name().compare("Humanlikely"), 0);
	ASSERT_EQ(e1.get_experince(), 1);

	Equipment eq(Helmet);
	e1.set_tool(&eq);

	ASSERT_EQ(e1.get_tool().getname().compare("Helmet"), 0);
}

TEST(TestKeys, Testall) {
	Keys k1(2);

	ASSERT_EQ(k1.getname().compare("2 keys"), 0);
	ASSERT_EQ(k1.get_num_of_keys(), 2);
	ASSERT_FALSE(k1.isArtefact());
}

TEST(TestPotion, Testall) {
	Potion p(Power, 2);
	ASSERT_EQ(p.getname().compare("POWERUP potion"), 0);
	ASSERT_TRUE(p.isArtefact());
	ASSERT_EQ(p.get_feature().compare("POWERUP"),0);
	ASSERT_EQ(p.get_feature_val(Power), 2);
	p.becomeUpTo(Agility, 4);
	ASSERT_EQ(p.get_feature().compare("POWERUP AGILITYUP"), 0);
	ASSERT_EQ(p.get_feature_val(Agility), 4);
}

TEST(TestWeapon, Testall) {
	Weapon eq1(Sword);
	Weapon eq2(Axe);
	Weapon eq3(Baton);

	ASSERT_EQ(eq1.getname().compare("Sword"), 0);
	ASSERT_EQ(eq2.getname().compare("Axe"), 0);
	ASSERT_EQ(eq3.getname().compare("Baton"), 0);

	EXPECT_FALSE(eq1.isArtefact());
	EXPECT_FALSE(eq2.isArtefact());
	EXPECT_FALSE(eq3.isArtefact());

	ASSERT_EQ(eq1.use(Witch), 4);
	ASSERT_EQ(eq2.use(Witch), 5);
	ASSERT_EQ(eq3.use(Witch), 6);
}

TEST(TestCharmedWeapon, Testall) {
	CharmedWeapon w(Axe, Drying);
	ASSERT_EQ(w.getname().compare("Drying Axe"), 0);
	w.becomeBlessed(2);
	ASSERT_EQ(w.getname().compare("Blessed Drying Axe"), 0);
	ASSERT_EQ(w.get_charm().compare("Blessed Drying"), 0);
	EXPECT_FALSE(w.isArtefact());
	ASSERT_EQ(w.use(Witch), 5);
	ASSERT_EQ(w.use(Demon), 7);
}

TEST(TestArtefactedCharmedWeapon, Testall) {
	ArtefactedCharmedWeapon w(Baton, Burning, Resistance,2);
	ASSERT_EQ(w.get_feature().compare("RESISUP"), 0);
	ASSERT_EQ(w.get_feature_val(Resistance), 2);
	ASSERT_EQ(w.get_charm().compare("Burning"), 0);
	ASSERT_EQ(w.getname().compare("RESISUP Burning Baton"),0);
	ASSERT_TRUE(w.isArtefact());
	ASSERT_EQ(w.use(Witch), 7);
	ASSERT_EQ(w.use(Demon), 6);

	w.becomeBlessed(5);
	w.becomeUpTo(Power, 3);

	ASSERT_EQ(w.getname().compare("POWERUP RESISUP Burning Blessed Baton"), 0);
	ASSERT_EQ(w.get_feature_val(Power), 3);
	ASSERT_EQ(w.get_charm().compare("Burning Blessed"), 0);
	ASSERT_TRUE(w.isArtefact());
	ASSERT_EQ(w.use(Witch), 7);
	ASSERT_EQ(w.use(Demon), 8);
}

TEST(TestArtefactedWeapon, Testall) {
	ArtefactedWeapon w(Baton, Resistance, 1);
	ASSERT_EQ(w.get_feature().compare("RESISUP"), 0);
	ASSERT_EQ(w.get_feature_val(Resistance), 1);
	ASSERT_EQ(w.getname().compare("RESISUP Baton"), 0);
	ASSERT_TRUE(w.isArtefact());
	ASSERT_EQ(w.use(Demon), 6);

	w.becomeUpTo(Power,3);

	ASSERT_EQ(w.getname().compare("POWERUP RESISUP Baton"), 0);
	ASSERT_EQ(w.get_feature_val(Power), 3);
	ASSERT_TRUE(w.isArtefact());
	ASSERT_EQ(w.use(Witch), 6);
}

TEST(TestArtefactedEquipment, Testall) {
	ArtefactedEquipment w(Helmet, Resistance, 1);
	ASSERT_EQ(w.get_feature().compare("RESISUP"), 0);
	//ASSERT_EQ(w.get_feature_val(), 1);
	ASSERT_EQ(w.getname().compare("RESISUP Helmet"), 0);
	ASSERT_TRUE(w.isArtefact());
	ASSERT_EQ(w.use(Demon), 1);

	w.becomeUpTo(Power, 3);

	ASSERT_EQ(w.getname().compare("POWERUP RESISUP Helmet"), 0);
	//ASSERT_EQ(w.get_feature_val(), 3);
	ASSERT_TRUE(w.isArtefact());
	ASSERT_EQ(w.use(Witch), 1);

	ArtefactedEquipment ww(Ring, Resistance, 1);
	ASSERT_EQ(ww.get_feature().compare("RESISUP"), 0);
	ASSERT_EQ(ww.get_feature_val(Resistance), 1);
	ASSERT_EQ(ww.getname().compare("RESISUP Ring"), 0);
	ASSERT_TRUE(ww.isArtefact());
	ASSERT_EQ(ww.use(Demon), 3);

	ww.becomeUpTo(Power, 3);

	ASSERT_EQ(ww.getname().compare("POWERUP RESISUP Ring"), 0);
	ASSERT_EQ(ww.get_feature_val(Power), 3);
	ASSERT_TRUE(ww.isArtefact());
	ASSERT_EQ(ww.use(Witch), 3);
}

TEST(TestHero, Testall) {
	Table t;
	Hero hero1(t);
	Weapon weapon(Axe);
	Equipment equip(Helmet);
	Hero hero2(weapon,t);

	ASSERT_EQ(hero1.get_keys(),0);
	ASSERT_EQ(hero1.get_experince(), 0);
	ASSERT_EQ(hero1.get_max_potion(), 3);
	ASSERT_EQ(hero1.get_keys(), 0);

	ASSERT_EQ(&hero2.get_weapon(), &weapon);

	Potion p1(Power, 2), p2(Power,3);
	p1.becomeUpTo(Agility, 3);
	hero1.set_potion(p1);
	hero1.set_potion(p2);

	ASSERT_EQ(hero1.get_potion(1), &p1);
	ASSERT_EQ(hero1.get_potion(2), &p2);

	Equipment e(Helmet);
	Hero hero3(e,t);

	ASSERT_EQ(hero3.get_equipment(Head), &e);
	ASSERT_EQ(hero3.get_equipment(Hands), nullptr);

	hero3.set_weapon(weapon);

	ASSERT_EQ(&hero3.get_weapon(), &weapon);

	hero3.set_experince(3);
	hero3.set_max_potion(10);
	hero3.set_keys(5);
	hero2.set_equipment(e);

	ASSERT_EQ(hero3.get_experince(), 3);
	ASSERT_EQ(hero3.get_max_potion(), 10);
	ASSERT_EQ(hero3.get_keys(), 5);
	ASSERT_EQ(hero2.get_equipment(Head), &e);
	ASSERT_EQ(hero2.generate_damage(Witch), 5);
	ASSERT_EQ(hero2.get_table().get_val_of_param(Cur_health), 10);

	Potion p3(Power,6);
	Tool& tool = p3;
	hero1.take_tool(tool);
	hero1.take_tool(weapon);
	Enemy enemy(Witch), enemy2(Slug);
	hero2.gain_damage(enemy.attack());

	ASSERT_EQ(hero2.get_table().get_val_of_param(Cur_health), 9);
	ASSERT_EQ(hero1.get_potion_val(), 3);
	ASSERT_EQ(&hero1.get_weapon(), &weapon);

	hero1.drink_potion(1);

	ASSERT_EQ(hero1.get_potion_val(), 2);
	ASSERT_EQ(hero1.get_table().get_val_of_param(Power), 3);

	hero1.set_experince(3);
	hero1.upgrate_param(Power);

	ASSERT_EQ(hero1.get_table().get_val_of_param(Power), 4);
	ASSERT_EQ(hero1.get_table().get_val_of_param(Agility), 4);
}

TEST(TestUnderground, Testall) {
	
}

TEST(TestContainer, Testall) {
	Container<CHARM> container(Blessed,2);
	container.print();

	container.insert(Blessed, 3);
	container.insert(Burning, 4);
	container.insert(Drying, 1);

	std::cout<< container.find(Blessed) << std::endl;
	container.print();
	std::cout << container.getSize() << std::endl;

	for (Container<CHARM>::Iterator it = container.begin(); it != container.end(); ++it) {
		
	}
}