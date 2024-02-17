#ifndef Exit_h
#define Exit_h

#include "Entity.h"
#include "Room.h"
#include "NameCommands.h"

NameCommands nameComm;

class Exit : public Entity
{
public:

	Exit(const std::string& dir, const std::string& nameExit, const std::string& descriptionExit, Entity* parent1, Entity* parent2);

	void detectOpositeDir(const std::string& dirSource);
	std::string dirExitRoom(Room* room);

	std::string dirSource;
	std::string dirDestination;

	Room* source;
	Room* destination;

};

#endif //Exit_h

