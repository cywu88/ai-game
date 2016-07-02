#pragma once


#include <iostream>
#include <string>

#include "EntityNames.h"


using namespace std;
 
static void LogEvent(std::string userName,std::string userEvent) {
	std::string message = "\n" + userName + ":" + userEvent;
	std::cout<< message <<endl;
}