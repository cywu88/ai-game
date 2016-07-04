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

//class State;
//#include "State.h"



#include "./FSM/State.h"
#include "./FSM/StateMachine.h"
using namespace FSM;
#include "./Message/Telegram.h"

const int ComfortLevel = 5;
const int MaxNuggets = 3;
const int ThirstLevel = 5;
const int TirednessThreshold = 5;


class Miner : public BaseGameEntity{
private:
//    State* m_pCurrentState;
    StateMachine<Miner>* m_pStateMachine;
    
    //旷工所处的位置
    location_type m_Location;
    
    int m_iGoldCarried;
    
    int m_iMoneyInBank;
    
    int m_iThirst;
    
    int m_iFatigue;
  
public:

    Miner(int ID);
    
    ~Miner(){delete m_pStateMachine;}
    
    void Update();
 
//    void ChangeState(State* pNewState);
    
    
// add and change
    
    virtual bool HandleMessage(const Telegram& msg);
 
    StateMachine<Miner>* GetFSM() const{return m_pStateMachine;}
    
//---no change
    
    location_type Location()const{return m_Location;}
    void ChangeLocation(const location_type loc){m_Location=loc;}
    
    int GoldCarried() const {return m_iGoldCarried;}
    void SetGoldCarried(const int val){m_iGoldCarried = val;}
    void AddToGoldCarried(const int val);
    bool PocketsFull()const{return m_iGoldCarried >= MaxNuggets;}
    
	bool Fatigued() const;
    void IncreateFatigue(){m_iFatigue += 1;}
    void DecreateFatigue(){m_iFatigue -= 1;}
    
	int Wealth() const { return m_iMoneyInBank; }
	void SetWealth(const int val) { m_iMoneyInBank = val; }
	void AddToWealth(const int val);

    
    bool Thirsty() const;
    void BuyAndDrinkAWhiskye(){m_iThirst = 0; m_iMoneyInBank -= 2;}
};


#endif /* Miner_hpp */
