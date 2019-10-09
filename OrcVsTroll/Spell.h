#include <iostream>
#pragma once


class Spells
{
public:
	Spells();
	~Spells();

	int castingSpells();
	int spellBuff();
	int magicDamage();
	int mana();


private:

	int m_firebolt = 1;
	int m_eletricbolt = 2;
	int m_frost = 3;
	int m_earthenWall = 4;

	int m_fireboltDamage = 3;
	int m_eletricboltDamage = 3;
	int m_frostDamage = 3;
	int m_earthWallBuff = 2;



};
