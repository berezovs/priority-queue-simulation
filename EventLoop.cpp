#include "EventLoop.hpp"
#include "EventQueue.hpp"
#include "FIFOQueue.hpp"
#include <stdint.h>
#include <time.h>
#include <iostream>
#include <math.h>

EventLoop::EventLoop(float n, float lambda, float mu, float M) : totalNumberOfArrivals{n}, lambda{lambda}, mu{mu}, serverAvailableCount{M}
{
    srand((unsigned)time(NULL));
    this->EQueue = new EventQueue();
    this->FQueue = new FIFOQueue();
    this->customerWaitedCount = 0;
    this->iddleTime = 0.0f;
    this->currentWaitTime = 0.0f;
    this->serviceTime =0.0f;
    
}

float EventLoop::getNextRandomInterval(float avg)
{

    float random = (float)rand() / RAND_MAX;
    return -1 * (1 / avg) * log(random);
}

void EventLoop::loop()
{
    this->loadFirstArrivals(200);

    // while (!this->queue->isEmpty())
    // {
    //     //std::cout<<"Event #"<<counter<<" "<<this->queue->getNextEvent()->getTime()<<std::endl;
    //     //this->queue->removeEvent();
    //     this->processNextEvent();

    // }
}

void EventLoop::loadFirstArrivals(uint32_t arrivals)
{
    for (uint32_t i = 0; i < arrivals; ++i)
    {
        this->EQueue->insert(new Event(this->getNextRandomInterval(this->lambda), false));
    }
}

void EventLoop::processNextEvent()
{
    Event *event = this->EQueue->getNextEvent();
    float interval=0.0f, startOfServiceTime = 0.0f, departureTime=0.0f;

    if (!event->isDeparture())
    {
        if (this->serverAvailableCount > 0)
        {
            this->serverAvailableCount--;
            startOfServiceTime = event->getTime();
            interval = this->getNextRandomInterval(this->mu);
            departureTime = startOfServiceTime + interval;
            Event *departureEvent = new Event(departureTime, true);
        }
    }
    else
    {
        /* code */
    }
}
