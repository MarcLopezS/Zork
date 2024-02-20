#include "Item.h"
#include "Exit.h"

Item::Item(const std::string& nameItem, const std::string& descriptItem, Entity* parentItem, bool isAContainer,Exit* keyDoor, int valueItem)
	:Entity(nameItem, descriptItem, parentItem)
{
	type = EntityType::ITEM;
	isItemAContainer = isAContainer;
	valuePoints = valueItem;
	exitToUnlock = keyDoor;
}

Item::~Item()
{
	exitToUnlock = nullptr;
}

void Item::look()
{
	std::cout << "Item: " + name + "\n" + description << std::endl;
}
