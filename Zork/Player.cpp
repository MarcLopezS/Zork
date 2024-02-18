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


void Player::drop(const std::string& nameItem)
{
	bool isDropped = false;

	for (Entity* item : containerEntities)
	{
		if (toLowerCase(item->name) == nameItem)
		{
			item->updateParent(location);
			std::cout << "You leave " + item->name + " on the floor." << std::endl;
			isDropped = true;
			break;
		}
	}

	if (!isDropped)
		std::cout << "I don't have anything like that to drop it." << std::endl;
}

void Player::put(const std::vector<std::string>& argUser)
{
	std::list<Item*> itemsMentioned;
	std::string itemToBePutted = argUser[1];
	std::string itemDestiny = argUser[3];
	bool isPutted = false;

	for(Entity* item : containerEntities)
	{
		if (toLowerCase(item->name) == itemToBePutted || toLowerCase(item->name) == itemDestiny)
			itemsMentioned.push_back(static_cast<Item*>(item));
	}
	
	if (itemsMentioned.size() == 2)
	{
		if (itemsMentioned.front()->isItemAContainer && toLowerCase(itemsMentioned.front()->name) == itemDestiny)
		{
			itemsMentioned.back()->updateParent(itemsMentioned.front());
			isPutted = true;
		}
		else if (itemsMentioned.back()->isItemAContainer && toLowerCase(itemsMentioned.back()->name) == itemDestiny)
		{
			itemsMentioned.front()->updateParent(itemsMentioned.back());
			isPutted = true;
		}
		else
		{
			std::cout << "I cannot put " + itemToBePutted + " inside " + itemDestiny + "..." << std::endl;
		}
	}
	else {
		std::cout << "I cannot put anything or into anything that I don't have or see." << std::endl;
	}

	if (isPutted)
		std::cout << "Putted inside " + itemDestiny + "." << std::endl;
	
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