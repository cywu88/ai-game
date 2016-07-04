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

#include <time.h>
#include <iostream>
#include <fstream>
#include "Locations.h"
#include "EntityNames.h"

#include "EntityManager.h"
#include "Message/MessageDispatcher.h"

#include "Miner.h"
#include "MinersWife.h"

#define  TEXTOUTPUT
std::ofstream os;

int main(int argc, const char * argv[]) {
    std::cout << "Hello.west-world-with-message ing\n";
 
#ifdef TEXTOUTPUT
	os.open("output.txt");
#endif

	srand((unsigned)time(NULL));

	//create a miner
	Miner* Bob = new Miner(ent_Miner_Bob);

	//create his wife
	MinersWife* Elsa = new MinersWife(ent_Elsa);

	//register them with the entity manager
	EntityMgr->RegisterEntity(Bob);
	EntityMgr->RegisterEntity(Elsa);

	//run Bob and Elsa through a few Update calls
	for (int i = 0; i < 30; ++i)
	{
		Bob->Update();
		Elsa->Update();

		//dispatch any delayed messages
		Dispatch->DispatchDelayedMessages();

		Sleep(800);
	}

	//tidy up
	delete Bob;
	delete Elsa;

	char c;
	c = getchar();
 
    return 0;
}
