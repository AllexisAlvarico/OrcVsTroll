#include "Troll.h"

void Troll::walk()
{
}

int Troll::fight()
{
	bool m_picks = true;
	int m_attack = 0;
	system("CLS");
	while (m_picks)
	{
		std::cout << "Attack = 1\nDefend = 2\nItems = 3\n";
		std::cin >> m_choice;

		if (m_choice == 1)
		{
			int m_chanceToHit = rand() % 10;
			std::cout << "Attack:\nSword = 1, Staff = 2, Daggers = 3, Bows = 4\n";
			std::cin >> m_attack;

			if (m_attack == 1)
			{
				if (m_chanceToHit >= 5)
				{
					stats.m_damage = rand() % 8 + 1;
					std::cout << "You Slash the Orc by " << stats.m_damage << " Damage" << std::endl;
					m_picks = false;
					break;
				}
				else
				{
					std::cout << "You have miss your target\n";
					stats.m_damage = 0;
					m_picks = false;
					break;
				}
			}
			else if (m_attack == 2)
			{
				if (m_chanceToHit >= 5)
				{
					stats.m_damage = rand() % 6 + 1;
					std::cout << "You Hit the Orc by " << stats.m_damage << " Damage" << std::endl;
					m_picks = false;
					break;
				}
				else
				{
					std::cout << "You have miss your target\n";
					stats.m_damage = 0;
					m_picks = false;
					break;

				}
			}
			else if (m_attack == 3)
			{
				if (m_chanceToHit >= 5)
				{
					stats.m_damage = rand() % 3 + 1;
					std::cout << "You Stab the Orc by " << stats.m_damage << " Damage" << std::endl;
					m_picks = false;
					break;
				}
				else
				{
					std::cout << "You have miss your target\n";
					stats.m_damage = 0;
					m_picks = false;
					break;
				}
			}
			else if (m_attack == 4)
			{
				if (m_chanceToHit >= 5)
				{
					stats.m_damage = rand() % 4 + 1;
					std::cout << "You Hit the Orc by " << stats.m_damage << " Damage\n" << std::endl;
					m_picks = false;
					break;
				}
				else
				{
					std::cout << "You have miss your target\n";
					stats.m_damage = 0;
					m_picks = false;
					break;
				}
			}
			else
			{
				std::cout << "Pick again....\n";
			}
		}
		else if (m_choice == 2)
		{
			std::cout << "You're defending\n";
			m_picks = false;
			break;

		}
		else if (m_choice == 3)
		{
			item();
		}
		else
		{
			std::cout << "Pick again......\n";
		}

	}
	return stats.m_damage;
}

int Troll::AI()
{
	m_choice = rand() % 2 + 1;
	//Attacks
	if (m_choice == 1)
	{
		int chanceToHit = rand() % 10 + 1;
		if (chanceToHit >= 5)
		{
			stats.m_damage = rand() % 5 + 1;
			std::cout << "The Troll attacked you for " << stats.m_damage << std::endl;
			
		}
		else
		{
			std::cout << "The Troll attacked and missed you!" << std::endl;
			stats.m_damage = 0;
		}
	}
	//defends
	else
	{
		std::cout << "The Troll defended this turn\n";
		stats.m_damage = 0;
	}

	return stats.m_damage;
}


int Troll::health()
{
	return stats.m_health;
}


void Troll::item()
{
	system("CLS");
	std::cout << "items\nHealth Potions =" << stats.m_healthPotion << "\nWeapons:\nSwords: " << stats.m_swords << "\nStaffs: " << stats.m_staffs << "\nDaggers: " << stats.m_daggers << "\nBows: " << stats.m_bows << std::endl;
	std::cout << "Use a health potion? press = 1 or go back = 2\n";
	std::cin >> m_choice;

	if (m_choice == 1)
	{
		if (stats.m_healthPotion > 0)
		{
			stats.m_health += 5;
			stats.m_healthPotion--;
			std::cout << "You have healed 5 health\n";
			system("PAUSE");
		}
		else
		{
			std::cout << "You have no health potions\n";
		}
	}
}
