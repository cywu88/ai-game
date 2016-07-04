#pragma once

#include <map>

#include "BaseGameEntity.h"

#define EntityMgr EntityManager::getInstance()

class EntityManager
{
private:

	typedef std::map<int, BaseGameEntity*> EntityMap;

private:
	EntityMap m_EntityMap;

	EntityManager() {}
 
	//EntityManager(const EntityManager&);
	//EntityManager& operator=(const EntityManager&);
public:

	static EntityManager* getInstance();
 
	void RegisterEntity(BaseGameEntity* NewEntity);
 
	BaseGameEntity* GetEntityFromID(int id)const;
 
	void RemoveEntity(BaseGameEntity* pEntity);

};