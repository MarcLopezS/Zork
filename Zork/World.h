#ifndef World_h
#define World_h

#include <vector>
#include "Entity.h"

class World
{
public:
	
	World();

	bool parseUserCommand(std::vector<std::string>& arguments);
	bool handleOnlyCommand(const std::string& command);


	std::vector<Entity*> entities;
	bool isGameOver;
};

#endif //World_h

