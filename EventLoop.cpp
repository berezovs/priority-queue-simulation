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
    std::cout <<"Arrivals "<<arr<<std::endl;
    std::cout <<"Departures "<<dep<<std::endl;
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
    
    Event *currentEvent = this->EQueue->getNextEvent();
    float interval = 0.0f, startOfServiceTime = 0.0f, departureTime = 0.0f;
    float currentTime = currentEvent->getEventTime();

    if (!this->EQueue->getNextEvent()->isDeparture())
    {
        arr++;
        if (this->serverAvailableCount > 0)
        {
            this->serverAvailableCount--;
            std::cout << "Processed an arrival" << std::endl;
            startOfServiceTime = currentTime;
            interval = this->getNextRandomInterval(this->mu);
            departureTime = startOfServiceTime + currentTime;
            Event *departureEvent = new Event(departureTime, true);
            this->EQueue->removeEvent();
            this->EQueue->insert(departureEvent);
        }
        else
        {
            std::cout << "Added an event into FIFO queue" << std::endl;
            Customer *customer = new Customer(currentEvent->getEventTime());
            customer->setQueueTime(currentEvent->getEventTime());
            this->FQueue->insertCustomer(customer);
            this->EQueue->removeEvent();
        }
    }
    else
    {
        dep++;
        this->serverAvailableCount++;
        currentTime = currentEvent->getEventTime();
        EQueue->removeEvent();
        if (this->FQueue->getSize() > 0)
        {
            std::cout << "Processed a departure" << std::endl;
            Customer *fifoCustomer = this->FQueue->removeCustomer();
            interval = this->getNextRandomInterval(mu);
            departureTime = currentTime + interval;
            Event *departureEvent = new Event(departureTime, true);
            departureEvent->setWaitForServiceTime(currentTime - fifoCustomer->getQueueTime());
            EQueue->insert(departureEvent);
        }
    }
}
