#include <iostream>
#include "Character.h"
#pragma once

class Orc : public Character{
public:
	void barrelRoll() { std::cout << "rooooooolllllllllllinggggggg" << std::endl; }
	void walk() { std::cout << "Doopers have a really cool walk!" << std::endl; }
	void fly() { std::cout << "Dooper is flapping and flying" << std::endl; }
};