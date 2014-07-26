#include "Consumable.h"

Consumable::Consumable(void)
{
	setName("Consumable");
	setPrice(0);
	setRarity(0);

	m_effect         = 0;
	m_effectstrength = 0;
    m_itemid         = 2;
}

Consumable::Consumable(std::string name, int effect, int effectstrength, int price, int rarity)
{
	setName(name);
	setPrice(price);
	setRarity(rarity);
    
	m_effect         = effect;
	m_effectstrength = effectstrength;
    m_itemid         = 2;
}


Consumable::~Consumable(void)
{
}

/*
void Consumable::useItem()
{
    std::cout << "Boop";

	switch(m_effect)
	{
	case 0: 
		m_player->addToHealth(m_effectstrength);
        std::cout << "Health restored by: " << m_effectstrength;
        std::cout << "\nNow health is: " << m_player->getHealth();
		break;
	}
}*/