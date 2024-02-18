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

	void setupGame();
	
	bool parseUserCommand(std::vector<std::string>& arguments);
	bool handleOnlyCommand(const std::string& command);
	void checkGameOver();
	void printCurrentRoom();

	std::vector<Entity*> entities;

	bool isGameOver;
	
	NameCommands nameCommand;
	Player* player;
};

#endif //World_h

