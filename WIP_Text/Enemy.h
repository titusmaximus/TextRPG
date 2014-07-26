#pragma once
#include <string>
class Enemy
{
public:
	Enemy(void);
	virtual ~Enemy(void);

	int getDexterity(){return m_dexterity;};
	int getAttack(){return (m_strength*3)/5;};

	int getMaxHealth(){return 5+(m_constitution*3)/2;};
	void setHealth(int value){m_health = value;};
	int getHealth(){return m_health;};
	void addToHealth(int value){m_health += value;};

	int getExpWorth(){return m_expworth;};
	int getGoldWorth(){return m_goldworth;};

	std::string getName(){return m_name;};

	void randomizeStats(int playerlevel);
	void enemyReset();

private:
	std::string m_name;
    int m_difficulty;
	int m_goldworth;
	int m_expworth;
	int m_health;
	int m_strength;
	int m_dexterity;
	int m_constitution;
};

