#include <iostream>
#include "Character.h"
#pragma once


struct StatsTroll
{
	int m_health = 12;
	int m_armorClass = 8;
	int m_healthPotion = 3;
	int m_swords = 10;
	int m_staffs = 5;
	int m_daggers = 15;
	int m_bows = 10;
	int m_damage = 0;
};


class Troll : public Character{

private:
	int m_choice = 0;

public:
	StatsTroll stats;
	void fly() { std::cout << "Average Dooper is flapping and flying" << std::endl; }
	void walk();
	void fight();
	int AI();
	int damage(int t_damage);
	int health();
	void item();

};