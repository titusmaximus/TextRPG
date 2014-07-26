#include "Armor.h"

Armor::Armor(void)
{
	m_name        = "Armor";
	m_placement   = 0;
	m_defence     = 0;
    m_blockchance = 0;
    m_dodgechance = 0;
	m_price       = 0;
	m_rarity      = 0;
    m_itemid      = 1;
}

Armor::Armor(std::string name, int placement, int defence, int blockchance, int dodgechance, int price, int rarity)
{
	m_name        = name;
	m_placement   = placement;
	m_defence     = defence;
    m_blockchance = blockchance;
    m_dodgechance = dodgechance;
	m_price       = price;
	m_rarity      = rarity;
    m_itemid      = 1;
}


Armor::~Armor(void)
{
}
