#include <iostream>
#include "Character.h"
#include "Orcs.h"
#include "Troll.h"

#pragma once


class Game
{
public:

	Orc orc; // orc object
	Troll troll; // Troll object
	Character* player = nullptr; // the player
	Character* npc = nullptr; // the enemy 
};