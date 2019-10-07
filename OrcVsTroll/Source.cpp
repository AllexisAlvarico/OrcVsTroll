#include <iostream>
#include "Game.h"

int main(void)
{
	Game game;

	std::cout << "Let go virtual" << std::endl;

	std::cout << "Let go create an Orc" << std::endl;


	game.orc.walk();
	game.orc.fly();
	game.orc.flip();

	
	std::cout << "Let go create an Troll" << std::endl;

	game.troll.walk();
	game.troll.fly();
	game.troll.flip();


	game.npc->flip();
	game.npc->fly();
	game.npc->walk();

	game.npc = &game.troll;
	game.npc->flip();
	game.npc->fly();
	game.npc->walk();

	cin.get();
}
 