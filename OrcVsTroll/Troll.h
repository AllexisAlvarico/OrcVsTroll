/// Login: C00242855
/// estimated time: 6hrs
/// actual time 7hrs
#include <iostream>
#include "Character.h"
#pragma once


struct StatsTroll
{
	int m_health = 12; // the orc's health
	int m_healthPotion = 3; // health potions
	int m_swords = 10; // amount swords
	int m_staffs = 5; // amount staffs
	int m_daggers = 15; // amount daggers
	int m_bows = 10; // amount bows
	int m_damage = 0; // damage holder
};


class Troll : public Character{

public:
	StatsTroll stats; // struct object
	int m_choice = 0; // AI choice
	void action(); // starting
	int fight(); // player choices
	int AI(); // AI choices
	int health(); // Troll's health
	void item(); // Troll's inventory

};