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

int main(int argc, const char * argv[]) {
    std::cout << "behavior tree ing\n";
 
	for (int i = 0; i < 20;i++)
    {
		 
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
