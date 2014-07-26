#pragma once
#include <iostream>
#include <ctime>
#include "Input.h"
#include "Player.h"
#include "Enemy.h"
#include "BattleSystem.h"
class BattleSystem
{
public:
	BattleSystem(Player* player, Input* input);
	bool battle(Enemy enemy, Inventory* inv);
	virtual ~BattleSystem(void);
private:
	Player* m_player;
    Input* m_input;
};

