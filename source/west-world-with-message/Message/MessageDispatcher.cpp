//
//  MessageDispatcher.cpp
//  ai-game
//
//  Created by wucy on 16/7/2.
//  Copyright © 2016年 wucy. All rights reserved.
//

#include <iostream>
#include "MessageDispatcher.h"
#include "Telegram.h"
#include "../Time/CrudeTimer.h"
#include "../BaseGameEntity.h"
#include "../EntityManager.h"
#include "../EntityNames.h"
#include "../MessageType.h"

MessageDispatcher* MessageDispatcher::getInstance()
{
    static MessageDispatcher instance;
    return &instance;
}

void MessageDispatcher::Discharge(BaseGameEntity *pReceiver, const Telegram &msg) {
	if (!pReceiver->HandleMessage(msg)) {
		std::cout << "Message not handled";
	}
}

void MessageDispatcher::DispatchMsg(double delay, int sender, int receiver,
	int msg, void* ExtralInfo)
{
	BaseGameEntity* pSender = EntityMgr->GetEntityFromID(sender);
	BaseGameEntity* pReceiver = EntityMgr->GetEntityFromID(receiver);

	if (pReceiver == NULL)
	{
		std::cout << "\nWarning! No Receiver with ID of " << receiver << " found";

		return;
	}

	Telegram telegram(0, sender, receiver, msg, ExtralInfo);

	//if there is no delay, route telegram immediately                       
	if (delay <= 0.0f)
	{
		std::cout << "\nInstant telegram dispatched at time: " << Clock->GetCurrentTime()
			<< " by " << GetNameOfEntity(pSender->ID()) << " for " << GetNameOfEntity(pReceiver->ID())
			<< ". Msg is " << MsgToStr(msg);
 
		 Discharge(pReceiver, telegram);
	}
}

void MessageDispatcher::DispatchDelayedMessages()
{
	double CurrentTime = Clock->GetCurrentTime();

	while (!PriorityQ.empty() && PriorityQ.begin()->DispatchTime < CurrentTime
		&& PriorityQ.begin()->DispatchTime > 0) {

		const Telegram& msg = *PriorityQ.begin();

		BaseGameEntity* pReceiver = EntityMgr->GetEntityFromID(msg.Receiver);

		std::cout << "\nQueued telegram ready for dispatch: Sent to "
			<< GetNameOfEntity(pReceiver->ID()) << ". Msg is " << MsgToStr(msg.Msg);
 
		Discharge(pReceiver, msg);
 
		PriorityQ.erase(PriorityQ.begin());
 
	}
}

