#pragma once

#include <algorithm>
#include "Room.h"
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
#include "Consumable.h"
#include "Inventory.h"

class Player
{
public:
	Player(std::string name, Room* start);
	Player();
	virtual ~Player(void);

	int getAttack();
    int getDefence();

    int getBlockChance();
    int getDodgeChance();
    
	int getStrength(){return m_strength;};
    void setStrength(int value){m_strength = value;};
    int getConstitution(){return m_constitution;};
    void setConstitution(int value){m_constitution = value;};
    int getDexterity(){return m_dexterity;};
    void setDexterity(int value){m_dexterity = value;};

	int getMaxHealth(){return 5+(m_constitution*3)/2;};
	void setHealth(int value){m_health = value;};
	int getHealth(){return m_health;};
	void addToHealth(int value);

    void setName(std::string name){m_name = name;};

    void toggleGodMode(){m_godmode = !m_godmode;};

    int getMoney(){return m_money;};
    void addMoney(int value){m_money += value;};

	int getExp(){return m_exp;};
	void setExp(int value){m_exp = value;};
	void incExp(int value){m_exp+=value;};
    int getLevel(){return m_level;};
    int getLevelExp(){return m_levelexp;};
    void setLevelExp(int exp){m_levelexp = exp;};
    void checkLevel();

    Inventory getInventory(){return m_inv;};
    void setInventory(Inventory inv){m_inv = inv;};

    void setLevel(int level){m_level = level;};

    void incKills(){m_kills++;};
    int getKills(){return m_kills;};

    int getDamageAbsorbtion();

	std::string getName(){return m_name;};

    void useItem(int index);

    bool equipItem(int index);
    bool isEquipped(int location);
    Item* getEquipment(int slot);

    void addToInventory(Item* item);
    void removeFromInventory(int index)
    {
        m_inv.removeItem(index);
    }

    bool inventoryIsFull(){return m_inv.isFull();};

	Room getLocation(){return *m_location;};
	void setLocation(Room* newLocation){m_location = newLocation;};

private:
    int m_level;
    int m_levelexp;
	int m_exp;
	int m_health;
	int m_strength;
	int m_dexterity;
	int m_constitution;
    int m_kills;
    int m_money;
    bool m_godmode;
	Room* m_location;
	std::string m_name;

    Inventory m_inv;

	Armor* m_headarmor;
	Armor* m_chestarmor;
	Armor* m_handarmor;
	Armor* m_legarmor;
    Armor* m_feetarmor;
	Weapon* m_weapon;
	Armor* m_shield;
};