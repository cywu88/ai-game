//
//  State.hpp
//  WestWorld
//
//  Created by wucy on 16/7/1.
//  Copyright © 2016年 wucy. All rights reserved.
//

#ifndef State_hpp
#define State_hpp

#include <stdio.h>
//#include "Miner.h"

class Miner;
class State{
public:
    
    //很久没写cpp了，父类的析构函数一定要是实现啊。
    virtual ~State(){};
    
    virtual void Enter(Miner*) = 0;
    
    virtual void Execute(Miner *troll) = 0;
    
    virtual void Exit(Miner* ) = 0;
    
};
#endif /* State_hpp */
