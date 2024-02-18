#include "Item.h"

Item::Item(const std::string& nameItem, const std::string& descriptItem, Entity* parentItem, bool isAContainer, int valueItem)
	:Entity(nameItem, descriptItem, parentItem)
{
	type = EntityType::ITEM;
	isItemAContainer = isAContainer;
	valuePoints = valueItem;
}

Item::~Item()
{
}

void Item::look()
{
	std::cout << "Item: " + name + "\n" + description << std::endl;
}
