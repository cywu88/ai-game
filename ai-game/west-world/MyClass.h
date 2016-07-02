//
//  MyClass.hpp
//  WestWorld
//
//  Created by wucy on 16/7/1.
//  Copyright © 2016年 wucy. All rights reserved.
//

#ifndef MyClass_hpp
#define MyClass_hpp

#include <stdio.h>

class MyClass{
private:
    int m_iNum;
    
    MyClass();
    
    MyClass(const MyClass&);
    
//    MyClass& operator=(const MyClass&);

public:
    ~MyClass();
    
    int GetVal() const{return m_iNum;}
    
    static MyClass* getInstance();
};

#endif /* MyClass_hpp */
