#ifndef Creature_h
#define Creature_h

#include <vector>

#include "Entity.h"
#include "Room.h"

class Creature : public Entity
{
public:

	Creature(const std::string& nameCreature, const std::string& descriptCreature, Room* location);
	~Creature();
	
	virtual bool Go(const std::string& userCommand);
};

#endif //Creature_h

