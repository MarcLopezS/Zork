#ifndef Player_h
#define Player_h

#include "Creature.h"


class Item;
class Exit;

class Player : public Creature
{
public:

	Player(const std::string& namePlayer, const std::string descriptPlayer, Room* locationPlayer);
	~Player();

	void go(const std::string& userCommand);
	void look();
	void inventory();
	void take(const std::string& nameItem);
	void take(const std::vector<std::string>& argUser);
	void drop(const std::string& nameItem);
	void put(const std::vector<std::string>& argUser);
	void open(const std::string& nameEntityToOpen);
	void open(const std::vector<std::string>& argUser);
	void talk();

	Entity* checkContainerItem(const std::string& nameItem);
	bool hasKey(Exit* lockedExit);
	bool isExitOpened(Item* item, Exit* lockedExit);

	Room* location;
};

#endif //Player_h