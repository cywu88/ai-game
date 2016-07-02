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


const int MaxNuggets = 3;
const int ThirstLevel = 5;


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
    void ChangeLocation(const location_type loc){m_Location=loc;}
    
    int GoldCarried() const {return m_iGoldCarried;}
    void SetGoldCarried(const int val){m_iGoldCarried = val;}
    void AddToGoldCarried(const int val);
    bool PocketsFull()const{return m_iGoldCarried >= MaxNuggets;}
    
    void IncreateFatigue(){m_iFatigue += 1;}
    void DecreateFatigue(){m_iFatigue -= 1;}
    
    
    
    bool Thirsty() const;
    void BuyAndDrinkAWhiskye(){m_iThirst = 0; m_iMoneyInBank -= 2;}
};


#endif /* Miner_hpp */
