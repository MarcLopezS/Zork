#include "Player.h"
#include "Room.h"
#include "Exit.h"


Player::Player(const std::string& namePlayer, const std::string descriptPlayer, Room* locationPlayer)
	:Creature(namePlayer, descriptPlayer, locationPlayer)
{
	type = EntityType::PLAYER;
	location = static_cast<Room*>(parent);
}

Player::~Player()
{
}

bool Player::go(const std::string& userCommand)
{
	//get all exit entities from room parent
	std::list<Entity*> exitList = static_cast<Room*>(parent)->findAll(EntityType::EXIT);
	
	Exit* ex;

	for (Entity* exitEntity : exitList)
	{
		ex = static_cast<Exit*>(exitEntity);

		if (ex->dirExitRoom(location) == userCommand)
		{
			updateParent(ex->getRoomDestination(location));
			location = static_cast<Room*>(parent);
			std::cout << "I passed the " + ex->name + " and arrived to " + parent->name + "." << std::endl;
			return true;
		}
	}

	std::cout << "There is no door in that direction..." << std::endl;

	return false;
	
}

void Player::look()
{
	location->look();
}
