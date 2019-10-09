#include <iostream>
#include "Character.h"
#pragma once

class Troll : public Character{

private:
	int m_health;
	int m_armorClass;
	int m_class;

public:
	void fly() { std::cout << "Average Dooper is flapping and flying" << std::endl; }
	void walk();
	void defend();
	void item();
};