#include "Room.h"


Room::Room(void)
{
	m_name = "forrest";
	m_description = "Treeeeees!";
	m_battleOk = false;
    m_shop = nullptr;

	m_north = nullptr;
	m_south = nullptr;
	m_east = nullptr;
	m_west = nullptr;
}

Room::Room(std::string name, std::string description, bool battleOk, Shop* shop)
{
	m_description = description;

	m_name = name;

    if(shop != nullptr)
    {
        m_shop = shop;
    }
    else
    {
        m_shop = nullptr;
    }

	m_battleOk = battleOk;
	m_north = nullptr;
	m_south = nullptr;
	m_east = nullptr; 
	m_west = nullptr;
}


Room::~Room(void)
{

}

bool Room::linkTo(char direction, Room& room)
{
	switch(direction)
	{
	case 'n':
	case 'N': m_north = &room;
		return true;
	case 's':
	case 'S': m_south = &room;
		return true;
	case 'e':
	case 'E' : m_east = &room;
		return true;
	case 'w':
	case 'W': m_west = &room;
		return true;
	default: return false;
	}
}