#include "BattleSystem.h"


BattleSystem::BattleSystem(Player* player, Input* input)
{
	m_player = player;
    m_input = input;
}

//Return true if player wins battle else false
bool BattleSystem::battle(Enemy enemy, Inventory* inv)
{
	srand(time(0));

    enemy.randomizeStats(m_player->getLevel());

	bool choose = false;
	bool battle = true;

	int dodgechance = 0;
    int blockchance = 0;

    int blockcounter = 0;
	int dodgecounter = 0;
	int attackcounter = 0;

	int option = 0;

	while(battle)
	{
        choose = false;
		while(!choose)
		{
            option = 0;
			std::cout << "\n------------------------------\n";

            //Debug stuff
            /*std::cout << "Attacks = " << attackcounter
                      << " || Dodges = " << dodgecounter 
                      << " || Blocks = " << blockcounter << std::endl << std::endl;
            */
            std::cout << "\nDamage:      " << m_player->getAttack();
            std::cout << "\nDefence:     " << m_player->getDefence();
            std::cout << "\nDodgechance: " << m_player->getDodgeChance();
            std::cout << "\nBlockchance: " << m_player->getBlockChance();

			std::cout << "\nPlayer: Health{" << m_player->getHealth() << "}" << std::endl;
			std::cout << "Enemy: Health{" << enemy.getHealth() << "}" << std::endl;
			std::cout << "1. Attack\n";
			std::cout << "2. Block\n";
            std::cout << "3. Item\n";
            
            option = m_input->getSelection();
			std::cout << std::endl;

			switch(option)
			{
			case 1: enemy.addToHealth(-1*m_player->getAttack());
				choose = true;
				break;
            case 2: m_player->addToHealth((m_player->getConstitution()*30)/100);
                blockchance = 8;
				choose = true;
				break;
            case(3): m_input->parseCommand("use");
                choose = true;
                break;
			default: std::cout << "\n\nError: Option not acceptable!\n\n";
                break;
			}
		}
		
        if(enemy.getHealth() <= 0)
		{
			std::cout << std::endl << enemy.getName() << " has been defeated!\n";
            m_player->incKills();
			m_player->incExp(enemy.getExpWorth());
            m_player->addMoney(enemy.getGoldWorth());
			std::cout << "Player exp: " << m_player->getExp() << std::endl;
            m_player->checkLevel();
            m_player->addToInventory(inv->getItem(rand()%inv->getSize()));
            std::cin.get();
			return true;
		}

        dodgechance = m_player->getDodgeChance();
        blockchance = m_player->getBlockChance();

		attackcounter++;

        if(rand()%100 <= blockchance)
        {
            printf("You blocked the hit.");
        }else if(rand()%100 <= dodgechance)
		{
            printf("You dodged the hit.");
			dodgecounter++;
		}else
        {
            std::cout << "You were hit by enemy!" << std::endl;
            m_player->addToHealth(-1*enemy.getAttack()-(m_player->getDefence()*10)/100);
        }

        if(m_player->getHealth() <= 0)
		{
			return false;
		}

        std::cout << "\n------------------------------\n";
	}
    std::cout << "\n------------------------------\n";

    return false;
}

BattleSystem::~BattleSystem(void)
{

}
