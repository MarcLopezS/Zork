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

bool Player::Go(const std::string& userCommand)
{
	std::list<Exit*> exitList = static_cast<Room*>(parent)->getAllExitRoom();

	for (Exit* exit : exitList)
	{
		if (exit->dirExitRoom(location) == userCommand)
		{
			updateParent(exit->getRoomDestination(location));
			location = static_cast<Room*>(parent);
			std::cout << "I passed the " + exit->name + " and arrived to " + parent->name + "." << std::endl;
			return true;
		}
	}

	std::cout << "There is no door in that direction..." << std::endl;

	return false;
	
}
