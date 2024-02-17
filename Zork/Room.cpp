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
		switch (type)
		{
		case EntityType::EXIT:
			std::cout << "There is a " + entity->name + " in the " + static_cast<Exit*>(entity)->dirExitRoom(this) + " side of this room." << std::endl;
			break;
		case EntityType::NPC:
			std::cout << "You see someone in this room. From first sight, seems like a " + entity->name + "." << std::endl;
			break;
		case EntityType::ITEM:
			std::cout << "There is a " + entity->name + " on the floor." << std::endl;
			break;
		default:
			break;
		}
	}
}
