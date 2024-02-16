#ifndef Entity_h
#define Entity_h

#include <string>
#include <list>

enum EntityType {
	ENTITY,
	ROOM,
	EXIT,
	CREATURE,
	PLAYER,
	NPC,
	ITEM
};

class Entity
{
public:

	virtual void update();

	std::string name;
	std::string description;
	EntityType type;
	std::list<Entity*> container;
};

#endif //Entity_h
