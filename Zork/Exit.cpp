#include "Exit.h"
#include "Room.h"


Exit::Exit(const std::string& dir, const std::string& nameExit, const std::string& descriptionExit, Entity* parent1, Entity* parent2, bool exitLocked)
	:Entity(nameExit, descriptionExit,parent1)
{
	type = EntityType::EXIT;

	dirSource = dir;
	detectOpositeDir(dir);
	isLocked = exitLocked;

	source = static_cast<Room*>(parent1);
	destination = static_cast<Room*>(parent2);

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

std::string Exit::dirExitRoom(Room* room)
{
	std::string dir;

	if (room == source)
		dir = dirSource;
	else if (room == destination)
		dir = dirDestination;

	return dir;	
}

Room* Exit::getRoomDestination(Room* room)
{
	if (room == source)
		return destination;
	else if (room == destination)
		return source;

	return nullptr; //if not found
}
