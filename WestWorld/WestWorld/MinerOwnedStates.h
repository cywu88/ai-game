//
//  MinerOwnedStates.hpp
//  WestWorld
//
//  Created by wucy on 16/7/1.
//  Copyright © 2016年 wucy. All rights reserved.
//

#ifndef MinerOwnedStates_hpp
#define MinerOwnedStates_hpp

#include <stdio.h>
#include "State.h"

class Minner;

class EnterMineAndDigForNugget : public State
{
private:
    EnterMineAndDigForNugget(){};
    
//    EnterMineAndDigForNugget(const EnterMineAndDigForNugget&){};
//    
//    EnterMineAndDigForNugget& operator=(const EnterMineAndDigForNugget&);
    
public:
//    virtual ~EnterMineAndDigForNugget();
    
//    static EnterMineAndDigForNugget* getInstance();
    
    virtual void Enter(Miner* miner);
    
    virtual void Execute(Miner* miner);
    
    virtual void Exit(Minner *minner);
};

class VisitBankAndDepositGold : public State
{
private:
    VisitBankAndDepositGold(){}
    
//    VisitBankAndDepositGold(const VisitBankAndDepositGold&);
//    
//    VisitBankAndDepositGold& operator=(const VisitBankAndDepositGold&);
    
public:
//    static VisitBankAndDepositGold* getInstance();
    
    virtual void Enter(Miner* miner);
    
    virtual void Execute(Miner* miner);
    
    virtual void Exit(Minner *minner);
};


class GoHomeAndSleepTilRested : public State
{
private:
    GoHomeAndSleepTilRested(){}
    
//    GoHomeAndSleepTilRested(const GoHomeAndSleepTilRested&);
//    
//    GoHomeAndSleepTilRested& operator=(const GoHomeAndSleepTilRested&);
    
public:
//    static GoHomeAndSleepTilRested* getInstance();
    
    virtual void Enter(Miner* miner);
    
    virtual void Execute(Miner* miner);
    
    virtual void Exit(Minner *minner);
};


class QuenchThirst : public State
{
private:
    QuenchThirst(){}
    
//    QuenchThirst(const QuenchThirst&);
//    
//    QuenchThirst& operator=(const QuenchThirst&);
    
public:
//    static QuenchThirst* getInstance();
    
    virtual void Enter(Miner* miner);
    
    virtual void Execute(Miner* miner);
    
    virtual void Exit(Minner *minner);
};


#endif /* MinerOwnedStates_hpp */
