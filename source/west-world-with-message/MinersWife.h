//
//  MinnersWift.hpp
//  ai-game
//
//  Created by wucy on 16/7/3.
//  Copyright © 2016年 wucy. All rights reserved.
//

#ifndef MinnersWift_hpp
#define MinnersWift_hpp

#include <stdio.h>
#include "BaseGameEntity.h"

#include "./Message/Telegram.h"
#include "./FSM/State.h"
#include "./FSM/StateMachine.h"
using namespace FSM;



#include "Locations.h"

class MinersWife : public BaseGameEntity
{
private:
    StateMachine<MinersWife>* m_pStateMachine;
    
    location_type m_Location;
    
    bool m_bCooking;
    
public:
    
    MinersWife(int id)
    :m_Location(shack),
    m_bCooking(false),
    BaseGameEntity(id)
    {
        m_pStateMachine = new StateMachine<MinersWife>(this);
        //        m_pStateMachine = SetCurrentState(D)
    }
    
    ~MinersWife()
    {
        delete m_pStateMachine;
    }
    
    void Update();
    
    virtual bool HandleMessage(const Telegram& msg);
    
    StateMachine<MinersWife>* GetFSM()const{return m_pStateMachine;}
    
    location_type Location() const{return m_Location;}
    
    void ChangeLocation(location_type loc){m_Location = loc;}
    
    bool Cooking()const{return m_bCooking;}
    void SetCooking(bool val){m_bCooking = val;}
    
};
#endif /* MinnersWift_hpp */
