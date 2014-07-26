#pragma once
#include "Player.h"
#include <iostream>
#include <fstream>
#include <algorithm>

class FileOperations
{
public:
    static void save(Player* player);
    static Player load(std::string filename);
};

