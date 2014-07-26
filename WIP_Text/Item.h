#pragma once

#include <iostream>


class Item
{
public:
 	int getItemPrice(){return m_price;};
	int getItemRarity(){return m_rarity;};
	std::string getItemName(){return m_name;};

    //virtual void useItem(){std::cout << "It does nothing.";};

	void setPrice(int value){m_price = value;};
	void setName(std::string name){m_name = name;};
	void setRarity(int value){m_rarity = value;};

    int getItemId(){return m_itemid;};

protected:
    int m_itemid;
	int m_price;
	int m_rarity;
	std::string m_name;
};
