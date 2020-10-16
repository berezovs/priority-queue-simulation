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
    this->serviceTime = 0.0f;
}

float EventLoop::getNextRandomInterval(float avg)
{

    float random = (float)rand() / RAND_MAX;
    return -1 * (1 / avg) * log(random);
}

void EventLoop::loop()
{
    this->loadFirstArrivals(200);
    int counter = 0;
    while (!this->EQueue->isEmpty())
    {

        this->processNextEvent();
        //std::cout<<this->EQueue->getSize()<<std::endl;
    }

    // while (!this->EQueue->isEmpty())
    // {
    //     std::cout << "Event #" << ++counter << " " << this->EQueue->getNextEvent()->getTime() << std::endl;
    //     this->EQueue->removeEvent();
    //     // this->processNextEvent();
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
    float interval = 0.0f, startOfServiceTime = 0.0f, departureTime = 0.0f;

    if (!event->isDeparture())
    {
        if (this->serverAvailableCount > 0)
        {
            std::cout<<"Processed an arrival"<<std::endl;
            this->serverAvailableCount--;
            startOfServiceTime = event->getTime();
            interval = this->getNextRandomInterval(this->mu);
            departureTime = startOfServiceTime + interval;
            Event *departureEvent = new Event(departureTime, true);
            EQueue->removeEvent();
            this->EQueue->insert(departureEvent);
        }
        else
        {
            std::cout<<"Added an event into FIFO queue"<<std::endl;
            this->EQueue->removeEvent();
            this->FQueue->insertCustomer(new Customer(event->getTime()));
            
        }
    }
    else
    {
        this->EQueue->removeEvent();
        this->serverAvailableCount++;
        if (this->FQueue->getSize() > 0)
        {
            std::cout<<"Processed a departure"<<std::endl;
            FQueue->removeCustomer();
            startOfServiceTime = event->getTime();
            interval = this->getNextRandomInterval(mu);
            departureTime = startOfServiceTime;
            Event *departureEvent = new Event(departureTime, true);
            EQueue->insert(event);
            this->serverAvailableCount--;
        }
    }
    
}
