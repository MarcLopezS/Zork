#include "World.h"
#include "Global.h"
#include "Player.h"
#include "Room.h"
#include "Exit.h"


World::World()
{
	isGameOver = false;

	Room* bedroom = new Room("Bedroom", "This is my bedroom.");
	Room* livingRoom = new Room("Living Room", "This is my big living room.");
	Room* bathroom = new Room("Bathroom", "This is my beloved bathroom.");

	entities.push_back(bedroom);
	entities.push_back(livingRoom);
	entities.push_back(bathroom);

	Exit* exitBedroom = new Exit(nameCommand.SOUTH_1, "Bedroom door", "This door comunicates my bedroom with the living room.", bedroom, livingRoom);
	Exit* exitBathroom = new Exit(nameCommand.WEST_1, "Bathroom door", "This door communicates my bedroom with the bathroom.", bedroom, bathroom);
	
	entities.push_back(exitBedroom);
	entities.push_back(exitBathroom);


	player = new Player("Marc", "The player of this game", bedroom);

	entities.push_back(player);
}

bool World::parseUserCommand(std::vector<std::string>& arguments)
{
	std::string command = arguments[0];
	bool isParseOK = true;

	switch (arguments.size())
	{
	case 1: //Only Command (0 arguments)
		isParseOK = handleOnlyCommand(command);
		break;
	default:
		isParseOK = false;
		break;
	}

	return isParseOK;
}

bool World::handleOnlyCommand(const std::string& command)
{
	bool handleOK = true;

	if(command == nameCommand.NORTH_1 || command == nameCommand.NORTH_2)
	{
		player->go(nameCommand.NORTH_1);
	}
	else if (command == nameCommand.SOUTH_1 || command == nameCommand.SOUTH_2)
	{
		player->go(nameCommand.SOUTH_1);
	}
	else if (command == nameCommand.EAST_1 || command == nameCommand.EAST_2)
	{
		player->go(nameCommand.EAST_1);
	}
	else if (command == nameCommand.WEST_1 || command == nameCommand.WEST_2)
	{
		player->go(nameCommand.WEST_1);
	}
	else if (command == nameCommand.UP_1 || command == nameCommand.UP_2)
	{
		player->go(nameCommand.UP_1);
	}
	else if (command == nameCommand.DOWN_1 || command == nameCommand.DOWN_2)
	{
		player->go(nameCommand.DOWN_1);
	}
	else if (command == nameCommand.LOOK_1 || command == nameCommand.LOOK_2)
	{
		player->look();
	}
	else if (command == nameCommand.INVENTORY_1 || command == nameCommand.INVENTORY_2)
	{
		player->inventory();
	}
	else if (command == nameCommand.QUIT_1 || command == nameCommand.QUIT_2)
	{
		checkGameOver();
	}
	else
	{
		handleOK = false;
	}

	return handleOK;
}

void World::checkGameOver()
{
	isGameOver = true;
	std::cout << "GAME OVER" << std::endl;
}
