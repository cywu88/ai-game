//
//  BaseGameEntity.cpp
//  WestWorld
//
//  Created by wucy on 16/7/1.
//  Copyright © 2016年 wucy. All rights reserved.
//

#include "BaseGameEntity.h"

int BaseGameEntity::m_iNextValidId = 0;

void BaseGameEntity::setID(int val){
    m_ID = val;
    m_iNextValidId = m_ID + 1;
}