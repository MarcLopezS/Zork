#include "Entity.h"
#include "Global.h"

Entity::Entity(const std::string& nameEntity, const std::string& descriptionEntity, Entity* parentEntity)
	:name(nameEntity), description(descriptionEntity), parent(parentEntity)
{
	type = EntityType::ENTITY;

	if (parent != nullptr)
		parent->containerEntities.push_back(this);
}

void Entity::look()
{
}

std::list<Entity*> Entity::findAll(EntityType type)
{
	std::list<Entity*> allEntityType;

	for (Entity* entity : containerEntities)
	{
		if (entity->type == type)
			allEntityType.push_back(entity);
	}
	
	return allEntityType;
}

Entity* Entity::findByName(const std::string& nameEntity)
{
	for (Entity* entity : containerEntities)
	{
		if (toLowerCase(entity->name) == nameEntity)
			return entity;
	}

	return nullptr;
}


void Entity::updateParent(Entity* destinyParent)
{
	if(parent != nullptr)
		parent->containerEntities.remove(this);
	
	parent = destinyParent;
	
	if(parent != nullptr)
		parent->containerEntities.push_back(this);
}

void Entity::printAllEntitites(EntityType entityType)
{
	for (Entity* entity : containerEntities)
	{
		if (entity->type == entityType)
		{
			std::cout << entity->name << std::endl;
		}
	}
}
