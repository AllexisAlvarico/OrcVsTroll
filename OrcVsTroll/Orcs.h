#include <iostream>
#include "Character.h"
#pragma once

struct StatsOrcs
{
	int m_health = 10;
	int m_armorClass = 13;
	int m_healthPotion = 3;
	int m_swords = 10;
	int m_staffs = 5;
	int m_daggers = 15;
	int m_bows = 10;
	int m_damage = 0;
};



class Orc : public Character
{

public:
	StatsOrcs stats;
	int m_choice = 0;
	void action();
	void fight();
	int AI();
	int damage(int t_damage);
	int health();
	void item();
};