#ifndef World_h
#define World_h

#include <iostream>
#include <vector>
#include "Entity.h"

class World
{
public:
	
	std::vector<Entity*> entities;
};

#endif //World_h

