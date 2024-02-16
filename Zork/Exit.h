#ifndef Exit_h
#define Exit_h

#include "Entity.h"
#include "Room.h"

class Exit : public Entity
{
public:

	Room* source;
	Room* destination;
};

#endif //Exit_h

