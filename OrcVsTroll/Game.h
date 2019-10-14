#include <iostream>

#include "Character.h"
#include "Orcs.h"
#include "Troll.h"

#pragma once


class Game
{
public:

	Orc orc;
	Troll troll;
	Character* player = nullptr;
	Character* npc = nullptr;
};