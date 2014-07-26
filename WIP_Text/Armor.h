#ifndef _ARMOR
#define _ARMOR

#include "Item.h"

class Armor : public Item
{
public:
	Armor(void);
	Armor(std::string name, int placement, int defence, int blockchance, int dodgechance, int price, int rarity);
	virtual ~Armor(void);

    int getPlacement(){return m_placement;};
    int getDefence(){return m_defence;};
    int getBlock(){return m_blockchance;};
    int getDodge(){return m_dodgechance;};
	//void useItem(Player& player);

private:
	int m_defence;
    int m_blockchance;
    int m_dodgechance;
	int m_placement; //0 = head, 1 = chest, 2 = hands, 3 = legs, 4 = feet, 5 = shield
};
#endif

