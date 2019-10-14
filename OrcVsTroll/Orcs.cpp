/// Name: Allexis Alvarico
/// Login: C00242855
/// estimated time: 6hrs
/// actual time 7hrs
#include <iostream>
#include "Orcs.h"

void Orc::action()
{
	bool m_pick = true; // player's pick

	while (m_pick)
	{
		std::cout << "You're in the battlefield.....\nYou see a Troll what do you do??\nAttack = 1 or Run = 2\n"; // display
		std::cin >> m_choice; // player's input

		if (m_choice == 1) // checks
		{
			std::cout << "You Fight the Troll\n"; // display
			m_pick = false; // set
		}
		else if (m_choice == 2)
		{
			std::cout << "You ran away\n"; // display
			m_pick = false; // set
		}
		else
		{
			std::cout << "Pick again..... you don't have time\n"; // display
		}
	}
	

	system("PAUSE");
}

int Orc::fight()
{
	bool m_picks = true; // set
	int m_attack = 0; // set the value
	system("CLS"); // clear the command promt
	while (m_picks)
	{
		std::cout << "Attack = 1\nDefend = 2\nItems = 3\n"; // display
		std::cin >> m_choice; // player's input

		if (m_choice == 1) // checks
		{
			int m_chanceToHit = rand() % 10; // random hit
			std::cout << "Attack:\nSword = 1, Staff = 2, Daggers = 3, Bows = 4\n"; // display
			std::cin >> m_attack; //player's input

			if (m_attack == 1) // checks
			{
				if (m_chanceToHit >= 5) // checks
				{
					stats.m_damage = rand() % 8 + 1; // damage
					std::cout << "You Slash the Troll by " << stats.m_damage << " Damage" << std::endl; // display
					m_picks = false; // set
					break;
				}
				else
				{
					std::cout << "You have miss your target\n"; // display
					stats.m_damage = 0; // damage
					m_picks = false; // set
					break;
				}
			}
			else if (m_attack == 2) // checks
			{
				if (m_chanceToHit >= 5) // checks
				{
					stats.m_damage = rand() % 6 + 1; // damage
					std::cout << "You Hit the Troll by " << stats.m_damage << " Damage" << std::endl; // display
					m_picks = false; // set
					break;
				}
				else
				{
					std::cout << "You have miss your target\n"; // display
					stats.m_damage = 0; // damage
					m_picks = false; // set
					break;

				}
			}
			else if (m_attack == 3) // checks
			{
				if (m_chanceToHit >= 5) // checks
				{
					stats.m_damage = rand() % 3 + 1; // damage
					std::cout << "You Stab the Troll by " << stats.m_damage << " Damage" << std::endl; // display
					m_picks = false; // set
					break;
				}
				else
				{
					std::cout << "You have miss your target\n"; // display
					stats.m_damage = 0; // damage
					m_picks = false; // set
					break;
				}
			}
			else if (m_attack == 4) // checks
			{
				if (m_chanceToHit >= 5) // checks
				{
					stats.m_damage = rand() % 4 + 1; // damage
					std::cout << "You Hit the Troll by " << stats.m_damage << " Damage\n" << std::endl; // display
					m_picks = false; // set
					break;
				}
				else
				{
					std::cout << "You have miss your target\n"; // display
					stats.m_damage = 0; // damage
					m_picks = false; // set
					break;
				}
			}
			else
			{
				std::cout << "Pick again....\n"; // display
			}
		}
		else if (m_choice == 2) // checks
		{
			std::cout << "You're defending\n"; // display
			m_picks = false; // set
			break;

		}
		else if (m_choice == 3) // checks
		{
			item(); // open function
		}
		else
		{
			std::cout << "Pick again......\n"; // display
		}

	}
	return stats.m_damage;
}

int Orc::AI()
{
	m_choice = rand() % 2 + 1; // Random Pick
	//Attacks
	if (m_choice == 1) // checks
	{
		int chanceToHit = rand() % 10 + 1; // random hit
		if (chanceToHit >= 5)
		{
			stats.m_damage = rand() % 5 + 1; // damage
			std::cout << "The Orc attacked you for " << stats.m_damage << std::endl; // display

		}
		else
		{
			std::cout << "The Orc attacked and missed you!" << std::endl; // display
			stats.m_damage = 0; // damage
		}
	}
	//defends
	else
	{
		std::cout << "The Orc defended this turn\n"; // display
		stats.m_damage = 0; // damage
	}

	return stats.m_damage; // return
}

int Orc::health()
{
	return stats.m_health; // return
}

void Orc::item()
{
	system("CLS");
	std::cout << "items\nHealth Potions =" << stats.m_healthPotion << "\nWeapons:\nSwords: " << stats.m_swords<<"\nStaffs: " << stats.m_staffs << "\nDaggers: " << stats.m_daggers << "\nBows: "<< stats.m_bows << std::endl; // display
	std::cout << "Use a health potion? press = 1 or go back = 2\n"; // display
	std::cin >> m_choice; // player's input

	if (m_choice == 1) // checks
	{
		if (stats.m_healthPotion > 0) // checks
		{
			stats.m_health += 5;
			stats.m_healthPotion--;
			std::cout << "You have healed 5 health\n"; // display
			system("PAUSE"); 
		}
		else
		{
			std::cout << "You have no health potions\n"; // display
			system("PAUSE");
		}
	}

	system("CLS"); // clears the command prompt
}
