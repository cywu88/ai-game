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
#include "FSM/State.h"
using namespace FSM;

class Miner;
class EnterMineAndDigForNugget : public State<Miner>
{
private:
    EnterMineAndDigForNugget(){};
    
//    EnterMineAndDigForNugget(const EnterMineAndDigForNugget&){};
//    
//    EnterMineAndDigForNugget& operator=(const EnterMineAndDigForNugget&);
    
public:
    
    virtual ~EnterMineAndDigForNugget(){};
    
    static EnterMineAndDigForNugget* getInstance();
    
    virtual void Enter(Miner* miner);
    
    virtual void Execute(Miner* miner);
    
    virtual void Exit(Miner *minner);
    
    virtual bool OnMessage(Miner* agent, const Telegram& msg);
};

class VisitBankAndDepositGold : public State<Miner>
{
private:
    VisitBankAndDepositGold(){}
    
//    VisitBankAndDepositGold(const VisitBankAndDepositGold&);
//    
//    VisitBankAndDepositGold& operator=(const VisitBankAndDepositGold&);
    
public:
    static VisitBankAndDepositGold* getInstance();
    
    virtual void Enter(Miner* miner);
    
    virtual void Execute(Miner* miner);
    
    virtual void Exit(Miner *minner);
    
    virtual bool OnMessage(Miner* agent, const Telegram& msg);
};


class GoHomeAndSleepTilRested : public State<Miner>
{
private:
    GoHomeAndSleepTilRested(){}
    
//    GoHomeAndSleepTilRested(const GoHomeAndSleepTilRested&);
//    
//    GoHomeAndSleepTilRested& operator=(const GoHomeAndSleepTilRested&);
    
public:
    static GoHomeAndSleepTilRested* getInstance();
    
    virtual void Enter(Miner* miner);
    
    virtual void Execute(Miner* miner);
    
    virtual void Exit(Miner *minner);
    
    virtual bool OnMessage(Miner* agent, const Telegram& msg);
};


class QuenchThirst : public State<Miner>
{
private:
    QuenchThirst(){}
    
//    QuenchThirst(const QuenchThirst&);
//    
//    QuenchThirst& operator=(const QuenchThirst&);
    
public:
    static QuenchThirst* getInstance();
    
    virtual void Enter(Miner* miner);
    
    virtual void Execute(Miner* miner);
    
    virtual void Exit(Miner *minner);
    
    virtual bool OnMessage(Miner* agent, const Telegram& msg);
};

//
//
//



#endif /* MinerOwnedStates_hpp */
