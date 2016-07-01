//
//  Miner.hpp
//  WestWorld
//
//  Created by wucy on 16/7/1.
//  Copyright © 2016年 wucy. All rights reserved.
//

#ifndef Miner_hpp
#define Miner_hpp

#include <stdio.h>
#include "BaseGameEntity.h"

#include "Locations.h"
#include "State.h"
//class State;

class Miner : public BaseGameEntity{
private:
    State* m_pCurrentState;
    
    //旷工所处的位置
    location_type m_Location;
    
    int m_iGoldCarried;
    
    int m_iMoneyInBank;
    
    int m_iThirst;
    
    int m_iFatigue;
    
  
    
public:
    Miner(int ID);
    
    void Update();
    
    void ChangeState(State* pNewState);
    
    location_type Location()const{return m_Location;}
    
};


#endif /* Miner_hpp */
