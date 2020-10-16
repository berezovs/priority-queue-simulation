#include "EventLoop.hpp"
#include <stdint.h>
#include <time.h>
#include <iostream>
#include <math.h> 
EventLoop::EventLoop(float n, float lambda, float mu, float M) : n{n}, lambda{lambda}, mu{mu}, M{M}
{
    srand((unsigned)time(NULL));
}

void EventLoop::beginLoop()
{
}

float EventLoop::getNextRandomInterval(float avg)
{
    
    float random = (float)rand() / RAND_MAX;
    return -1 * (1 / avg) * log(random);
}