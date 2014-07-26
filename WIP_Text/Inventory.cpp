#include "Inventory.h"

Inventory::Inventory()
{
    m_numslots = -1;
}

Inventory::Inventory(int size)
{
    m_numslots = size;
}


Inventory::~Inventory(void)
{
   
}

void Inventory::printItems()
{
    for(int i = 0; i < m_slots.size(); i++)
    {
        std::cout << "{" << i << "} " << m_slots[i]->getItemName() << std::endl;
    }
}

Item* Inventory::checkSlot(int index)
{
    try
    {
        Item* item = m_slots[index];
        return item;
    }catch (std::out_of_range)
    {
        return nullptr;
    }
}

bool Inventory::addItem(Item* item)
{
    if(!isFull())
    {
        m_slots.push_back(item);
        return true;
    }else
        return false;
}

Item* Inventory::removeItem(int slot)
{
    Item* temp = m_slots[slot];
    m_slots.erase(m_slots.begin() + slot);
    return temp;
}
