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
	void take(const std::string& nameItem);
	void take(const std::vector<std::string>& argUser);
	void drop(const std::string& nameItem);
	void put(const std::vector<std::string>& argUser);
	void open(const std::string& nameEntityToOpen);
	void open(const std::vector<std::string>& argUser);

	Item* findContainerItem(const std::string& nameItem);

	Room* location;
};

#endif //Player_h