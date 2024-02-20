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
	~World();

	void setupGame();
	
	bool parseUserCommand(std::vector<std::string>& arguments);
	
	bool handleOnlyCommand(const std::string& command);
	bool handleOneArgument(std::vector<std::string>& arguments);
	bool handleTwoArguments(std::vector<std::string>& arguments);
	bool handleThreeArguments(std::vector<std::string>& arguments);
	
	void printCurrentRoom() const;
	void printHelpCommand() const;
	void checkFirstTimeRoom();
	
	void playerReachRoomEnd();
	void checkGameOver();

	std::vector<Entity*> entities;

	bool isGameOver;
	std::string nameRoomGameOver;
	
	NameCommands nameCommand;
	Player* player;
	NPCsDialogues* allDialogues;
};

#endif //World_h
