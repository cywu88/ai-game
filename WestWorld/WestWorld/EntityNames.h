//
//  EntityNames.h
//  WestWorld
//
//  Created by wucy on 16/7/2.
//  Copyright © 2016年 wucy. All rights reserved.
//

#ifndef EntityNames_h
#define EntityNames_h

#include <string.h>
enum
{
    ent_Miner_Bob,
    
    ent_Elas
};

inline std::string GetNameOfEntity(int n)
{
    switch (n) {
        case ent_Miner_Bob:
            return "Minner Bob";
            break;
        case ent_Elas:
            return "Elsa";
            break;
        default:
            return "cywu";
            break;
    }
}


#endif /* EntityNames_h */
