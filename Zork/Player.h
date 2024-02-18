#ifndef Player_h
#define Player_h

#include "Creature.h"


class Player : public Creature
{
public:

	Player(const std::string& namePlayer, const std::string descriptPlayer, Room* locationPlayer);
	~Player();

	bool go(const std::string& userCommand);
	void look();
	void inventory() const;

	Room* location;
};

#endif //Player_h