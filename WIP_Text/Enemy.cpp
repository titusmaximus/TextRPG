#include "Enemy.h"
#include <iostream>
#include <ctime>

Enemy::Enemy(void)
{
	m_name = "Unknown";
	randomizeStats(0);
	m_health = getMaxHealth();
	m_expworth = 10;
	m_goldworth = 10;
}


Enemy::~Enemy(void)
{
}

void Enemy::randomizeStats(int playerlevel)
{
	srand(time(0));
	m_strength = 0;
	m_dexterity = 0;
	m_constitution = 0;

	for(int i = 0; i < 15+playerlevel/2; i++)
	{
		switch(rand()%3)
		{
		case 0: m_strength++;
			break;
		case 1: m_dexterity++;
			break;
		case 2: m_constitution++;
			break;
		}
	}
	//std::cout << "strength = " << m_strength << " | dexterity = " << m_dexterity << " | constitution = " << m_constitution << std::endl;
}

void Enemy::enemyReset()
{
	setHealth(getMaxHealth());
}
