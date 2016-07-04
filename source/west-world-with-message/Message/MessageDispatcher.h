//
//  MessageDispatcher.hpp
//  ai-game
//
//  Created by wucy on 16/7/2.
//  Copyright © 2016年 wucy. All rights reserved.
//

#ifndef MessageDispatcher_hpp
#define MessageDispatcher_hpp

#include <stdio.h>
#include <set>
#include <string>
#include "Telegram.h"

class BaseGameEntity;

const double SEND_MSG_IMMEDIATELY = 0.0f;
const int   NO_ADDITIONAL_INFO = 0;


#define Dispatch MessageDispatcher::getInstance()


class MessageDispatcher
{
private:
    std::set<Telegram> PriorityQ;

private:
	MessageDispatcher() {}

	void Discharge(BaseGameEntity* pReceiver, const Telegram& msg);

public:
    static MessageDispatcher* getInstance();
    
    void DispatchMsg(double delay,int sender,int receiver,
                     int msg,void* ExtralInfo);
    
    void DispatchDelayedMessages();
    
};

#endif /* MessageDispatcher_hpp */
