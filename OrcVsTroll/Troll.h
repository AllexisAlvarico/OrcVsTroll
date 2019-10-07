#include <iostream>
#include "Character.h"
#pragma once

class Troll : public Character{
public:
	void fly() { std::cout << "Average Dooper is flapping and flying" << std::endl; }
};