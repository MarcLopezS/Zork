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

void Player::inventory() 
{
	std::cout << "Inventory:\n" << std::endl;

	printAllEntitites(EntityType::ITEM);
}

//One argument
void Player::take(const std::string& nameItem)
{
	Entity* entityToTake = location->findByName(nameItem);

	if (entityToTake != nullptr && entityToTake->type == EntityType::ITEM)
	{
		entityToTake->updateParent(this);
		std::cout << "Taken." << std::endl;
	}
	else {
		std::cout << "There is no item in here with that name." << std::endl;
	}
}

//Three arguments
void Player::take(const std::vector<std::string>& argsUser)
{
	//TODO: WITH 3 ARGUMENTS

	/*bool isTaken = false;
	Entity* entityToTake;

	entityToTake = location->findByName(argsUser[1]);
		
	if (entityToTake != nullptr && entityToTake->type == EntityType::ITEM)
	{
		entityToTake->updateParent(this);
		isTaken = true;
		std::cout << "Taken." << std::endl;
	}
	else {
		std::cout << "There is no item in here with that name." << std::endl;
		return;
	}
	
	if(argsUser.size() == 4) { 
		
		Entity* itemContainer = findByName(argsUser[3]);
		
		if (itemContainer == nullptr)
		{ //search container in player's location

			itemContainer = location->findByName(argsUser[3]);

			if (itemContainer == nullptr)
			{
				std::cout << "I don't find any container with that name." << std::endl;
				return;
			}
			else if (itemContainer->type != EntityType::ITEM)
			{
				std::cout << itemContainer->name + " is not a container..." << std::endl;
				return;
			}
		}
	}*/
}




void Player::drop(const std::string& nameItem)
{
	Entity* entity = findByName(nameItem);

	if (entity != nullptr && entity->type == EntityType::ITEM)
	{
		entity->updateParent(location);
		std::cout << "You leave " + entity->name + " on the floor." << std::endl;
	}
	else
	{
		std::cout << "I don't have anything like that to drop it." << std::endl;
	}
}

void Player::put(const std::vector<std::string>& argUser)
{
	bool isPutted = false;

	if (argUser[1] == argUser[3])
	{
		std::cout << "Are you serious?..." << std::endl;
		return;
	}

	std::string nameItemToPut = argUser[1];
	Item* itemToBePutted = static_cast<Item*>(findByName(nameItemToPut));

	if (itemToBePutted == nullptr)
	{
		std::cout << "I don't have an item called like that." << std::endl;
		return;
	}
	
	std::string nameItemContainer = argUser[3];
	Entity* itemContainer = findByName(nameItemContainer);

	if (itemContainer == nullptr)
	{ //search container in player's location

		itemContainer = location->findByName(nameItemContainer);

		if (itemContainer == nullptr)
		{
			std::cout << "I don't find any container with that name." << std::endl;
			return;
		}
		else if (itemContainer->type != EntityType::ITEM)
		{
			std::cout << itemContainer->name + " is not a container..." << std::endl;
			return;
		}
	}

	if (static_cast<Item*>(itemContainer)->isItemAContainer)
	{
		itemToBePutted->updateParent(itemContainer);
		std::cout << "Putted inside " + itemContainer->name + "." << std::endl;
	}
	else
	{
		std::cout << "I cannot put " + itemToBePutted->name + " inside " + itemContainer->name + "..." << std::endl;
	}

}

////PENDING CASE TO OPEN DOOR WITH KEY AND WITHOUT KEY (REQUIRED TWO ARGUMENTS)
void Player::open(const std::string& nameEntityToOpen)
{
	Entity* entityDestiny = findByName(nameEntityToOpen);

	if (entityDestiny == nullptr)
		entityDestiny = location->findByName(nameEntityToOpen);

	if (entityDestiny != nullptr)
	{
		if (entityDestiny->type == EntityType::ITEM && static_cast<Item*>(entityDestiny)->isItemAContainer)
		{
			std::cout << entityDestiny->name + ":\n" << std::endl;
			entityDestiny->printAllEntitites(EntityType::ITEM);
		}
		else {
			std::cout << "Are you serious? You can't open a " + entityDestiny->name + "!" << std::endl;
		}
	}
	else
	{
		std::cout << "There is nothing to open with that name" << std::endl;
	}
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