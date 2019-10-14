/// Name: Allexis Alvarico
/// Login: C00242855
/// estimated time: 6hrs
/// actual time 7hrs
#include <iostream>
#pragma once


class Character {
public:
	virtual void action() { std::cout << "You are in the battlefied..."; } // A holder
	virtual void items() { std::cout << "AAYYYYYY"; } // A holder
	virtual int fight() { return 0; } // A holder
	virtual int AI() { return 0; } // A holder
	virtual int health() { return 0; } // A holder
	virtual void walk() { std::cout << "just in case they are too young to walk yet" << std::endl; } // A holder
};