#include "Entity.h"

Entity::Entity(const std::string& nameEntity, const std::string& descriptionEntity)
	:name(nameEntity), description(descriptionEntity)
{
	type = EntityType::ENTITY;
}

void Entity::look()
{
	std::cout << description << std::endl;
}

std::list<Entity*> Entity::findAll(EntityType type)
{
	std::list<Entity*> allEntityType;

	for (Entity* entity : container)
	{
		if (entity->type == type)
			allEntityType.push_back(entity);
	}
	
	return allEntityType;
}
