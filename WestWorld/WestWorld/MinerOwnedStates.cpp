//
//  MinerOwnedStates.cpp
//  WestWorld
//
//  Created by wucy on 16/7/1.
//  Copyright © 2016年 wucy. All rights reserved.
//

#include <iostream>

#include "MinerOwnedStates.h"
#include "Locations.h"
#include "State.h"
#include "Miner.h"
#include "EntityNames.h"



using std::cout;

EnterMineAndDigForNugget* EnterMineAndDigForNugget::getInstance()
{
    static EnterMineAndDigForNugget instance;
    return &instance;
}

void EnterMineAndDigForNugget::Enter(Miner *pMiner)
{
    if (pMiner->Location() != goldmine) {
        cout<<"\n"<<GetNameOfEntity(pMiner->ID())<<":"<<"Walkin 'to the goldmine";
        pMiner->ChangeLocation(goldmine);
    }
}

void EnterMineAndDigForNugget::Execute(Miner *pMiner)
{
    pMiner->AddToGoldCarried(1);
    pMiner->IncreateFatigue();
    
    cout<<"\n"<<GetNameOfEntity(pMiner->ID())<<":"<<"Pickin'up a nuggent";
    
    if (pMiner->PocketsFull()) {
        pMiner->ChangeState(VisitBankAndDepositGold::getInstance());
    }
    
    if (pMiner->Thirsty()) {
        pMiner->ChangeState(QuenchThirst::getInstance());
    }
}

void EnterMineAndDigForNugget::Exit(Miner *pMiner)
{
    
}

//.2

VisitBankAndDepositGold* VisitBankAndDepositGold::getInstance()
{
    static VisitBankAndDepositGold instance;
    return &instance;
}

void VisitBankAndDepositGold::Enter(Miner *pMiner)
{
    
}

void VisitBankAndDepositGold::Execute(Miner *pMiner)
{
    
}

void VisitBankAndDepositGold::Exit(Miner *pMiner)
{
    
}

//.3

GoHomeAndSleepTilRested* GoHomeAndSleepTilRested::getInstance()
{
    static GoHomeAndSleepTilRested instance;
    return &instance;
}

void GoHomeAndSleepTilRested::Enter(Miner *pMiner)
{

}

void GoHomeAndSleepTilRested::Execute(Miner *pMiner)
{
    
}

void GoHomeAndSleepTilRested::Exit(Miner *pMiner)
{
    
}

//4
QuenchThirst* QuenchThirst::getInstance()
{
    static QuenchThirst instance;
    return &instance;
}

void QuenchThirst::Enter(Miner *pMiner)
{

}

void QuenchThirst::Execute(Miner *pMiner)
{
    
}

void QuenchThirst::Exit(Miner *pMiner)
{
    
}

