//
//  main.cpp
//  WestWorld
//
//  Created by wucy on 16/7/1.
//  Copyright © 2016年 wucy. All rights reserved.
//
#include <windows.h>
#include <iostream>
#include "MyClass.h"

#include "Miner.h"
#include "EntityNames.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    std::cout << "study FSM ing\n";
//    int num = MyClass::getInstance()->GetVal();

	Miner miner(ent_Miner_Bob);
	for (int i = 0; i < 20;i++)
    {
		miner.Update();
		Sleep(1000);
    }
	//PressAnyKeyToContinue();
#ifdef WIN32
	char c;
	c = getchar();
#endif // WIN32
    return 0;
}
