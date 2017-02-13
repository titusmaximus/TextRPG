#include "FileOperations.h"

void FileOperations::save(Player* player)
{
    //std::string filepath = "";
    Player child;
    std::string name = "";
    printf("What will your child's name be: ");
    getline(std::cin, name);
    std::transform(name.begin(), name.end(), name.begin(), ::tolower);

    /*
    child.setName(name);
    child.addMoney(player->getMoney()/3);
    child.setLevel(player->getLevel()/4);
    child.setLevelExp(child.getLevelExp()+player->getLevelExp()/3);

    child.setStrength(child.getStrength()+player->getStrength()/3);
    child.setConstitution(child.getConstitution()+player->getConstitution()/3);
    child.setDexterity(child.getDexterity()+player->getDexterity()/3);

    child.setHealth(child.getMaxHealth());

    child.setInventory(player->getInventory());
    */
    int multiplier = (2<<player->getLevel())+1;

    std::fstream outf;
    outf.open(name + ".dat", std::ios::out);
    if(outf.is_open())
    {
        outf << name << "\n";
        outf << player->getMoney() << "\n";
        outf << player->getLevel() << "\n";
        outf << child.getLevelExp()+player->getLevelExp()/multiplier << "\n";
        outf << child.getStrength()+player->getStrength()/multiplier << "\n";
        outf << child.getConstitution()+player->getConstitution()/multiplier << "\n";
        outf << child.getDexterity()+player->getDexterity()/multiplier;
        outf.close();
    }else
        printf("Could not open file for writing, sorry.");
}

Player FileOperations::load(std::string filename)
{
    Player child;
    std::string name = "";
    int n;
    int value;
    std::vector<int> values;
    std::fstream inf;
    inf.open(filename + ".dat", std::ios::in);
    if(inf.is_open())
    {
        inf >> name;
        child.setName(name);

        inf >> value;
        std::cout << value;
        child.addMoney(value);

        inf >> value;
        std::cout << value;
        child.setLevel(value);

        inf >> value;
        std::cout << value;
        child.setLevelExp(value);

        inf >> value;
        std::cout << value;
        child.setStrength(value);

        inf >> value;
        std::cout << value;
        child.setConstitution(value);

        inf >> value;
        std::cout << value;
        child.setDexterity(value);
        
        child.setHealth(child.getMaxHealth());

        inf.close();
    }
    return child;
}