#include "Player.h"

Player::Player()
{
	m_name         = "";
	m_exp          = 0;
	m_location     = nullptr;
	m_strength     = 6;
	m_dexterity    = 5;
	m_constitution = 5;
	m_health       = getMaxHealth();
    m_levelexp     = 20;
    m_level        = 1;
    m_kills        = 0;
    m_money        = 0;
    m_inv.setMaxSize(15);

    m_godmode      = false;
	
	m_headarmor    = nullptr;
	m_chestarmor   = nullptr;
	m_handarmor    = nullptr;
	m_legarmor     = nullptr;
    m_feetarmor    = nullptr;
	m_weapon       = nullptr;
	m_shield       = nullptr;
}

Player::Player(std::string name, Room* start) : m_location(start)
{	
	m_name         = name;
	m_exp          = 0;
	m_location     = start;
	m_strength     = 6;
	m_dexterity    = 5;
	m_constitution = 5;
	m_health       = getMaxHealth();
    m_levelexp     = 20;
    m_level        = 1;
    m_kills        = 0;
    m_money        = 0;
    m_inv.setMaxSize(15);

    m_godmode      = false;
	
	m_headarmor    = nullptr;
	m_chestarmor   = nullptr;
	m_handarmor    = nullptr;
	m_legarmor     = nullptr;
    m_feetarmor    = nullptr;
	m_weapon       = nullptr;
	m_shield       = nullptr;
}


Player::~Player(void)
{
}



Item* Player::getEquipment(int slot)
{
    switch(slot)
    {
    case(0): 
        if(m_headarmor != nullptr)
            return m_headarmor;
        break;
    case(1): 
        if(m_chestarmor != nullptr)
            return m_chestarmor;
        break;
    case(2): 
        if(m_handarmor != nullptr)
            return m_handarmor;
        break;
    case(3): 
        if(m_legarmor != nullptr)
            return m_legarmor;
        break;
    case(4): 
        if(m_feetarmor != nullptr)
            return m_feetarmor;
		break;
    case(5): 
        if(m_weapon != nullptr)
            return m_weapon;
        break;
    case(6): 
        if(m_shield != nullptr)
            return m_shield;
        break;
    default: return nullptr;
        break;
    }

    return nullptr;
}

bool Player::isEquipped(int location)
{
    switch(location)
    {
    case(0): return m_headarmor != nullptr;
    case(1): return m_chestarmor != nullptr;
    case(2): return m_handarmor != nullptr;
    case(3): return m_legarmor != nullptr;
    case(4): return m_feetarmor != nullptr;
    case(5): return m_weapon != nullptr;
    case(6): return m_shield != nullptr;
    }

    return false;
}

int Player::getBlockChance()
{
        int bc = 8;

        if(m_shield != nullptr)
        {
            bc += m_shield->getBlock();
        }
       
        //std::cout << "Debug: bc = " << bc;

        return bc;
    }

int Player::getDodgeChance()
{
    int dc = 5;
    dc += m_dexterity/2;
    
    if(m_shield != nullptr)
    {
        dc += m_shield->getDodge();
    }

    if(m_headarmor != nullptr)
    {
        dc += m_headarmor->getDodge();
    }

    if(m_chestarmor != nullptr)
    {
        dc += m_chestarmor->getDodge();
    }

    if(m_handarmor != nullptr)
    {
        dc += m_handarmor->getDodge();
    }

    if(m_legarmor != nullptr)
    {
        dc += m_legarmor->getDodge();
    }

    if(m_feetarmor != nullptr)
    {
        dc += m_feetarmor->getDodge();
    }

    //std::cout << "Debug: dc = " << dc;

    return dc;
    }

void Player::checkLevel()
{
    double exp = m_exp;
    double levelexp = m_levelexp;

    if(exp/levelexp >= 1)
    {
        int extra = m_exp-m_levelexp;

        m_level += 1;
        m_exp = extra;
        m_levelexp = m_levelexp + (m_levelexp*25)/100;

        m_strength = m_strength + (m_strength*15)/100;
        m_dexterity = m_dexterity + (m_dexterity*25)/100;
        m_constitution = m_constitution + (m_constitution*25)/100;

        m_health = getMaxHealth();
        std::cout << std::endl << m_name << " has gained a level!\n";
    }
}

void Player::addToHealth(int value)
{
    if(m_godmode)
        m_health = 99;
    else
        m_health += value;

    if(m_health > getMaxHealth())
    {
        m_health = getMaxHealth();
    }
}

int Player::getAttack()
{
    int temp = 0;
    temp = (m_strength*3)/5;
    if(m_weapon != nullptr)
        temp += m_weapon->getDamage();
    return temp;
}

void Player::addToInventory(Item* item)
{
    if(m_inv.addItem(item))
        std::cout << "\n*" << item->getItemName() << " has been added to your inventory.*" << std::endl;
    else
        std::cout << "\n*" << item->getItemName() << " could not be added to your inventory.*" << std::endl;
}

int Player::getDefence()
{
    int temp = 0;
    temp = (m_strength*10)/50;
    if(m_headarmor != nullptr)
        temp += m_headarmor->getDefence();
    if(m_chestarmor != nullptr)
        temp += m_chestarmor->getDefence();
    if(m_handarmor != nullptr)
        temp += m_handarmor->getDefence();
    return temp;
}

bool Player::equipItem(int index)
{
    if(m_inv.checkSlot(index) != nullptr)
    {
        if(m_inv.getItem(index)->getItemId() == 0)
        {
            Weapon* item = static_cast<Weapon*>(m_inv.getItem(index));
            m_weapon = item;
            std::cout << "\nYou equipped *" << item->getItemName();
            return true;
        }

        if(m_inv.getItem(index)->getItemId() == 1)
        {
            Armor* item = static_cast<Armor*>(m_inv.getItem(index));
            switch(item->getPlacement())
            {
            case(0): m_headarmor = item;
                std::cout << "\nYou equipped *" << item->getItemName();
                return true;
                break;
            case(1): m_chestarmor = item;
                std::cout << "\nYou equipped *" << item->getItemName();
                return true;
                break;
            case(2): m_handarmor = item;
                std::cout << "\nYou equipped *" << item->getItemName();
                return true;
                break;
            case(3): m_legarmor = item;
                std::cout << "\nYou equipped *" << item->getItemName();
                return true;
                break;
            case(4): m_feetarmor = item;
                std::cout << "\nYou equipped *" << item->getItemName();
                return true;
                break;
            case(5): m_shield = item;
                std::cout << "\nYou equipped *" << item->getItemName();
                return true;
                break;
            }
        }


    }
    printf("\n\nYou are not carrying that.");
    return false;
}

void Player::useItem(int index)
{
    //std::cout << "Debug: Getting close\n";
    if(m_inv.getItem(index)->getItemId() == 2)
    {
        Consumable* item = static_cast<Consumable*>(m_inv.removeItem(index));
        //std::cout << "Debug: Made it: Effect type = " << item->getEffect();
        
        switch(item->getEffect())
        {
        case(0): 
            addToHealth(item->getEffectStrength());
            std::cout << "Health restored by: " << item->getEffectStrength();
            std::cout << "\nNow health is: " << getHealth();
		    break;
        default: 
            std::cout << "Debug: Woops, something went wrong.\n";
            break;
        }
    }else
        std::cout << "That is not how that's used.";
}