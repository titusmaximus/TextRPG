#pragma once
#include <string>
#include <vector>
#include <stdexcept> 
#include "Item.h"

class Inventory
{
public:
    Inventory();
    Inventory(int size);
    virtual ~Inventory(void);

    int getSize(){return m_slots.size();};
    void setMaxSize(int size){m_numslots = size;};
    int getMaxSize(){return m_numslots;};

    Item* checkSlot(int index);

    void printItems();
    bool isFull(){return m_slots.size() == m_numslots;};

    Item* getItem(int index){
        if(index < m_numslots || m_numslots == -1 && index >= 0)
            return m_slots[index];
        
        return nullptr;};

    bool addItem(Item* item);
    Item* removeItem(int slotnum);
private:
    std::vector<Item*> m_slots;
    int m_numslots;
};

