#include "Player.h"
#include "Room.h"
#include "Exit.h"
#include "Item.h"
#include "Global.h"


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

void Player::inventory() const 
{
	std::cout << "Inventory:\n" << std::endl;

	for (Entity* entity : containerEntities)
	{
		if (entity->type == EntityType::ITEM)
		{
			std::cout << static_cast<Item*>(entity)->name << std::endl;
		}
		
	}
}

void Player::take(std::vector<std::string>& argsUser)
{
	bool isTaken = false;

	//one argument
	if (argsUser.size() == 2)
	{
		for (Entity* entityContRoom : location->containerEntities)
		{
			if (toLowerCase(entityContRoom->name) == argsUser[1])
			{
				entityContRoom->updateParent(this);
				std::cout << "Taken." << std::endl;
				isTaken = true;
				break;
			}
		}
	}
	else { //three arguments
		//TODO: implement TAKE ... FROM ...
	}
	

	if (!isTaken)
		std::cout << "There is nothing in here with that name." << std::endl;

}

Item* Player::findContainerItem(const std::string& nameItem)
{
	Item* item;

	for (Entity* entity : containerEntities)
	{
		if (entity->type == EntityType::ITEM)
		{
			item = static_cast<Item*>(entity);

			if (item->name == nameItem && item->isItemAContainer)
			{
				return item;
			}
		}
	}

	return nullptr;
}