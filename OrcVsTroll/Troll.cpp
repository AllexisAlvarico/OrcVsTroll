/// Name: Allexis Alvarico
/// Login: C00242855
/// estimated time: 6hrs
/// actual time 7hrs
#include "Troll.h"


void Troll::action()
{
	bool m_pick = true; // set

	while (m_pick) // Check
	{
		std::cout << "You're in the battlefield.....\nYou see a Orc what do you do??\nAttack = 1 or Run = 2\n"; // display
		std::cin >> m_choice; // Player's input

		if (m_choice == 1) // Check
		{
			std::cout << "You Fight the Orc\n"; // display
			m_pick = false; // set
		}
		else if (m_choice == 2) // Check
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

int Troll::fight()
{
	bool m_picks = true; // set
	int m_attack = 0; // value set
	system("CLS");
	while (m_picks) // Check
	{
		std::cout << "Attack = 1\nDefend = 2\nItems = 3\n"; // display
		std::cin >> m_choice; // Player's input

		if (m_choice == 1) // Check
		{
			int m_chanceToHit = rand() % 10; // set random chance to hit
			std::cout << "Attack:\nSword = 1, Staff = 2, Daggers = 3, Bows = 4\n"; // display
			std::cin >> m_attack; // Player's input

			if (m_attack == 1) // Check
			{
				if (m_chanceToHit >= 5) // Check
				{
					stats.m_damage = rand() % 8 + 1; // random damage
					std::cout << "You Slash the Orc by " << stats.m_damage << " Damage" << std::endl; // display
					m_picks = false; // set
					break;
				}
				else
				{
					std::cout << "You have miss your target\n"; // display
					stats.m_damage = 0; // set
					m_picks = false; // set
					break;
				}
			}
			else if (m_attack == 2) // Check
			{
				if (m_chanceToHit >= 5) // Check
				{
					stats.m_damage = rand() % 6 + 1; // random damage
					std::cout << "You Hit the Orc by " << stats.m_damage << " Damage" << std::endl; // display
					m_picks = false; // set
					break;
				}
				else
				{
					std::cout << "You have miss your target\n"; // display
					stats.m_damage = 0; // set
					m_picks = false; // set
					break;

				}
			}
			else if (m_attack == 3) // Check
			{
				if (m_chanceToHit >= 5) // Check
				{
					stats.m_damage = rand() % 3 + 1; // random damage
					std::cout << "You Stab the Orc by " << stats.m_damage << " Damage" << std::endl; // display
					m_picks = false; // set
					break;
				}
				else
				{
					std::cout << "You have miss your target\n"; // display
					stats.m_damage = 0; // set
					m_picks = false; // set
					break;
				}
			}
			else if (m_attack == 4) // Check
			{
				if (m_chanceToHit >= 5) // Check
				{
					stats.m_damage = rand() % 4 + 1; // random damage
					std::cout << "You Hit the Orc by " << stats.m_damage << " Damage\n" << std::endl; // display
					m_picks = false; // set
					break;
				}
				else
				{
					std::cout << "You have miss your target\n"; // display
					stats.m_damage = 0; // set
					m_picks = false; // set
					break;
				}
			}
			else
			{
				std::cout << "Pick again....\n"; // display
			}
		}
		else if (m_choice == 2) // Check
		{
			std::cout << "You're defending\n"; // display
			m_picks = false; // set
			break;

		}
		else if (m_choice == 3) // Check
		{
			item(); // open function
		}
		else
		{
			std::cout << "Pick again......\n"; // display
		}

	}
	return stats.m_damage; // return
}

int Troll::AI()
{
	m_choice = rand() % 2 + 1; // random choice AI
	//Attacks
	if (m_choice == 1) // Check
	{
		int chanceToHit = rand() % 10 + 1; // random chance to hit
		if (chanceToHit >= 5) // checks
		{
			stats.m_damage = rand() % 5 + 1; // random damage
			std::cout << "The Troll attacked you for " << stats.m_damage << std::endl; // display
			
		}
		else
		{
			std::cout << "The Troll attacked and missed you!" << std::endl; // display
			stats.m_damage = 0; // set
		}
	}
	//defends
	else
	{
		std::cout << "The Troll defended this turn\n"; // display
		stats.m_damage = 0;
	}
 
	return stats.m_damage; // return
}


int Troll::health()
{
	return stats.m_health; // return
}


void Troll::item()
{
	system("CLS");
	std::cout << "items\nHealth Potions =" << stats.m_healthPotion << "\nWeapons:\nSwords: " << stats.m_swords << "\nStaffs: " << stats.m_staffs << "\nDaggers: " << stats.m_daggers << "\nBows: " << stats.m_bows << std::endl; // display
	std::cout << "Use a health potion? press = 1 or go back = 2\n"; // display
	std::cin >> m_choice; // Player's input

	if (m_choice == 1) // Check
	{
		if (stats.m_healthPotion > 0) // Check
		{
			stats.m_health += 5; // adds health
			stats.m_healthPotion--; // take potion
			std::cout << "You have healed 5 health\n"; // display
			system("PAUSE");
		}
		else
		{
			std::cout << "You have no health potions\n"; // display
		}
	}
}
