#pragma once
#include "pch.h"
#include "Artefact.h"
#include "ArtefactedCharmedWeapon.h"
#include "ArtefactedEquipment.h"
#include "ArtefactedWeapon.h"
#include "Box.h"
#include "CharmedWeapon.h"
#include "Enemy.h"
#include "Equipment.h"
#include "Hero.h"
#include "Keys.h"
#include "Potion.h"
#include "Table.h"
#include "Weapon.h"

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
	Potion p(POWERUP, 2);
	ASSERT_EQ(p.getname().compare("POWERUP potion"), 0);
	ASSERT_TRUE(p.isArtefact());
	ASSERT_EQ(p.get_feature().compare("POWERUP"),0);
	ASSERT_EQ(p.get_feature_val(), 2);
	p.becomeUpToAgility(4);
	ASSERT_EQ(p.get_feature().compare("AGILITYUP"), 0);
	ASSERT_EQ(p.get_feature_val(), 4);
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
	w.becomeBlessed();
	ASSERT_EQ(w.getname().compare("Blessed Axe"), 0);
	ASSERT_EQ(w.get_charm().compare("Blessed"), 0);
	EXPECT_FALSE(w.isArtefact());
	ASSERT_EQ(w.use(Witch), 5);
	ASSERT_EQ(w.use(Demon), 7);
}

TEST(TestArtefactedCharmedWeapon, Testall) {
	ArtefactedCharmedWeapon w(Baton, Burning, RESISTANCEUP,1);
	ASSERT_EQ(w.get_feature().compare("RESISTANCEUP"), 0);
	ASSERT_EQ(w.get_feature_val(), 1);
	ASSERT_EQ(w.get_charm().compare("Burning"), 0);
	ASSERT_EQ(w.getname().compare("RESISTANCEUP Burning Baton"),0);
	ASSERT_TRUE(w.isArtefact());
	ASSERT_EQ(w.use(Witch), 7);
	ASSERT_EQ(w.use(Demon), 6);

	w.becomeBlessed();
	w.becomeUpToPower(3);

	ASSERT_EQ(w.getname().compare("POWERUP Blessed Baton"), 0);
	ASSERT_EQ(w.get_feature_val(), 3);
	ASSERT_EQ(w.get_charm().compare("Blessed"), 0);
	ASSERT_TRUE(w.isArtefact());
	ASSERT_EQ(w.use(Witch), 6);
	ASSERT_EQ(w.use(Demon), 8);
}

TEST(TestArtefactedWeapon, Testall) {
	ArtefactedWeapon w(Baton, RESISTANCEUP, 1);
	ASSERT_EQ(w.get_feature().compare("RESISTANCEUP"), 0);
	ASSERT_EQ(w.get_feature_val(), 1);
	ASSERT_EQ(w.getname().compare("RESISTANCEUP Baton"), 0);
	ASSERT_TRUE(w.isArtefact());
	ASSERT_EQ(w.use(Demon), 6);

	w.becomeUpToPower(3);

	ASSERT_EQ(w.getname().compare("POWERUP Baton"), 0);
	ASSERT_EQ(w.get_feature_val(), 3);
	ASSERT_TRUE(w.isArtefact());
	ASSERT_EQ(w.use(Witch), 6);
}

TEST(TestArtefactedEquipment, Testall) {
	ArtefactedEquipment w(Helmet, RESISTANCEUP, 1);
	ASSERT_EQ(w.get_feature().compare("RESISTANCEUP"), 0);
	ASSERT_EQ(w.get_feature_val(), 1);
	ASSERT_EQ(w.getname().compare("RESISTANCEUP Helmet"), 0);
	ASSERT_TRUE(w.isArtefact());
	ASSERT_EQ(w.use(Demon), 1);

	w.becomeUpToPower(3);

	ASSERT_EQ(w.getname().compare("POWERUP Helmet"), 0);
	ASSERT_EQ(w.get_feature_val(), 3);
	ASSERT_TRUE(w.isArtefact());
	ASSERT_EQ(w.use(Witch), 1);

	ArtefactedEquipment ww(Ring, RESISTANCEUP, 1);
	ASSERT_EQ(ww.get_feature().compare("RESISTANCEUP"), 0);
	ASSERT_EQ(ww.get_feature_val(), 1);
	ASSERT_EQ(ww.getname().compare("RESISTANCEUP Ring"), 0);
	ASSERT_TRUE(ww.isArtefact());
	ASSERT_EQ(ww.use(Demon), 3);

	ww.becomeUpToPower(3);

	ASSERT_EQ(ww.getname().compare("POWERUP Ring"), 0);
	ASSERT_EQ(ww.get_feature_val(), 3);
	ASSERT_TRUE(ww.isArtefact());
	ASSERT_EQ(ww.use(Witch), 3);
}

TEST(TestHero, Testall) {
	Hero hero1;
	Weapon weapon(Axe);
	Equipment equip(Helmet);
	Hero hero2(weapon);

	ASSERT_EQ(hero1.get_keys(),0);
	ASSERT_EQ(hero1.get_experince(), 0);
	ASSERT_EQ(hero1.get_max_potion(), 3);
	ASSERT_EQ(hero1.get_keys(), 0);

	ASSERT_EQ(&hero2.get_weapon(), &weapon);


}