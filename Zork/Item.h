#ifndef Item_h
#define Item_h

#include "Entity.h"

class Exit;

class Item : public Entity
{
public:

	Item(const std::string& nameItem, const std::string& descriptItem, Entity* parentItem, bool isAContainer, Exit* keyDoor = nullptr, int valueItem = 0);
	~Item();

	void look() override;

	bool isItemAContainer;
	int valuePoints;
	Exit* exitToUnlock;
};

#endif //Item_h

