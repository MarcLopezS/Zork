#ifndef Room_h
#define Room_h

#include "Entity.h"


class Room : public Entity
{
public:

	Room(const std::string& nameRoom, const std::string& descriptionRoom);
	~Room();

	void look() override;
	void seeFirstTime();

	bool firstTime;

};

#endif //Room_h

