#pragma once
#include <iostream>
#include <algorithm>
#include "Player.h"
#include "Shop.h"
#include "Item.h"
#include "FileOperations.h"

class Input
{
public:
    Input();
    Input(Player* player);
	virtual ~Input(void);

    void setPlayer(Player* player){m_player = player;};

    int getSelection();
	std::string getInput(bool parse);
    std::string parseCommand(std::string command);
	void resetBattle(){m_forcebattle = false;
                       m_bmoved      = false;
                       m_shop        = false;};


    bool isMovementMade(){return m_bmoved;};
    bool isShop(){return m_shop;};
	bool isQuitCalled(){return m_quitCalled;};
	bool isBattleCalled(){return m_forcebattle;};
private:
	std::string m_input;
    int m_selection;
	Player* m_player;
	bool m_quitCalled;
	bool m_forcebattle;
    bool m_bmoved;
    bool m_shop;
};

