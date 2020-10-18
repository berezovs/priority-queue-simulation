/***************************************************************
  Student Name:Serghei Berezovschi
  File Name: EventLoop.hpp
  Assignment number:Project 2-DS&AII

 
***************************************************************/
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
    void loadArrivals(uint32_t arrivals);
    void processNextEvent();
    void processStatistics(Event *event);
    bool moreArrivals();
    void printStatistics();

private:
    float totalNumberOfArrivals, lambda, mu, totalServers, serverAvailableCount, idleTime, totalServiceTime, currentWaitTime, totalWaitTime, arr, dep;
    uint32_t customerWaitedCount;
    uint32_t const ARRIVAL_NUMBER{200};
    EventQueue *EQueue;
    FIFOQueue *FQueue;
};
#endif