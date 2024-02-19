#ifndef World_h
#define World_h

#include <vector>

#include "Entity.h"
#include "NameCommands.h"

class Player;
class NPCsDialogues;

class World
{
public:
	
	World();

	void setupGame();
	
	bool parseUserCommand(std::vector<std::string>& arguments);
	bool handleOnlyCommand(const std::string& command);
	bool handleOneArgument(std::vector<std::string>& arguments);
	bool handleTwoArguments(std::vector<std::string>& arguments);
	bool handleThreeArguments(std::vector<std::string>& arguments);
	void checkGameOver();
	void printCurrentRoom() const;
	void checkFirstTimeRoom();

	std::vector<Entity*> entities;

	bool isGameOver;
	
	NameCommands nameCommand;
	Player* player;
	NPCsDialogues* allDialogues;
};

#endif //World_h

