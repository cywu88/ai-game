#pragma once

#pragma  comment(lib,"winmm.lib")
#include <windows.h>

#define  Clock CrudeTimer::getInstance()

class CrudeTimer
{
private:
	double m_dStartTime;
	CrudeTimer() { m_dStartTime = timeGetTime() * 0.001; }
public:
	static CrudeTimer* getInstance();

	double GetCurrentTime() { return timeGetTime() * 0.001 - m_dStartTime; }
};