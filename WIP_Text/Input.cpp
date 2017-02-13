#include "Input.h"

Input::Input()
{
    m_input       = "";
    m_selection   = -1;
	m_player      = nullptr;
	m_quitCalled  = false;
	m_forcebattle = false;
    m_bmoved      = false;
    m_shop        = false;
}

Input::Input(Player* player)
{
	m_input       = "";
    m_selection   = -1;
	m_player      = player;
	m_quitCalled  = false;
	m_forcebattle = false;
    m_bmoved      = false;
    m_shop        = false;
}

Input::~Input(void)
{
}

int Input::getSelection()
{
    m_selection = -1;
    
    if(!(std::cin >> m_selection))
    {
        std::cin.clear();
        std::cin.ignore();
        return -1;
    }

    return m_selection;
}

std::string Input::getInput(bool parse)
{
	m_input = "";
	getline(std::cin, m_input);

    std::transform(m_input.begin(), m_input.end(), m_input.begin(), ::tolower);
	
    return m_input;
}

std::string Input::parseCommand(std::string command)
	{
        m_input = command;
		std::cout << std::endl;
		//std::cout << m_input; //Debug: Show command after it is set to lowercase

		//Debug: Jump into a battle
		if(m_input == "battle")
		{
			m_forcebattle = true;
		}

        if(m_input == "save")
        {
            FileOperations::save(m_player);
        }

        if(m_input == "help")
        {
            std::cout << "\n\n##################################\n";
            std::cout << "Commands: \n";
            std::cout << "\n    North, East, West, South: Movement";
            std::cout << "\n    Stats:                    Show player stats";
            std::cout << "\n    Map:                      List surrounding rooms";
            std::cout << "\n    Inventory:                List all items you carry";
            std::cout << "\n    Equipment:                List what you are wearing";
            std::cout << "\n    Use:                      Use an item located in your inventory";
            std::cout << "\n    Remove:                   Remove an item located in your inventory";
            std::cout << "\n    Equip:                    Equip an item from your inventory";
			std::cout << "\n    Buy:                      See what the nearby shop has to offer";
			std::cout << "\n    Sell:                     Sell some of your items at a nearby shop";
            std::cout << "\n    Battle:                   Jump into a battle";
            std::cout << "\n    Save:                     Pass your experience to the next generation";
            std::cout << "\n    Quit:                     Exit the game";
            std::cout << "\n##################################\n\n";
            std::cin.get();
        }

        if(m_input == "remove")
        {
            std::cout << "\n\n##################################\n\n";
            std::cout << m_player->getName() << "'s Inventory: {Size: " << m_player->getInventory().getMaxSize() << "}\n";
            m_player->getInventory().printItems();
            std::cout << "\n\n\nWhich item shall I remove? {0, 1, etc.} ";
            m_player->getInventory().removeItem(getSelection());
            std::cout << "\n##################################\n\n";
            std::cin.get();
        }

        if(m_input == "buy")
        {
            if(m_player->getLocation().isShop())
            {
                Shop* shop = m_player->getLocation().getShop();
                Item* item;

                std::cout << "\n\n##################################\n\n";
                std::cout << "Shop's Inventory:\n";
                std::cout << "Gold: " << m_player->getMoney() << std::endl;
                shop->listItems();
                std::cout << "\n\n\nWhich item shall I buy? {0, 1, etc.} ";

                item = shop->getInv().getItem(getSelection());

                if(!m_player->inventoryIsFull())
                {
                    if(m_player->getMoney() >= item->getItemPrice())
                    {
                        m_player->addMoney(-item->getItemPrice());
                        m_player->addToInventory(item);
                    }else
                        printf("\nYou are too poor to afford that.\n");
                }else
                    printf("\nYour inventory is already full.\n");

                std::cout << "\n##################################\n\n";
            }else
                printf("\nThere is no shop in this location.\n");

            std::cin.get();
        }

        if(m_input == "sell")
        {
            if(m_player->getLocation().isShop())
            {
                Shop* shop = m_player->getLocation().getShop();
                Item* item;

                std::cout << "\n\n##################################\n\n";
                std::cout << m_player->getName() << "'s Inventory: {Size: " << m_player->getInventory().getMaxSize() << "}\n";
                std::cout << "Gold: " << m_player->getMoney() << std::endl;
                m_player->getInventory().printItems();
                std::cout << "\n\n\nWhich item shall I sell? {0, 1, etc.} ";

                int index = getSelection();
                item = m_player->getInventory().getItem(index);

                m_player->addMoney(item->getItemPrice());
                m_player->removeFromInventory(index);
                
                std::cout << "\n##################################\n\n";
            }else
                printf("\nThere is no shop in this location.\n");

            std::cin.get();
        }

        if(m_input == "stats")
        {
            std::cout << "\n\n##################################\n";
            std::cout << m_player->getName() << "'s Stats: \n";
            std::cout << "\n    Level:         " << m_player->getLevel();
            std::cout << "\n    Exp:           " << m_player->getExp() << "/" << m_player->getLevelExp();
            std::cout << "\n    Health:        " << m_player->getHealth() << "/" << m_player->getMaxHealth();
            std::cout << "\n    Kills:         " << m_player->getKills() << std::endl;
            std::cout << "\n    Strength:      " << m_player->getStrength();
            std::cout << "\n    Dexterity:     " << m_player->getDexterity();
            std::cout << "\n    Constitution:  " << m_player->getConstitution() << std::endl;
            std::cout << "\n    Attack:        " << m_player->getAttack();
            std::cout << "\n    Defence:       " << m_player->getDefence();
            std::cout << "\n##################################\n\n";
            std::cin.get();
        }

        if(m_input == "map")
        {
            std::cout << "\n\n##################################\n";
            std::cout << "Area map: \n";

            if(m_player->getLocation().northExist())
            {
                std::cout << "\n    North:  " << m_player->getLocation().getNorth()->getName();
            }
            else
                std::cout << "\n    North: -Can't go that way-";

            if(m_player->getLocation().eastExist())
            {
                std::cout << "\n    East:   " << m_player->getLocation().getEast()->getName();
            }
            else
                std::cout << "\n    East:   -Can't go that way-";

            if(m_player->getLocation().southExist())
            {
                std::cout << "\n    South:  " << m_player->getLocation().getSouth()->getName();
            }
            else
                std::cout << "\n    South:  -Can't go that way-";

            if(m_player->getLocation().westExist())
            {
                std::cout << "\n    West:   " << m_player->getLocation().getWest()->getName();
            }
            else
                std::cout << "\n    West:   -Can't go that way-";

            std::cout << "\n##################################\n\n";
            std::cin.get();
        }

        if(m_input == "use")
        {
            std::cout << "\n\n##################################\n\n";
            std::cout << m_player->getName() << "'s Inventory: {Size: " << m_player->getInventory().getMaxSize() << "}\n";
            m_player->getInventory().printItems();
            std::cout << "\n\n\nWhich item shall I use? {0, 1, etc.} ";
            m_player->useItem(getSelection());
            std::cout << "\n##################################\n\n";
            std::cin.get();
        }

        if(m_input == "inventory")
        {
            std::cout << "\n\n##################################\n\n";
            std::cout << m_player->getName() << "'s Inventory: {Size: " << m_player->getInventory().getMaxSize() << "}\n";
            std::cout << "Gold: " << m_player->getMoney() << std::endl;
            m_player->getInventory().printItems();
            std::cout << "\n##################################\n\n";
            std::cin.get();
        }

        if(m_input == "equip")
        {
            std::cout << "\n\n##################################\n\n";
            std::cout << m_player->getName() << "'s Inventory: {Size: " << m_player->getInventory().getMaxSize() << "}\n";
            m_player->getInventory().printItems();
            std::cout << "\n\n\nWhich item shall I equip? {0, 1, etc.} ";
            m_player->equipItem(getSelection());
            std::cout << "\n##################################\n\n";
            std::cin.get();
        }

        if(m_input == "equipment")
        {
            Armor* head    = static_cast<Armor*>(m_player->getEquipment(0));
            Armor* chest   = static_cast<Armor*>(m_player->getEquipment(1));
            Armor* hand    = static_cast<Armor*>(m_player->getEquipment(2));
            Armor* legs    = static_cast<Armor*>(m_player->getEquipment(3));
			Armor* feet    = static_cast<Armor*>(m_player->getEquipment(4));
            Weapon* weapon = static_cast<Weapon*>(m_player->getEquipment(5));
            Armor* shield  = static_cast<Armor*>(m_player->getEquipment(6));
            

            std::cout << "\n\n##################################\n";
            std::cout << m_player->getName() << "'s Equipment: \n";

            if(weapon != nullptr)
                std::cout << "\n    Weapon:     " << weapon->getItemName() << "|   Attack: " << weapon->getDamage();
            else
                std::cout << "\n    Weapon:     " << "-empty";

            if(shield != nullptr)
                std::cout << "\n    Shield:     " << shield->getItemName() << "|   Defence: " << shield->getDefence() << " | Block: " << shield->getBlock();
            else
                std::cout << "\n    Shield:     " << "-empty";

            if(head != nullptr)
                std::cout << "\n    Head:       " << head->getItemName() << "|   Defence: " << head->getDefence();
            else
                std::cout << "\n    Head:       " << "-empty";

            if(chest != nullptr)
                std::cout << "\n    Chest:      " << chest->getItemName() << "|   Defence: " << chest->getDefence();
            else
                std::cout << "\n    Chest:      " << "-empty";

            if(hand != nullptr)
                std::cout << "\n    Hands:      " << hand->getItemName() << " |  Defence: " << hand->getDefence();
            else
                std::cout << "\n    Hands:      " << "-empty";

            if(legs != nullptr)
                std::cout << "\n    Legs:       " << legs->getItemName() << "|   Defence: " << legs->getDefence();
            else
                std::cout << "\n    Legs:       " << "-empty";

            if(feet != nullptr)
                std::cout << "\n    Feet:       " << feet->getItemName() << "|   Defence: " << feet->getDefence();
            else
                std::cout << "\n    Feet:       " << "-empty";
            std::cout << "\n##################################\n\n";
            std::cin.get();
        }

		if(m_input == "north")
		{
			if(m_player->getLocation().northExist())
			{
				m_player->setLocation(m_player->getLocation().getNorth());
                m_bmoved = true;
			}
			else
			{
				std::cout << "Something blocks your way." << std::endl;
                std::cin.get();
			}
		}


		if(m_input == "south")
		{
			if(m_player->getLocation().southExist())
			{
				m_player->setLocation(m_player->getLocation().getSouth());
                m_bmoved = true;
			}
			else
			{
				std::cout << "Something blocks your way." << std::endl;
                std::cin.get();
			}
		}

		if(m_input == "east")
		{
			if(m_player->getLocation().eastExist())
			{
				m_player->setLocation(m_player->getLocation().getEast());
                m_bmoved = true;
			}
			else
			{
				std::cout << "Something blocks your way." << std::endl;
                std::cin.get();
			}
		}

		if(m_input == "west")
		{
			if(m_player->getLocation().westExist())
			{
				m_player->setLocation(m_player->getLocation().getWest());
                m_bmoved = true;
			}
			else
			{
				std::cout << "Something blocks your way." << std::endl;
                std::cin.get();
			}
		}

		if(m_input == "quit")
		{
            bool choose = false;
            int option = 0;
	        while(!choose)
	        {
	            std::cout << "\n------------------------------\n";

		        std::cout << "1. Save and Exit\n";
		        std::cout << "2. Exit w/o Saving\n";
                std::cout << "3. Cancel";
            
                option = getSelection();
		        std::cout << std::endl;
                std::cout << "\n------------------------------\n";


                switch(option)
                {
                case(1): 
                    FileOperations::save(m_player);
                    m_quitCalled = true;
                    choose = true;
                    break;
                case(2):
                    m_quitCalled = true;
                    choose = true;
                    break;
                case(3):
                    choose = true;
                    break;
                default:
                    printf("\nThat is not an option.\n");
                    break;
                }
            }
		}

        //Cheats
        if(m_input == "~god")
        {
            m_player->toggleGodMode();
            std::cout << "\nYou have usurped God himself!";
            std::cin.get();
        }

        if(m_input == "~moneyrain")
        {
            m_player->addMoney(1000);
            std::cout << "\nIt is the reign of the rich!";
            std::cin.get();
        }

        std::cout << std::endl;
        return m_input;
	}