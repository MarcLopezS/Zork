#ifndef World_h
#define World_h

#include <iostream>
#include <vector>
#include "Entity.h"

class World
{
public:
	
	World();

	std::vector<Entity*> entities;
	bool isGameOver;
};

#endif //World_h

