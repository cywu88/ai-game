#include "CrudeTimer.h"

CrudeTimer* CrudeTimer::getInstance()
{
	static CrudeTimer instance;
	return &instance;
}

