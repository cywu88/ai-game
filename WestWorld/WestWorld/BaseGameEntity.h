//
//  BaseGameEntity.hpp
//  WestWorld
//
//  Created by wucy on 16/7/1.
//  Copyright © 2016年 wucy. All rights reserved.
//

#ifndef BaseGameEntity_hpp
#define BaseGameEntity_hpp

#include <stdio.h>

class BaseGameEntity{
private:
    int m_ID;
    
    static int m_iNextValidId;
    
    void setID(int val);
    
public:
    BaseGameEntity(int id){
        setID(id);
    }
    
    virtual ~BaseGameEntity(){}
    
    virtual void Update() = 0;
    
    int ID() const{return m_ID;}
};




#endif /* BaseGameEntity_hpp */
