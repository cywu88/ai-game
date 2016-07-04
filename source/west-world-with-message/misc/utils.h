#pragma once

#include <math.h>
#include <stdlib.h>

inline double RandFloat()
{
	return (rand() / (RAND_MAX + 1.0));
}

inline int RandInt(int x,int y)
{
	int min = x > y ? y : x;
	int max = x > y ? x : y;
	return rand() % (max - min + 1) + min;
}