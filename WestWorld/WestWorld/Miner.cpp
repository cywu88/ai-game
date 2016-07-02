//
//  Miner.cpp
//  WestWorld
//
//  Created by wucy on 16/7/1.
//  Copyright © 2016年 wucy. All rights reserved.
//

#include "Miner.h"


Miner::Miner(int ID)
    :BaseGameEntity(ID)
{
}

void Miner::Update(){
    
}

void Miner::ChangeState(State* pNewState){
    
    if (m_pCurrentState != NULL && pNewState != NULL) {
        m_pCurrentState->Exit(this);
        
        m_pCurrentState = pNewState;
        
        m_pCurrentState->Enter(this);
    }
    
}

void Miner::AddToGoldCarried(const int val){
    m_iGoldCarried += val;
    if (m_iGoldCarried < 0) {
        m_iGoldCarried = 0;
    }
}


bool Miner::Thirsty()const{
    if (m_iThirst >= ThirstLevel) {
        return true;
    }
    return false;
}