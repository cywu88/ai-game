//
//  controls.h
//  ai-game
//
//  Created by wucy on 16/7/2.
//  Copyright © 2016年 wucy. All rights reserved.
//

#ifndef controls_h
#define controls_h

class Telegram;

namespace FSM
{

template <class entity_type>
class State
{
public:
    virtual ~State(){}
        
    virtual void Enter(entity_type*) = 0;
        
    virtual void Execute(entity_type*) = 0;
        
    virtual void Exit(entity_type*) = 0;
        
    virtual bool OnMessage(entity_type*,const Telegram&)=0;
};
};


#endif /* controls_h */
