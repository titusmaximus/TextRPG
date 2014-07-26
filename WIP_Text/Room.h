#pragma once
#include <string>
#include "Shop.h"
class Room
{
public:
	Room(void);
	Room(std::string name, std::string description, bool battleOk, Shop* shop);
	virtual ~Room(void);

	std::string getName(){return m_name;};
	std::string getDescription(){return m_description;};

	Room* getNorth(){return m_north;};
	Room* getSouth(){return m_south;};
	Room* getEast(){return m_east;};
	Room* getWest(){return m_west;};

    Shop* getShop(){return m_shop;};

    bool isBattleOk(){return m_battleOk;};
    bool isShop(){return m_shop != nullptr;};

	bool northExist(){return m_north != nullptr;};
	bool southExist(){return m_south != nullptr;};
	bool eastExist(){return m_east != nullptr;};
	bool westExist(){return m_west != nullptr;};

	bool linkTo(char direction, Room& room);
private:
	std::string m_description;
	std::string m_name;
	bool m_battleOk;
    Shop* m_shop;

	Room* m_north;
	Room* m_south;
	Room* m_east;
	Room* m_west;
};

