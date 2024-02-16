
#include <iostream>
#include <string>
#include <vector>

#include "World.h"
#include "Global.h"

int main()
{
    World world;

    std::vector<std::string> userCommands;
    userCommands.reserve(10);

    std::string input;

    while (!world.isGameOver)
    {
        std::cout << ">> ";

        std::getline(std::cin, input);
        std::cout << "\n";

        userCommands = tokenize(input);

        //TODO: call function to parse the user command

    }

    return 0;
}


