#include <iostream>

#include "Character.h"
#include "Player.h"
#include "Orcs.h"
#include "Troll.h"
#include "Shield.h"
#include "Spell.h"
#include "Weapon.h"
#pragma once


class Game
{
public:
	Game();
	~Game();
	Orc orc;
	Troll troll;
	Character* npc = &orc;

private:

};