//
//  MinerOwnedStates.cpp
//  WestWorld
//
//  Created by wucy on 16/7/1.
//  Copyright © 2016年 wucy. All rights reserved.
//

#include <iostream>
#include <string>
#include "MinerOwnedStates.h"
#include "Locations.h"
#include "State.h"
#include "Miner.h"
#include "EntityNames.h"
#include "Debug.h"


using std::cout;

EnterMineAndDigForNugget* EnterMineAndDigForNugget::getInstance()
{
    static EnterMineAndDigForNugget instance;
    return &instance;
}

void EnterMineAndDigForNugget::Enter(Miner *pMiner)
{
    if (pMiner->Location() != goldmine) {
		LogEvent(pMiner->ID(), EnterNugget);
        pMiner->ChangeLocation(goldmine);
    }
}

void EnterMineAndDigForNugget::Execute(Miner *pMiner)
{
    pMiner->AddToGoldCarried(1);
    pMiner->IncreateFatigue();
    
	LogEvent(pMiner->ID(), ExecuteNuggent);

    if (pMiner->PocketsFull()) {
        pMiner->GetFSM()->ChangeState(VisitBankAndDepositGold::getInstance());
    }
    
    if (pMiner->Thirsty()) {
        pMiner->GetFSM()->ChangeState(QuenchThirst::getInstance());
    }
}

void EnterMineAndDigForNugget::Exit(Miner *pMiner)
{
	//SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	LogEvent(pMiner->ID(), ExitNugget);
}

bool EnterMineAndDigForNugget::OnMessage(Miner* pMiner, const Telegram& msg)
{
    //send msg to global message handler
    return false;
}


//.2

VisitBankAndDepositGold* VisitBankAndDepositGold::getInstance()
{
    static VisitBankAndDepositGold instance;
    return &instance;
}

void VisitBankAndDepositGold::Enter(Miner *pMiner)
{
	if (pMiner->Location() != bank) {
		pMiner->ChangeLocation(bank);
		LogEvent(pMiner->ID(), ExitBank);
	}
}

void VisitBankAndDepositGold::Execute(Miner *pMiner)
{
	pMiner->AddToWealth(pMiner->GoldCarried());

	pMiner->SetGoldCarried(0);

	LogEvent(pMiner->ID(), ExecuteBank, pMiner->Wealth());

	if (pMiner->Wealth() > ComfortLevel) {

		LogEvent(pMiner->ID(), ExecuteBank2);

		pMiner->GetFSM()->ChangeState(GoHomeAndSleepTilRested::getInstance());
	}
	else {
		pMiner->GetFSM()->ChangeState(EnterMineAndDigForNugget::getInstance());
	}
}

void VisitBankAndDepositGold::Exit(Miner *pMiner)
{
	LogEvent(pMiner->ID(), ExitBank);
}

bool VisitBankAndDepositGold::OnMessage(Miner* pMiner, const Telegram& msg)
{
    //send msg to global message handler
    return false;
}

//.3

GoHomeAndSleepTilRested* GoHomeAndSleepTilRested::getInstance()
{
    static GoHomeAndSleepTilRested instance;
    return &instance;
}

void GoHomeAndSleepTilRested::Enter(Miner *pMiner)
{
	if (pMiner->Location() != shack) {
		LogEvent(pMiner->ID(), EnterHome);
	}
	pMiner->ChangeLocation(shack);
}

void GoHomeAndSleepTilRested::Execute(Miner *pMiner)
{
	if (!pMiner->Fatigued()) {
		LogEvent(pMiner->ID(), ExecuteHome);
		pMiner->GetFSM()->ChangeState(EnterMineAndDigForNugget::getInstance());
	}
	else {
		pMiner->DecreateFatigue();
		LogEvent(pMiner->ID(), ExecuteHome2);
	}
}

void GoHomeAndSleepTilRested::Exit(Miner *pMiner)
{
	LogEvent(pMiner->ID(), ExitHome);
}

bool GoHomeAndSleepTilRested::OnMessage(Miner* pMiner, const Telegram& msg)
{
//    switch(msg.Msg)
//    {
//        case Msg_StewReady:
//            
////            cout << "\nMessage handled by " << GetNameOfEntity(pMiner->ID())
////            << " at time: " << Clock->GetCurrentTime();
//            
//            LogEvent(pMiner->ID(), ": Okay Hun, ahm a comin'!");
//         
//            pMiner->GetFSM()->ChangeState(EatStew::Instance());
//            
//            return true;
//            
//    }//end switch
    
    return false; //send message to global message handler
}

//4.

QuenchThirst* QuenchThirst::getInstance()
{
    static QuenchThirst instance;
    return &instance;
}

void QuenchThirst::Enter(Miner *pMiner)
{
	if (pMiner->Location()!=saloon)
	{
		pMiner->ChangeLocation(saloon);
		
		LogEvent(pMiner->ID(), EnterThirst);
	}
}

void QuenchThirst::Execute(Miner *pMiner)
{
    if (pMiner->Thirsty())
    {
		pMiner->BuyAndDrinkAWhiskye();
		LogEvent(pMiner->ID(), ExecuteThirst);
		pMiner->GetFSM()->ChangeState(EnterMineAndDigForNugget::getInstance());
	}
	else {
		LogEvent(pMiner->ID(), ExecuteThirst2);
	}
}

void QuenchThirst::Exit(Miner *pMiner)
{
	LogEvent(pMiner->ID(), ExitThirst);
}

bool QuenchThirst::OnMessage(Miner* pMiner, const Telegram& msg)
{
    //send msg to global message handler
    return false;
}

