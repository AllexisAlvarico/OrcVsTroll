#include <iostream>
#pragma once


class Character {
public:
	void flip() { std::cout << "I know how to flip and I will flipping do it" << std::endl; }

	virtual void action() { std::cout << "You are in the battlefied..."; }
	virtual void items() { std::cout << "AAYYYYYY"; }
	virtual void fight() { std::cout << "Fighting lol"; }
	virtual int AI() { return 0; }
	virtual int damage(int &t_damage) { return 0; }
	virtual int health() { return 0; }
	virtual void walk() { std::cout << "just in case they are too young to walk yet" << std::endl; }
};