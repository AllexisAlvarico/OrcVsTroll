/// Name: Allexis Alvarico
/// Login: C00242855
/// estimated time: 6hrs
/// actual time 7hrs
#include <iostream>
#include "Game.h"

int main(void)
{
	Game game;
	int m_race = 0; // set
	bool m_orcGame = false; // set
	bool m_trollGame = false; // set
	bool m_fighting = false; // set
	bool m_raceChoice = true; // set
	bool m_playerTurn = true; // set
	bool m_npcTurn = false; // set
	bool m_defeat = false; // set
	bool m_win = false; // set
	int m_playerHealth = 0; // set
	int m_npcHealth = 0; // set
	int m_damage = 0; // set
	int m_pick = 0; // set


	while (m_raceChoice) // checks
	{
		system("CLS");
		std::cout << "Whats your race?\nOrc = 1, Troll - 2\n"; // display
		std::cin >> m_race; // Player's input

		if (m_race == 1) // checks
		{
			game.player = &game.orc; // set the player to orc
			game.npc = &game.troll; // set the npc to orc
			m_orcGame = true; // set
			m_raceChoice = false; // set
		}
		else if (m_race == 2) // checks
		{
			game.player = &game.troll;  // set the player to troll
			game.npc = &game.orc; // set the npc to orc
			m_trollGame = true; // set
			m_raceChoice = false; // set
		}
		else
		{
			std::cout << "Error.... Pick a race again\n"; // display
		}

		if (m_orcGame) // checks
		{
			system("CLS");
			std::cout << "HA! My boy, Welcome to the Orc village, Glad your here!\nSo what do you need?? Do you want to fight some pesky Trolls or just nothing\n"; // display
			std::cout << "Fight = 1 or die = 2\n"; // display
			std::cin >> m_pick; // Player's input

			if (m_pick == 1) // checks
			{
				game.player->action();
				m_playerHealth = game.player->health();// gets the player's health
				m_npcHealth = game.npc->health(); // gets the npc's health 
				m_fighting = true; // set
			}
			else if (m_pick == 2) // checks
			{
				m_orcGame = false; // set
				m_raceChoice = true; // set
				std::cout << "You have died to a Troll attacker for being inactive....\n"; // display
				system("PAUSE");
			}

		}

		if (m_trollGame) // checks
		{
			system("CLS");
			std::cout << "HA! My boy, Welcome to the Troll village, Glad your here!\nSo what do you need?? Do you want to fight some barbarian Orc or just nothing\n"; // display
			std::cout << "Fight = 1 or die = 2\n"; // display
			std::cin >> m_pick; // Player's input

			if (m_pick == 1) // checks
			{
				game.player->action();
				m_playerHealth = game.player->health(); // gets the player's health
				m_npcHealth = game.npc->health();// gets the npc's health
				m_fighting = true; // set
			}
			else if (m_pick == 2) // checks
			{
				m_orcGame = false; // set
				m_raceChoice = true; // set
				std::cout << "You have died to an Orc attacker for being inactive....\n"; // display
				system("PAUSE");
			}

		}
	}

	while (m_fighting) // checks
	{
		if (m_playerHealth >= 0) // checks
		{
			if (m_playerTurn) // checks
			{
				m_damage = 0; // reset the damage
				m_damage = game.player->fight(); // Action
				m_npcHealth = m_npcHealth - m_damage; // damage calucation
				std::cout << "Player's health: " << m_playerHealth << "\nEnemy's Health: " << m_npcHealth << std::endl; // display
				system("PAUSE");
				m_playerTurn = false; // set
				m_npcTurn = true; // set
			}
		}

		if (m_playerHealth <= 0) // checks
		{
			m_defeat = true; // set
			m_fighting = false; // set
			break;
		}

		if (m_npcHealth >= 0) // checks
		{
			if (m_npcTurn) // checks
			{
				m_damage = 0; // reset the damage
				m_damage = game.npc->AI(); // go's to teh AI function
				m_playerHealth = m_playerHealth - m_damage; // damage calucation
				std::cout << "Player's health: " << m_playerHealth << "\nEnemy's Health: " << m_npcHealth << std::endl; // display
				system("PAUSE");
				m_npcTurn = false; // set
				m_playerTurn = true; // set
			}
		}

		if (m_npcHealth <= 0) // checks
		{
			m_win = true; // set
			m_fighting = false; // set
			break;
		}
	}


	if (m_win) // checks
	{
		system("CLS");
		std::cout << "You have defeated your enemy You win!!!!\n"; // display
	}

	if (m_defeat) // checks
	{
		std::cout << "You had been defeated by your enemy\n"; // display
	}
	




	system("PAUSE");
}
 