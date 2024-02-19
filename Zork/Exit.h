#ifndef Exit_h
#define Exit_h

#include "Entity.h"
#include "NameCommands.h"

class Room;

class Exit : public Entity
{
public:

	Exit(const std::string& dir, const std::string& nameExit, const std::string& descriptionExit, Entity* parent1, Entity* parent2, bool exitLocked = false);

	void detectOpositeDir(const std::string& dirSource);
	std::string dirExitRoom(Room* room);
	Room* getRoomDestination(Room* room);

	void lockUnlock();

	std::string dirSource;
	std::string dirDestination;

	Room* source;
	Room* destination;
	NameCommands nameComm;

	bool isLocked;
};

#endif //Exit_h

