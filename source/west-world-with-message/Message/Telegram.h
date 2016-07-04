//
//  Telegram.h
//  ai-game
//
//  Created by wucy on 16/7/2.
//  Copyright © 2016年 wucy. All rights reserved.
//

#ifndef Telegram_h
#define Telegram_h

#include <iostream>
#include <math.h>

class Telegram
{
    int Sender;
    
    int Receiver;
    
    int Msg;
    
    double DispatchTime;
    
    void* ExtraInfo;

public:
    Telegram():
    DispatchTime(-1),
        Sender(-1),
        Receiver(-1),
        Msg(-1)
    {}
    
    
    Telegram(double time,int sender,int receiver,int msg,void* info = NULL)
    :DispatchTime(time),
        Sender(sender),
        Receiver(receiver),
        Msg(msg),
        ExtraInfo(info)
        {
        }
    
};

#endif /* Telegram_h */
