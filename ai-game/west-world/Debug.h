#pragma once


#include <iostream>
#include <string>

#include "EntityNames.h"


using namespace std;

const std::string EnterNugget  = "Walkin 'to the goldmine";
const std::string ExecuteNuggent = "Pickin'up a nuggent";
const std::string ExitNugget = "Ah'm leavin' the goldmine with mah pockets full o' sweet gold";

const std::string EnterBank = "Goin' to the bank. Yes siree";
const std::string ExecuteBank = "Depositing gold. Total savings now:";
const std::string ExecuteBank2 = "WooHoo!Rich enough for now.Back home to mah li'lle lady:";
const std::string ExitBank = "Leavin' the bank";


const std::string EnterHome = "Walkin' home";
const std::string ExecuteHome = "What a God darn fantastic nap! Time to find more gold";
const std::string ExecuteHome2 = "ZZZ...";
const std::string ExitHome = "Leaving the house";


const std::string EnterThirst = "Boy, ah sure is thusty! Walking to the saloon";
const std::string ExecuteThirst = "That's mighty fine sippin liquer";
const std::string ExecuteThirst2 = "\nERROR!\nERROR!\nERROR!";
const std::string ExitThirst = "Leaving the saloon, feelin' good";


static string intToString(int value) {
	char c[8];
	sprintf(c, "%05X", value);
	return string(c);
}

static void LogEvent(int userId,std::string userEvent) {
	string userName = GetNameOfEntity(userId);
	std::string message = "\n" + userName + ":" + userEvent;
	std::cout<< message <<endl;
}


static void LogEvent(int userId, std::string userEvent,int value) {
	string userName = GetNameOfEntity(userId);
	std::string message = "\n" + userName + ":" + userEvent + intToString(value);
	std::cout << message << endl;
}