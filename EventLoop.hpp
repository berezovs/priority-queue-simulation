#ifndef EVENTLOOP_H
#define EVENTLOOP_H
#include <stdint.h>
#include "EventQueue.hpp"
#include "FIFOQueue.hpp"
class EventLoop
{
public:
    EventLoop(float n, float lambda, float mu, float M);
    float getNextRandomInterval(float avg);
    void loop();
    void loadFirstArrivals(uint32_t arrivals);
    void processNextEvent();

private:
    float serverAvailableCount, mu, lambda, totalNumberOfArrivals,  iddleTime, serviceTime, currentWaitTime;
    uint32_t numOfFirstArrivals, customerWaitedCount;
    EventQueue *EQueue;
    FIFOQueue *FQueue;
};
#endif