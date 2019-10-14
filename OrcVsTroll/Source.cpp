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
	bool m_npcTurn = false;
	bool m_defeat = false;
	bool m_win = false;
	int m_playerHealth = 0;
	int m_npcHealth = 0;
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
				m_playerHealth = game.player->health();
				m_npcHealth = game.npc->health();
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
				m_playerHealth = game.player->health();
				m_npcHealth = game.npc->health();
				m_fighting = true;
			}
			else if (m_pick == 2)
			{
				m_orcGame = false;
				m_raceChoice = true;
				std::cout << "You have died to an Orc attacker for being inactive....\n";
				system("PAUSE");
			}

		}
	}

	while (m_fighting)
	{
		if (!m_playerHealth <= 0)
		{
			if (m_playerTurn)
			{
				m_damage = 0;
				m_damage = game.player->fight();
				m_npcHealth = m_npcHealth - m_damage;
				std::cout << "Player's health: " << m_playerHealth << "\nEnemy's Health: " << m_npcHealth << std::endl;
				system("PAUSE");
				m_playerTurn = false;
				m_npcTurn = true;
			}
		}

		if (m_playerHealth < 0)
		{
			m_defeat = true;
			m_fighting = false;
			break;
		}

		if (!m_npcHealth <= 0)
		{
			if (m_npcTurn)
			{
				m_damage = 0;
				m_damage = game.npc->AI();
				m_playerHealth = m_playerHealth - m_damage;
				std::cout << "Player's health: " << m_playerHealth << "\nEnemy's Health: " << m_npcHealth << std::endl;
				system("PAUSE");
				m_npcTurn = false;
				m_playerTurn = true;
			}
		}

		if (m_npcHealth < 0)
		{
			m_win = true;
			m_fighting = false;
			break;
		}
	}


	if (m_win)
	{
		system("CLS");
		std::cout << "You have defeated your enemy You win!!!!\n";
	}

	if (m_defeat)
	{
		std::cout << "You had been defeated by your enemy\n";
	}
	




	system("PAUSE");
}
 