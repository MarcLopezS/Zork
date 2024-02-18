#ifndef World_h
#define World_h

#include <vector>

#include "Entity.h"
#include "NameCommands.h"

class Player;

class World
{
public:
	
	World();

	bool parseUserCommand(std::vector<std::string>& arguments);
	bool handleOnlyCommand(const std::string& command);
	void checkGameOver();

	std::vector<Entity*> entities;

	bool isGameOver;
	
	NameCommands nameCommand;
	Player* player;
};

#endif //World_h

