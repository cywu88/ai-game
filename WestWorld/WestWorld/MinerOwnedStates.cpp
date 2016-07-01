//
//  MinerOwnedStates.cpp
//  WestWorld
//
//  Created by wucy on 16/7/1.
//  Copyright © 2016年 wucy. All rights reserved.
//

#include "Locations.h"
#include "State.h"
#include "Miner.h"

#include "MinerOwnedStates.h"


EnterMineAndDigForNugget* EnterMineAndDigForNugget::getInstance()
{
    static EnterMineAndDigForNugget instance;
    return &instance;
}

void EnterMineAndDigForNugget::Enter(Miner *pMiner)
{
    if (pMiner->Location() != goldmine) {
//        pMiner->ChangeLocation(goldmine);
    }
}

void EnterMineAndDigForNugget::Execute(Miner *pMiner)
{
    
}

void EnterMineAndDigForNugget::Exit(Miner *pMiner)
{
    
}

//.2
void VisitBankAndDepositGold::Enter(Miner *pMiner)
{
    
}

void VisitBankAndDepositGold::Execute(Miner *pMiner)
{
    
}

void VisitBankAndDepositGold::Exit(Minner *pMiner)
{
    
}

//.3
void GoHomeAndSleepTilRested::Enter(Miner *pMiner)
{

}

void GoHomeAndSleepTilRested::Execute(Miner *pMiner)
{
    
}

void GoHomeAndSleepTilRested::Exit(Minner *pMiner)
{
    
}

//4
void QuenchThirst::Enter(Miner *pMiner)
{

}

void QuenchThirst::Execute(Miner *pMiner)
{
    
}

void QuenchThirst::Exit(Minner *pMiner)
{
    
}

