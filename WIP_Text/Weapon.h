#pragma once
#include "Item.h"

class Weapon : public Item
{
public:
	Weapon(void);
	Weapon(std::string name, bool hold, int precision, int damage, int price, int rarity);
	virtual ~Weapon();

	int  getDamage(){return m_damage;};
	bool getHoldStyle(){return m_hold;};

	//void useItem(Player& player);

private:
	int m_damage;
	int m_precision;
	bool m_hold; //false = one-handed, true = two-handed
	
};
