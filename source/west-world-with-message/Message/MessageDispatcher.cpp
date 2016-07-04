//
//  MessageDispatcher.cpp
//  ai-game
//
//  Created by wucy on 16/7/2.
//  Copyright © 2016年 wucy. All rights reserved.
//

#include "MessageDispatcher.h"

#include "Telegram.h"

//#include "../../../west-world-with-mesage/BaseGameEntity.h"
#include "../BaseGameEntity.h"


MessageDispatcher* MessageDispatcher::getInstance()
{
    static MessageDispatcher instance;
    return &instance;
}

void MessageDispatcher::Discharge(BaseGameEntity *pReceiver, const Telegram &msg){
    
}