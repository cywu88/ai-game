//
//  main.cpp
//  WestWorld
//
//  Created by wucy on 16/7/1.
//  Copyright © 2016年 wucy. All rights reserved.
//


#ifdef WIN32
#include <windows.h>
#endif


#include <iostream>
#include "MyClass.h"

#include "Miner.h"
#include "EntityNames.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    std::cout << "frist project west-world ing\n";
//    int num = MyClass::getInstance()->GetVal();

	Miner miner(ent_Miner_Bob);
	for (int i = 0; i < 20;i++)
    {
		miner.Update();
#ifdef WIN32
		Sleep(1000);
#else
        sleep(1);
#endif

    }
    char c;
    c = getchar();
    return 0;
}
