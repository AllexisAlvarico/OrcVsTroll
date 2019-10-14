#include "Troll.h"

void Troll::walk()
{
}

void Troll::fight()
{
	bool m_picks = true;
	system("CLS");
	while (m_picks)
	{
		std::cout << "Attack = 1\nDefend = 2\nItems = 3";
		std::cin >> m_choice;

		if (m_choice == 1)
		{
			std::cout << "Attack:\nSword = 1, Staff = 2, Daggers = 3, Bows = 4\n";
		}

		else if (m_choice == 2)
		{
			std::cout << "You're defending\n";

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
			return stats.m_damage;
		}
		else
		{
			std::cout << "The Troll attacked you for " << stats.m_damage << std::endl;
			return stats.m_damage;
		}

	}
	//defends
	else
	{
		std::cout << "The Troll defended this turn\n";
		return 0;
	}

}

int Troll::damage(int t_damage)
{
	stats.m_health = stats.m_health - t_damage;
	return stats.m_health;
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
			std::cout << "You have healed 5 health";
			system("PAUSE");
			action();
		}
		else
		{
			std::cout << "You have no health potions";
			action();
		}
	}
	else
	{
		action();
	}
}
