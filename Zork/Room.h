#ifndef Room_h
#define Room_h

#include "Entity.h"

class Exit;

class Room : public Entity
{
public:

	Room(const std::string& nameRoom, const std::string& descriptionRoom);
	~Room();

	void look() override;

	std::list<Exit*> getAllExitRoom();
};

#endif //Room_h

