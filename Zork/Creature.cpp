#include "Creature.h"
#include "Room.h"


Creature::Creature(const std::string& nameCreature, const std::string& descriptCreature, Room* location)
	:Entity(nameCreature, descriptCreature, location)
{
	type = EntityType::CREATURE;
}

Creature::~Creature()
{
}

