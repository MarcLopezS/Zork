#include "World.h"
#include "Global.h"
#include "Player.h"
#include "Room.h"
#include "Exit.h"
#include "Item.h"


World::World()
{
	isGameOver = false;
	setupGame();
	
}

void World::setupGame()
{
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

	Item* photo = new Item("Photo", "This is a memory of my family going to the mountains.", bedroom, false);
	Item* bottle = new Item("Bottle", "I use this bottle for drinking outside home.", livingRoom,false);
	Item* backpack = new Item("Backpack", "My favourite backpack. It's a little worn.", bedroom, true);

	entities.push_back(photo);
	entities.push_back(bottle);

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
	case 2: //Command + 1 argument
		isParseOK = handleOneArgument(arguments);
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
		handleOK = player->go(nameCommand.NORTH_1);
	}
	else if (command == nameCommand.SOUTH_1 || command == nameCommand.SOUTH_2)
	{
		handleOK = player->go(nameCommand.SOUTH_1);
	}
	else if (command == nameCommand.EAST_1 || command == nameCommand.EAST_2)
	{
		handleOK = player->go(nameCommand.EAST_1);
	}
	else if (command == nameCommand.WEST_1 || command == nameCommand.WEST_2)
	{
		handleOK = player->go(nameCommand.WEST_1);
	}
	else if (command == nameCommand.UP_1 || command == nameCommand.UP_2)
	{
		handleOK = player->go(nameCommand.UP_1);
	}
	else if (command == nameCommand.DOWN_1 || command == nameCommand.DOWN_2)
	{
		handleOK = player->go(nameCommand.DOWN_1);
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

bool World::handleOneArgument(std::vector<std::string>& arguments)
{
	bool handleOK = true;

	if (arguments[0] == nameCommand.TAKE)
	{
		player->take(arguments);
	}
	else if (arguments[0] == nameCommand.DROP)
	{
		player->drop(arguments[1]);
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

void World::printCurrentRoom() const
{
	std::cout << player->location->name << std::endl;
}

void World::checkFirstTimeRoom()
{
	if (player->location->firstTime)
	{
		std::cout << "\n";
		player->look();
		std::cout << "\n";

		player->location->seeFirstTime();
	}
}