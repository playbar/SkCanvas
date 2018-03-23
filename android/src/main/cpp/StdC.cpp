
#include "StdC.h"
#include "EGTLog.h"

#include <time.h>

#define LOG_TAG "StdC"


static float _deltaTime = 0;
static float _lastUpdate = 0;


float getDeltaTime(){
	return _deltaTime;
}


//struct timeval *_lastUpdate = new struct timeval;
void calculateDeltaTime()
{
	struct timeval t;
	gettimeofday(&t, 0);
	unsigned int tmcou = ((t.tv_sec % 1000000) * 1000 + t.tv_usec / 1000);
    _deltaTime = ( tmcou - _lastUpdate ) / 1000000.0f;
    _lastUpdate = tmcou;
}


