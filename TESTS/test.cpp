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

	Equipment eq1(1);
	Equipment eq2(2);
	Equipment eq3(3);

	std::string name1 = eq1.get_name();
	std::string name2 = eq2.get_name();
	std::string name3 = eq3.get_name();
	ASSERT_EQ(name1.compare("Helmet"), 0);
	ASSERT_EQ(name2.compare("Gloves"), 0);
	ASSERT_EQ(name3.compare("Ring"), 0);

	EXPECT_FALSE(eq1.isArtefact());
	EXPECT_FALSE(eq2.isArtefact());
	EXPECT_FALSE(eq3.isArtefact());
	eq1.set_name("New Helmet");

	ASSERT_EQ(eq1.get_name().compare("New Helmet"), 0);
	ASSERT_EQ(eq1.use("Enemy"), 4);
	ASSERT_EQ(eq2.use("Enemy"), 5);
	ASSERT_EQ(eq3.use("Enemy"), 6);
}

TEST(TestBox, Testall) {
	Equipment eq(1);
	Box box(eq);
	Box box1(2,eq);
	ASSERT_EQ(box.get_level(), 1);
	ASSERT_EQ(box1.get_level(), 2);
	ASSERT_EQ(box.get_tool().get_name().compare("Helmet"), 0);

	int s = 0;
	for (int i = 0; i < 10; i++) {
		s += box.open(1);
	}

	ASSERT_TRUE(s > 7);
	box.set_level(3);
	ASSERT_EQ(box.get_level(), 3);
}

TEST(TestEnemy, Testall) {
	Enemy e1(1);
	Enemy e2(2);
	Enemy e3(3);
	Enemy e4(4);

	ASSERT_EQ(e1.attack(), 1);
	ASSERT_EQ(e2.attack(), 2);
	ASSERT_EQ(e3.attack(), 5);
	ASSERT_EQ(e4.attack(), 1);

	ASSERT_EQ(e1.get_outcomes(), 1);
	ASSERT_EQ(e2.get_outcomes(), 1);
	ASSERT_EQ(e3.get_outcomes(), 1);
	ASSERT_EQ(e4.get_outcomes(), 1);

	ASSERT_EQ(e1.get_health(), 10);
	ASSERT_EQ(e2.get_health(), 12);
	ASSERT_EQ(e3.get_health(), 15);
	ASSERT_EQ(e4.get_health(), 18);

	e1.harm(2);

	ASSERT_EQ(e1.get_cur_health(), 8);
	ASSERT_EQ(e1.get_name().compare("Humanlikely"), 0);
	ASSERT_EQ(e1.get_experince(), 1);

	Equipment eq(1);
	e1.set_tool(&eq);

	ASSERT_EQ(e1.get_tool().get_name().compare("Helmet"), 0);
}

TEST(TestKeys, Testall) {
	Keys k1(2);
	ASSERT_EQ(k1.get_name().compare("DEFALT_NAME_FOR_KEYS"), 0);
	ASSERT_EQ(k1.get_num_of_keys(), 2);
	ASSERT_FALSE(k1.isArtefact());
}

TEST(TestPotion, Testall) {
	Potion p;
	std::cout << "\n\n\nNAAAMEE" << p.get_name() << "\n\n\n\n";

	ASSERT_EQ(p.get_name().compare("DEFALT_NAME_FOR_POTION"), 0);
	ASSERT_TRUE(p.isArtefact());
}

TEST(TestWeapon, Testall) {
	Weapon eq1(1);
	Weapon eq2(2);
	Weapon eq3(3);

	std::string name1 = eq1.get_name();
	std::string name2 = eq2.get_name();
	std::string name3 = eq3.get_name();

	ASSERT_EQ(name1.compare("Sword"), 0);
	ASSERT_EQ(name2.compare("Axe"), 0);
	ASSERT_EQ(name3.compare("Baton"), 0);

	EXPECT_FALSE(eq1.isArtefact());
	EXPECT_FALSE(eq2.isArtefact());
	EXPECT_FALSE(eq3.isArtefact());
	eq1.set_name("New Sword");

	ASSERT_EQ(eq1.get_name().compare("New Sword"), 0);
	ASSERT_EQ(eq1.use("Enemy"), 8);
	ASSERT_EQ(eq2.use("Enemy"), 9);
	ASSERT_EQ(eq3.use("Enemy"), 10);
}

/*
TEST(TestHero, Testall) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}



TEST(TestArtefactedCharmedWeapon, Testall) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST(TestArtefactedEquipment, Testall) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST(TestArtefactedWeapon, Testall) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST(TestCharmedWeapon, Testall) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}*/