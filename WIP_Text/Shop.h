#pragma once
#include "Inventory.h"
//#include "Input.h"
//#include "Player.h"

class Shop
{
public:
    Shop(Inventory worldinv);
    virtual ~Shop(void);

    void listItems(){m_inv.printItems();};
    Inventory getInv(){return m_inv;};

//    void showMenu(Player* player);
private:
    Inventory m_inv;
    //Input m_in();
};

