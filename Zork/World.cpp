#include "World.h"
#include "Global.h"

World::World()
{
	isGameOver = false;
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

	if(command == "north" || command == "n")
	{
		//TODO: player action
	}
	else {
		handleOK = false;
	}

	return handleOK;
}
