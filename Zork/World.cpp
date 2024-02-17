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

	Exit* exitBedroom = new Exit(nameCommand.SOUTH_1, "Bedroom door", "This door comunicates my bedroom with the living room.", bedroom, livingRoom);
	Exit* exitBathroom = new Exit(nameCommand.WEST_1, "Bathroom door", "This door communicates my bedroom with the bathroom.", bedroom, bathroom);

	player = new Player("Marc", "The player of this game", bedroom);

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
		player->Go(nameCommand.NORTH_1);
	}
	else if (command == nameCommand.SOUTH_1 || command == nameCommand.SOUTH_2)
	{
		player->Go(nameCommand.SOUTH_1);
	}
	else if (command == nameCommand.EAST_1 || command == nameCommand.EAST_2)
	{
		player->Go(nameCommand.EAST_1);
	}
	else if (command == nameCommand.WEST_1 || command == nameCommand.WEST_2)
	{
		player->Go(nameCommand.WEST_1);
	}
	else if (command == nameCommand.UP_1 || command == nameCommand.UP_2)
	{
		player->Go(nameCommand.UP_1);
	}
	else if (command == nameCommand.DOWN_1 || command == nameCommand.DOWN_2)
	{
		player->Go(nameCommand.DOWN_1);
	}
	else {
		handleOK = false;
	}

	return handleOK;
}
