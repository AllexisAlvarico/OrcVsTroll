#include <iostream>
#pragma once


class Character {
public:
	void flip() { std::cout << "I know how to flip and I will flipping do it" << std::endl; }
	virtual void walk() { std::cout << "just in case they are too young to walk yet" << std::endl; }
	virtual void fly() = 0; //pure virtual function
};