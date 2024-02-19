#ifndef Creature_h
#define Creature_h

#include <vector>

#include "Entity.h"

class Room;

class Creature : public Entity
{
public:

	Creature(const std::string& nameCreature, const std::string& descriptCreature, Room* location);
	~Creature();

	virtual void talk();
	
};

#endif //Creature_h

