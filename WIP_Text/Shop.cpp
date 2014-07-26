#include "Shop.h"


Shop::Shop(Inventory worldinv)
{  
    //Input m_in(nullptr);
    m_inv = worldinv;
}

Shop::~Shop(void)
{
}
/*
void Shop::showMenu()
{
    Item* item;
    std::cout << "\n\n##################################\n\n";
    std::cout << "Shop's Inventory:\n";
    listItems();
    std::cout << "\n\n\nWhich item shall I buy? {0, 1, etc.} ";
    item = m_inv.getItem(m_in.getSelection());
    if(player->getMoney() >= item->getItemPrice())
    {
        player->addMoney(-item->getItemPrice());
        player->addToInventory(item);
    }else
        printf("You are too poor to afford that.");
    std::cout << "\n##################################\n\n";
    std::cin.get();
}*/


