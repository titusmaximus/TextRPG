#pragma once
#include <string>
#include "Item.h"

class Item;

class Consumable : public Item
{
public:
	Consumable(void);
	Consumable(std::string name, int effect, int effectstrength, int price, int rarity);
	virtual ~Consumable(void);

    int getEffect(){return m_effect;};
    int getEffectStrength(){return m_effectstrength;};

	void setEffect(int effect, int effectstrength){m_effect = effect; 
	                          m_effectstrength = effectstrength;};

	//void useItem() override;

private:
	int m_effect;
	int m_effectstrength;
};

