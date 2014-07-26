#include "Weapon.h"

Weapon::Weapon(void)
{
	setName("Weapon");
	m_hold = false;
	m_precision = 0;
	m_damage = 0;
	setPrice(0);
	setRarity(0);
    m_itemid = 0;
}

Weapon::Weapon(std::string name, bool hold, int precision, int damage, int price, int rarity)
{
	setName(name);
	m_hold = hold;
	m_precision = precision;
	m_damage = damage;
	setPrice(price);
	setRarity(rarity);
    m_itemid = 0;
}


Weapon::~Weapon(void)
{
}
