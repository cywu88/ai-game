
#include "EntityManager.h"

EntityManager* EntityManager::getInstance()
{
	static EntityManager instance;
	return &instance;
}

void EntityManager::RegisterEntity(BaseGameEntity* NewEntity)
{

}

BaseGameEntity* EntityManager::GetEntityFromID(int id) const
{
	EntityMap::const_iterator ent = m_EntityMap.find(id);

	if (ent != m_EntityMap.end()) {
		return ent->second;
	}

	return NULL;
}

void EntityManager::RemoveEntity(BaseGameEntity* pEntity)
{

}



