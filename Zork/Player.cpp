#include "Player.h"
#include "Room.h"
#include "Exit.h"
#include "Item.h"
#include "Global.h"
#include "NPC.h"


Player::Player(const std::string& namePlayer, const std::string descriptPlayer, Room* locationPlayer)
	:Creature(namePlayer, descriptPlayer, locationPlayer)
{
	type = EntityType::PLAYER;
	location = static_cast<Room*>(parent);
}

Player::~Player()
{
	location = nullptr;
}

void Player::go(const std::string& userCommand)
{
	//get all exit entities from room parent
	std::list<Entity*> exitList = static_cast<Room*>(parent)->findAll(EntityType::EXIT);
	
	Exit* ex;

	for (Entity* exitEntity : exitList)
	{
		ex = static_cast<Exit*>(exitEntity);

		if (ex->dirExitRoom(location) == userCommand)
		{
			if (ex->isLocked == false)
			{
				updateParent(ex->getRoomDestination(location));
				location = static_cast<Room*>(parent);
				std::cout << "I passed the " + ex->name + " and arrived to " + parent->name + "." << std::endl;
				return;
			}
			else {
				std::cout << ex->name + " is locked." << std::endl;
				return;
			}
			
		}
	}

	std::cout << "There is no door in that direction..." << std::endl;
	
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
void Player::take(const std::vector<std::string>& argUser)
{
	if (argUser[1] == argUser[3])
	{
		std::cout << "Are you serious?..." << std::endl;
		return;
	}

	Entity* itemContainer = checkContainerItem(argUser[3]);

	if (itemContainer == nullptr)
		return;
	
	if (!(static_cast<Item*>(itemContainer)->isItemAContainer))
	{
		std::cout << itemContainer->name + " is not a container..." << std::endl;
		return;
	}

	std::string nameItemToTake = argUser[1];
	Item* itemToBeTaken = static_cast<Item*>(itemContainer->findByName(nameItemToTake));

	if (itemToBeTaken == nullptr)
	{
		std::cout << "There is no item called like that in this container." << std::endl;
		return;
	}
	else {
		itemToBeTaken->updateParent(this);
		std::cout << "Taken." << std::endl;
	}
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
	
	Entity* itemContainer = checkContainerItem(argUser[3]);

	if (itemContainer == nullptr)
		return;

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

//One argument (containers)
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

//Two Arguments (unlock exits)
void Player::open(const std::vector<std::string>& argUser)
{
	std::string nameExit = argUser[1] + " " + argUser[2];
	Exit* lockedExit = static_cast<Exit*>(location->findByName(nameExit));

	if (lockedExit == nullptr)
	{
		std::cout << "There is no door in here with that name." << std::endl;
		return;
	}
	else if (lockedExit->isLocked == false)
	{
		std::cout << "The door is already opened..." << std::endl;
		return;
	}

	if(!hasKey(lockedExit))
		std::cout << "You don't have the key to open this door." << std::endl;

}

void Player::talk()
{
	NPC* npc = static_cast<NPC*>(location->findByType(EntityType::NPC));

	if (npc != nullptr)
	{
		npc->talk();
	}
	else 
	{
		std::cout << "There is no one here to talk..." << std::endl;
	}
}

Entity* Player::checkContainerItem(const std::string& nameItem)
{
	Entity* itemContainer = findByName(nameItem);

	if (itemContainer == nullptr)
	{ 
		//search container in player's location
		itemContainer = location->findByName(nameItem);

		if (itemContainer == nullptr)
		{
			std::cout << "I don't find any container with that name." << std::endl;
			return nullptr;
		}
		else if (itemContainer->type != EntityType::ITEM)
		{
			std::cout << itemContainer->name + " is not a container..." << std::endl;
			return nullptr;
		}
	}

	return itemContainer;
}

bool Player::hasKey(Exit* lockedExit)
{
	Item* item;

	//check if there is a key to open lockedExit
	for (Entity* entity : containerEntities)
	{
		item = static_cast<Item*>(entity);

		if (item->isItemAContainer)
		{
			//checks inside container
			for (Entity* itemInContainer : item->containerEntities)
			{
				if (static_cast<Item*>(itemInContainer)->exitToUnlock == lockedExit)
				{
					item = static_cast<Item*>(itemInContainer);
					break;
				}
			}
		}

		if (isExitOpened(item, lockedExit))
			return true;

	}

	return false;
}

bool Player::isExitOpened(Item* item, Exit* lockedExit)
{
	if (item->exitToUnlock == lockedExit)
	{
		lockedExit->lockUnlock();
		std::cout << "You opened " + lockedExit->name + " with " + item->name + "." << std::endl;
		return true;
	}

	return false;
}