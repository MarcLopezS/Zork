#include "Entity.h"

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
