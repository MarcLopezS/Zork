
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
        std::cout << "\n--------------------------------------\n";
        world.printCurrentRoom();
        std::cout << "--------------------------------------\n";
        
        world.checkFirstTimeRoom();

        std::cout << ">> ";

        std::getline(std::cin, input);
        std::cout << "\n";

        input = toLowerCase(input);

        userCommands = tokenize(input);

        if (!world.parseUserCommand(userCommands))
            std::cout << "That's not a command I recognise or have been used in the wrong way.\n" << std::endl;
        
        world.playerReachRoomEnd();
    }

    std::cout << "\nThank you for playing!" << std::endl;

    std::cout << "\nPress any key to exit game." << std::endl;

    std::getline(std::cin, input);

    return 0;
}


