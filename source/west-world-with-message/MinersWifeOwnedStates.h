//
//  MinersWifeOwnedStates.hpp
//  ai-game
//
//  Created by wucy on 16/7/3.
//  Copyright © 2016年 wucy. All rights reserved.
//

#ifndef MinersWifeOwnedStates_hpp
#define MinersWifeOwnedStates_hpp

#include <stdio.h>
 

//#include "MinersWife.h"
#include "./Message/Telegram.h"

#include "./FSM/State.h"

class MinersWife;

using namespace FSM;

class WifesGlobalState : public State<MinersWife>
{
private:
	WifesGlobalState() {}
public:

	static WifesGlobalState* getInstance();

	virtual void Enter(MinersWife* wife) {}

	virtual void Execute(MinersWife* wife);

	virtual void Exit(MinersWife* wife) {}

	virtual bool OnMessage(MinersWife* wife, const Telegram& msg);

};

class DoHouseWork : public State<MinersWife>
{
private:
	DoHouseWork() {}
public:

	static DoHouseWork* getInstance();

	virtual void Enter(MinersWife* wife);

	virtual void Execute(MinersWife* wife);

	virtual void Exit(MinersWife* wife);

	virtual bool OnMessage(MinersWife* wife, const Telegram& msg);

};


class VisitBathroom : public State<MinersWife>
{
private:
	VisitBathroom() {}
 
public:
 
	static VisitBathroom* getInstance();

	virtual void Enter(MinersWife* wife);

	virtual void Execute(MinersWife* wife);

	virtual void Exit(MinersWife* wife);

	virtual bool OnMessage(MinersWife* wife, const Telegram& msg);

};

//3
class CookStew : public State<MinersWife>
{
private:
	CookStew() {}
public:
	static CookStew* getInstance();

	virtual void Enter(MinersWife* wife);

	virtual void Execute(MinersWife* wife);

	virtual void Exit(MinersWife* wife);

	virtual bool OnMessage(MinersWife* wife, const Telegram& msg);
};


#endif /* MinersWifeOwnedStates_hpp */
