#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Room.h"
#include "BattleSystem.h"
#include "Weapon.h"
#include "Armor.h"
#include "Consumable.h"
#include "Input.h"
#include "Inventory.h"
#include "Shop.h"

int main()
{
    ///////////////Initialize Items////////////////////
    Inventory worldinv;

	Weapon sword1("Worn Sword", false, 5, 3, 2, 0);
    Weapon sword2("Crude Sword", false, 5, 4, 2, 1);
    Weapon sword3("Sword", false, 5, 5, 2, 2);
    Weapon sword4("Sharpened Sword", false, 6, 3, 2, 3);

    Armor shield1("Worn City shield", 5, 1, 5, 0, 1, 0);
    Armor shield2("Crude City shield", 5, 2, 7, 0, 1, 0);
    Armor shield3("City shield", 5, 3, 9, 0, 1, 0);
    Armor shield4("Hardened City shield", 5, 4, 11, 0, 1, 0);

    Armor head1("Worn Helmet", 0, 2, 0, 0, 1, 0);
    Armor head2("Crude Helmet", 0, 3, 0, 0, 1, 0);
    Armor head3("Helmet", 0, 4, 0, 0, 1, 0);
    Armor head4("Hardened Helmet", 0, 5, 0, 2, 1, 0);

	Armor chest1("Worn Chest Plate", 1, 4, 0, 0, 2, 0);
    Armor chest2("Crude Chest Plate", 1, 5, 0, 1, 2, 0);
    Armor chest3("Chest Plate", 1, 7, 0, 2, 2, 0);
    Armor chest4("Hardened Chest Plate", 1, 8, 0, 3, 2, 0);

    Armor hands1("Worn Gloves", 2, 1, 0, 1, 1, 0);
    Armor hands2("Crude Gloves", 2, 2, 0, 1, 1, 0);
    Armor hands3("Gloves", 2, 3, 0, 2, 1, 0);
    Armor hands4("Hardened Gloves", 2, 4, 0, 3, 1, 0);

    Armor pants1("Worn Pants", 3, 2, 0, 1, 1, 0);
    Armor pants2("Crude Pants", 3, 3, 0, 1, 1, 0);
    Armor pants3("Pants", 3, 4, 0, 1, 2, 0);
    Armor pants4("Harddened Pants", 3, 5, 0, 3, 1, 0);

    Armor shoes1("Worn Shoes", 4, 2, 0, 3, 2, 0);
    Armor shoes2("Crude Shoes", 4, 3, 0, 3, 2, 0);
    Armor shoes3("Shoes", 4, 3, 0, 4, 2, 0);
    Armor shoes4("Hardened Shoes", 4, 4, 0, 6, 2, 0);

	Consumable potion1("Weak potion", 0, 10, 2, 0);
    Consumable potion2("Potion", 0, 20, 4, 1);
    Consumable potion3("Strong potion", 0, 30, 5, 2);
    
    
    worldinv.addItem(&sword1); //0
    worldinv.addItem(&sword2); //1
    worldinv.addItem(&sword3); //2
    worldinv.addItem(&sword4); //3
    
    worldinv.addItem(&shield1); //4
    worldinv.addItem(&shield2); //5
    worldinv.addItem(&shield3); //6
    worldinv.addItem(&shield4); //7
    
    worldinv.addItem(&head1); //8
    worldinv.addItem(&head2); //9
    worldinv.addItem(&head3); //10
    worldinv.addItem(&head4); //11
    
    worldinv.addItem(&chest1); //12
    worldinv.addItem(&chest2); //13
    worldinv.addItem(&chest3); //14
    worldinv.addItem(&chest4); //15

    worldinv.addItem(&pants1); //16
    worldinv.addItem(&pants2); //17
    worldinv.addItem(&pants3); //18
    worldinv.addItem(&pants4); //19

    worldinv.addItem(&shoes1); //20
    worldinv.addItem(&shoes2); //21
    worldinv.addItem(&shoes3); //22
    worldinv.addItem(&shoes4); //23

    worldinv.addItem(&potion1); //24
    worldinv.addItem(&potion2); //25
    worldinv.addItem(&potion3); //26
	///////////////////////////////////////////////////

    ///////////////////Create a shop///////////////////
    Shop shop(worldinv);
    ///////////////////////////////////////////////////

	////////////Create the map locations///////////////
	Room home("My Home", "The place I call home.", false, nullptr);
	Room store("Shop", "This areas best shop.", false, &shop);
	Room battlegrounds("Battlegrounds of The Dead", "A place where many battles have been held throughout the years.\nBe wary of lingering spirits.", true, nullptr);
    Room forestpath("Forest Path", "A whinding path that leads deep into the forest.", true, nullptr);
    Room forestgrove("Forest Grove", "A grove with a path leading to the ruins of an old castle.", true, nullptr);
    Room oldruins("Castle Ruins", "An old castle that was once the house of the Bane family.", true, nullptr);

    home.linkTo('n', store);
    home.linkTo('e', forestpath);
    home.linkTo('s', battlegrounds);

    forestpath.linkTo('w', home);
    forestpath.linkTo('e', forestgrove);

    forestgrove.linkTo('w', forestpath);
    forestgrove.linkTo('n', oldruins);

    oldruins.linkTo('s', forestgrove);

    store.linkTo('s', home);
    battlegrounds.linkTo('n', home);
	///////////////////////////////////////////////////
    
    ////////Initialize Player and BattleSystem/////////
    Input commandinput;
	Player player("Titus", &home);

    bool choose = false;
    int option = 0;
	while(!choose)
	{
	    std::cout << "\n------------------------------\n";

		std::cout << "1. New Game\n";
		std::cout << "2. Load Game\n";
            
        option = commandinput.getSelection();
		std::cout << std::endl;
        std::cout << "\n------------------------------\n";

        if(option == 1)
        {
            choose = true;
            std::cin.get();
            printf("\nWhat is your name adventurer : ");
            std::string name = commandinput.getInput(false);
            player.setName(name);
        }

        if(option == 2)
        {
            std::cin.get();
            printf("Name of character to load: ");
            Player tempplayer = FileOperations::load(commandinput.getInput(false));
            if(tempplayer.getName() != "")
            {
                player = tempplayer;
                choose = true;
            }else
                printf("Couldn't find a save file with that name.");
        }
    }

    player.setLocation(&home);

	Player* playerptr = &player;
    commandinput.setPlayer(playerptr);

	BattleSystem battleSys(playerptr, &commandinput);
	///////////////////////////////////////////////////

	///////////////Initialize enemies//////////////////
	Enemy dummy;
    Enemy goblin;
	///////////////////////////////////////////////////

	//////////////Initialize game variables////////////
	bool game = true;
	///////////////////////////////////////////////////

    ///////////////////Start the Story/////////////////
    printf("\n\nAfter being trained by your parents for the past 19 years of your life,\n");
    printf("you are finally ready to begin your adventure. It is in your hands whether\n");
    printf("you make a name for yourself or not. As you step out your door, your parents\n");
    printf("Give you a few things a say, 'These will get you started, but always remember\n");
    printf("that fate is followed by you.'\n\n");
    std::cin.get();

    playerptr->addToInventory(worldinv.getItem(0));
    playerptr->addToInventory(worldinv.getItem(5));
    playerptr->addToInventory(worldinv.getItem(24));
    playerptr->equipItem(0);
    playerptr->equipItem(1);
    ///////////////////////////////////////////////////

	/////////////////////Main loop/////////////////////
	while(game)
	{
        std::cout << "\n==================================\n" << std::endl;
		std::cout << playerptr->getName() << std::endl << std::endl;
		std::cout << playerptr->getLocation().getName() << std::endl;
		std::cout << playerptr->getLocation().getDescription() << std::endl;
		std::cout << "\n----------------------------------\n" << std::endl;

        std::cout << "What shall I do?   :: Try {Help}\n";
		
		commandinput.parseCommand(commandinput.getInput(false));
		
		std::cout << "==================================" << std::endl;

        if(commandinput.isMovementMade() && playerptr->getLocation().isBattleOk())
		{
            std::cout << rand()%100;
            if(rand()%100 <= 75)
            {
			    battleSys.battle(dummy, &worldinv);
			    commandinput.resetBattle();
            }
		}

		if(commandinput.isBattleCalled())
		{
			battleSys.battle(dummy, &worldinv);
			commandinput.resetBattle();
		}

		if(playerptr->getHealth() <= 0)
		{
			std::cout << "\n\nFate has caught up with you. Now only eternal sleep awaits you.";
			std::cin.get();
			game = false;
		}

		if(commandinput.isQuitCalled())
		{
			std::cout << "\n\nLeaving will not help you. Fate waits for no one.";
			std::cin.get();
			game = false;
        }
	}
	return 0;
	/////////////////////////////////////////////////
}