#ifndef Item_h
#define Item_h

#include "Entity.h"

class Item : public Entity
{
public:

	Item(const std::string& nameItem, const std::string& descriptItem, Entity* parentItem, bool isAContainer, int valueItem = 0);
	~Item();

	void look() override;

	bool isItemAContainer;
	int valuePoints;
};

#endif //Item_h

