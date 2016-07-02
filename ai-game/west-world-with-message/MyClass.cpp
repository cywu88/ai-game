//
//  MyClass.cpp
//  WestWorld
//
//  Created by wucy on 16/7/1.
//  Copyright © 2016年 wucy. All rights reserved.
//

#include "MyClass.h"


MyClass* MyClass::getInstance(){
    static MyClass instance;
    return &instance;
}


MyClass::MyClass(){
    
}

MyClass::~MyClass(){
    
}



MyClass::MyClass(const MyClass&){
    
}



