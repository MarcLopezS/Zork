#ifndef Player_h
#define Player_h

#include "Creature.h"

class Item;

class Player : public Creature
{
public:

	Player(const std::string& namePlayer, const std::string descriptPlayer, Room* locationPlayer);
	~Player();

	bool go(const std::string& userCommand);
	void look();
	void inventory() const;
	void take(std::vector<std::string>& argUser);
	void drop(const std::string& nameItem);

	Item* findContainerItem(const std::string& nameItem);

	Room* location;
};

#endif //Player_h