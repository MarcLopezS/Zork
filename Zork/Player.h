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
	void inventory();
	void take(std::vector<std::string>& argUser);
	void drop(const std::string& nameItem);
	void put(const std::vector<std::string>& argUser);
	void open(const std::string& nameEntityToOpen);

	Item* findContainerItem(const std::string& nameItem);

	Room* location;
};

#endif //Player_h