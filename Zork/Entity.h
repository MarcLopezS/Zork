#ifndef Entity_h
#define Entity_h

#include <string>
#include <list>
#include <iostream>

enum class EntityType {
	ENTITY,
	ROOM,
	EXIT,
	CREATURE,
	PLAYER,
	NPC,
	ITEM
};

class Entity
{
public:

	Entity(const std::string& nameEntity, const std::string& descriptionEntity, Entity* parentEntity);

	virtual void look();

	std::list<Entity*> findAll(EntityType type);
	Entity* findByName(const std::string& nameEntity);
	Entity* findByType(EntityType entityType);
	void updateParent(Entity* destinyParent);
	void printAllEntitites(EntityType entityType);

	std::string name;
	std::string description;
	
	EntityType type;
	
	Entity* parent;
	std::list<Entity*> containerEntities;
};

#endif //Entity_h
