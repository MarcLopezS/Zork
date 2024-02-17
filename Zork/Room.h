#ifndef Room_h
#define Room_h

#include "Entity.h"

class Room : public Entity
{
	Room(const std::string& nameRoom, const std::string& descriptionRoom);
	~Room();

	void look() override;
};

#endif //Room_h

