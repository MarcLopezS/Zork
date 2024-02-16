#ifndef Creature_h
#define Creature_h

#include "Entity.h"
#include "Room.h"

class Creature : public Entity
{
public:

	Room* location;
};

#endif //Creature_h

