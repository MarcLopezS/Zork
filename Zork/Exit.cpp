#include "Exit.h"


Exit::Exit(const std::string& dir, const std::string& nameExit, const std::string& descriptionExit, Entity* parent1, Entity* parent2)
	:Entity(nameExit, descriptionExit,parent1)
{
	dirSource = dir;
	detectOpositeDir(dir);

	source = (Room*)parent1;
	destination = (Room*)parent2;

	if (destination != nullptr)
		destination->containerEntities.push_back(this);
}
void Exit::detectOpositeDir(const std::string& dirSource)
{
	if (dirSource == nameComm.NORTH_1 || dirSource == nameComm.NORTH_2)
		dirDestination = nameComm.SOUTH_1;

	else if (dirSource == nameComm.SOUTH_1 || dirSource == nameComm.SOUTH_2)
		dirDestination = nameComm.NORTH_1;

	else if (dirSource == nameComm.EAST_1 || dirSource == nameComm.EAST_2)
		dirDestination = nameComm.WEST_1;

	else if (dirSource == nameComm.WEST_1 || dirSource == nameComm.WEST_2)
		dirDestination = nameComm.EAST_1;

	else if (dirSource == nameComm.UP_1 || dirSource == nameComm.UP_2)
		dirDestination = nameComm.DOWN_1;

	else if (dirSource == nameComm.DOWN_1 || dirSource == nameComm.DOWN_2)
		dirDestination = nameComm.UP_1;
}
