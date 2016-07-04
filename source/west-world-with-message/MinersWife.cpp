//
//  MinnersWift.cpp
//  ai-game
//
//  Created by wucy on 16/7/3.
//  Copyright © 2016年 wucy. All rights reserved.
//

#include "MinersWife.h"

bool MinersWife::HandleMessage(const Telegram& msg)
{
    return m_pStateMachine->HandleMessage(msg);
}

void MinersWife::Update()
{
    //set text color to green
//    SetTextColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    
    m_pStateMachine->Update();
}