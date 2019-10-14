#include <iostream>
#include "Game.h"

int main(void)
{
	Game game;
	int m_race = 0;
	bool m_orcGame = false;
	bool m_trollGame = false;
	bool m_fighting = false;
	bool m_raceChoice = true;
	bool m_playerTurn = true;
	bool m_npcTurn = true;
	int m_damage = 0;
	int m_pick = 0;


	while (m_raceChoice)
	{
		system("CLS");
		std::cout << "Whats your race?\nOrc = 1, Troll - 2\n";
		std::cin >> m_race;

		if (m_race == 1)
		{
			game.player = &game.orc;
			game.npc = &game.troll;
			m_orcGame = true;
			m_raceChoice = false;
		}
		else if (m_race == 2)
		{
			game.player = &game.troll;
			game.npc = &game.orc;
			m_trollGame = true;
			m_raceChoice = false;
		}
		else
		{
			std::cout << "Error.... Pick a race again\n";
		}

		if (m_orcGame)
		{
			system("CLS");
			std::cout << "HA! My boy, Welcome to the Orc village, Glad your here!\nSo what do you need?? Do you want to fight some pesky Trolls or just nothing\n";
			std::cout << "Fight = 1 or die = 2\n";
			std::cin >> m_pick;

			if (m_pick == 1)
			{
				game.player->action();
				m_fighting = true;
			}
			else if (m_pick == 2)
			{
				m_orcGame = false;
				m_raceChoice = true;
				std::cout << "You have died to a Troll attacker for being inactive....\n";
				system("PAUSE");
			}

		}

		if (m_trollGame)
		{
			system("CLS");
			std::cout << "HA! My boy, Welcome to the Troll village, Glad your here!\nSo what do you need?? Do you want to fight some barbarian Orc or just nothing\n";
			std::cout << "Fight = 1 or die = 2\n";
			std::cin >> m_pick;

			if (m_pick == 1)
			{
				game.player->action();
				m_fighting = true;
			}
			else if (m_pick == 2)
			{
				m_orcGame = false;
				m_raceChoice = true;
				std::cout << "You have died to a Orc attacker for being inactive....\n";
				system("PAUSE");
			}

		}
	}


	while (m_fighting)
	{
		if (m_playerTurn)
		{
			game.player->fight();
		/*	game.npc->damage(m_damage);*/
			std::cout << "Player's health: " << game.player->health() << "\nEnemy's Health: " << game.npc->health() << std::endl;
			system("PAUSE");
			m_playerTurn = false;
			m_npcTurn = true;
		}
		if (m_npcTurn)
		{
			m_damage = game.npc->AI();
		/*	game.player->damage(m_damage);*/
			std::cout << "Player's health: " << game.player->health() - m_damage << "\nEnemy's Health: " << game.npc->health() << std::endl;
			system("PAUSE");
			m_npcTurn = false;
			m_playerTurn = true;
		}
	}

	system("PAUSE");
}
 