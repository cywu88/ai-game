//
//  MinersWifeOwnerStates.cpp
//  ai-game
//
//  Created by wucy on 16/7/3.
//  Copyright © 2016年 wucy. All rights reserved.
//

#include "MinersWifeOwnedStates.h"
#include "Time/CrudeTimer.h"
#include "misc/utils.h"
#include "Message/MessageDispatcher.h"
#include "MessageType.h"
#include "Debug.h"
#include "MinersWife.h"




WifesGlobalState* WifesGlobalState::getInstance()
{
	static WifesGlobalState instance;
	return &instance;
}


void WifesGlobalState::Execute(MinersWife* wife)
{
 
	if ((RandFloat() < 0.1) &&
		!wife->GetFSM()->isInState(*VisitBathroom::getInstance()))
	{
		wife->GetFSM()->ChangeState(VisitBathroom::getInstance());
	}
}

bool WifesGlobalState::OnMessage(MinersWife* wife, const Telegram& msg)
{
 
	switch (msg.Msg)
	{
	case Msg_HiHoneyImHome:
	{
		cout << "\nMessage handled by " << GetNameOfEntity(wife->ID()) << " at time: "
			<< Clock->GetCurrentTime();

 
		cout << "\n" << GetNameOfEntity(wife->ID()) <<
			": Hi honey. Let me make you some of mah fine country stew";

		wife->GetFSM()->ChangeState(CookStew::getInstance());
	}

	return true;

	}//end switch

	return false;
}

//-------------------------------------------------------------------------DoHouseWork

DoHouseWork* DoHouseWork::getInstance()
{
	static DoHouseWork instance;

	return &instance;
}


void DoHouseWork::Enter(MinersWife* wife)
{
	cout << "\n" << GetNameOfEntity(wife->ID()) << ": Time to do some more housework!";
}


void DoHouseWork::Execute(MinersWife* wife)
{
	switch (RandInt(0, 2))
	{
	case 0:

		cout << "\n" << GetNameOfEntity(wife->ID()) << ": Moppin' the floor";

		break;

	case 1:

		cout << "\n" << GetNameOfEntity(wife->ID()) << ": Washin' the dishes";

		break;

	case 2:

		cout << "\n" << GetNameOfEntity(wife->ID()) << ": Makin' the bed";

		break;
	}
}

void DoHouseWork::Exit(MinersWife* wife)
{
}

bool DoHouseWork::OnMessage(MinersWife* wife, const Telegram& msg)
{
	return false;
}

//------------------------------------------------------------------------VisitBathroom

VisitBathroom* VisitBathroom::getInstance()
{
	static VisitBathroom instance;

	return &instance;
}


void VisitBathroom::Enter(MinersWife* wife)
{
	cout << "\n" << GetNameOfEntity(wife->ID()) << ": Walkin' to the can. Need to powda mah pretty li'lle nose";
}


void VisitBathroom::Execute(MinersWife* wife)
{
	cout << "\n" << GetNameOfEntity(wife->ID()) << ": Ahhhhhh! Sweet relief!";

	wife->GetFSM()->RevertToPreviousState();
}

void VisitBathroom::Exit(MinersWife* wife)
{
	//cout << "\n" << GetNameOfEntity(wife->ID()) << ": Leavin' the Jon";
}


bool VisitBathroom::OnMessage(MinersWife* wife, const Telegram& msg)
{
	return false;
}


//------------------------------------------------------------------------CookStew

CookStew* CookStew::getInstance()
{
	static CookStew instance;

	return &instance;
}


void CookStew::Enter(MinersWife* wife)
{
	//if not already cooking put the stew in the oven
	if (!wife->Cooking())
	{
		cout << "\n" << GetNameOfEntity(wife->ID()) << ": Putting the stew in the oven";

		//send a delayed message myself so that I know when to take the stew
		//out of the oven
		Dispatch->DispatchMsg(1.5,                  //time delay
			wife->ID(),           //sender ID
			wife->ID(),           //receiver ID
			Msg_StewReady,        //msg
			NO_ADDITIONAL_INFO);

		wife->SetCooking(true);
	}
}


void CookStew::Execute(MinersWife* wife)
{
	cout << "\n" << GetNameOfEntity(wife->ID()) << ": Fussin' over food";
}

void CookStew::Exit(MinersWife* wife)
{
	cout << "\n" << GetNameOfEntity(wife->ID()) << ": Puttin' the stew on the table";
}


bool CookStew::OnMessage(MinersWife* wife, const Telegram& msg)
{
 
	switch (msg.Msg)
	{
	case Msg_StewReady:
	{
		cout << "\nMessage received by " << GetNameOfEntity(wife->ID()) <<
			" at time: " << Clock->GetCurrentTime();
		cout << "\n" << GetNameOfEntity(wife->ID()) << ": StewReady! Lets eat";

		//let hubby know the stew is ready
		Dispatch->DispatchMsg(SEND_MSG_IMMEDIATELY,
			wife->ID(),
			ent_Miner_Bob,
			Msg_StewReady,
			NO_ADDITIONAL_INFO);

		wife->SetCooking(false);
		wife->GetFSM()->ChangeState(DoHouseWork::getInstance());
	}

	return true;

	}//end switch

	return false;
}
