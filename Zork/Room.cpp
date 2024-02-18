#include "Room.h"
#include "Exit.h"

Room::Room(const std::string& nameRoom, const std::string& descriptionRoom)
	:Entity(nameRoom,descriptionRoom,nullptr)
{
	type = EntityType::ROOM;
}

Room::~Room()
{
}

void Room::look()
{
	std::cout << description << std::endl;

	for (Entity* entity : containerEntities)
	{
		switch (entity->type)
		{
		case EntityType::EXIT:
			std::cout << "The " + entity->name + " is on the " + static_cast<Exit*>(entity)->dirExitRoom(this) + " side." << std::endl;
			break;
		case EntityType::NPC:
			std::cout << "You see someone in this room. From first sight, seems like a " + entity->name + "." << std::endl;
			break;
		case EntityType::ITEM:
			std::cout << "A " + entity->name + " remains on the floor." << std::endl;
			break;
		default:
			break;
		}
	}
}

