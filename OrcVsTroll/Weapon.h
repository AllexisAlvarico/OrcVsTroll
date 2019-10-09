#include <iostream>
#pragma once



class Weapon
{
public:
	Weapon();
	~Weapon();

	int weapomDamage();
	int stamina();
	int attacking();

private:

	int m_swordDamage = 4;
	int m_bowDamage = 3;
	int m_daggerDamage = 2;

	int m_sword = 1;
	int m_bow = 2;
	int m_dagger = 3;


};
