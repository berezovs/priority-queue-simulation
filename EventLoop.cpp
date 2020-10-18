#include "EventLoop.hpp"
#include "EventQueue.hpp"
#include "FIFOQueue.hpp"
#include "analytics.hpp"
#include <stdint.h>
#include <time.h>
#include <iostream>
#include <math.h>

EventLoop::EventLoop(float n, float lambda, float mu, float M) : totalNumberOfArrivals{n}, lambda{lambda}, mu{mu}, totalServers{M}
{
    srand((unsigned)time(NULL));
    this->EQueue = new EventQueue();
    this->FQueue = new FIFOQueue();
    this->customerWaitedCount = 0;
    this->idleTime = 0.0f;
    this->currentWaitTime = 0.0f;
    this->totalServiceTime = 0.0f;
    this->totalWaitTime = 0;
    this->serverAvailableCount = this->totalServers;
}

float EventLoop::getNextRandomInterval(float avg)
{

    float random = (float)rand() / RAND_MAX;
    return -1 * (1 / avg) * log(random);
}

void EventLoop::loop()
{
    this->loadArrivals(ARRIVAL_NUMBER);
    this->totalNumberOfArrivals -= ARRIVAL_NUMBER;
    while (!this->EQueue->isEmpty())
    {

        this->processNextEvent();
        if (this->moreArrivals() && (EQueue->getSize() <= this->serverAvailableCount + 1))
        {
            uint32_t arrivalsToLoad = ARRIVAL_NUMBER - this->EQueue->getSize();
            if (arrivalsToLoad > this->totalNumberOfArrivals)
            {
                this->loadArrivals(this->totalNumberOfArrivals);
                this->totalNumberOfArrivals -= arrivalsToLoad;
            }
            else
            {
                this->loadArrivals(arrivalsToLoad);
                this->totalNumberOfArrivals -= arrivalsToLoad;
            }
        }
    }

    this->printStatistics();
}

void EventLoop::printStatistics()
{

    std::cout << "Simulated Results: " << std::endl;
    std::cout << "\tTotal Idle Time " << this->idleTime << std::endl;
    std::cout << "\tThe average time a customer spends in the system: " << (this->totalServiceTime + this->totalWaitTime) / this->arr << std::endl;
    std::cout << "\tThe average time a customer spends waiting in the queue: " << this->totalWaitTime / (float)this->arr << std::endl;
    std::cout << "\tThe utilization factor for the system: " << analytics::rho(this->lambda, this->totalServers, this->mu) << std::endl;

    std::cout << std::endl;
    std::cout << "Analytical Results: " << std::endl;
    float Po = analytics::getPo(this->lambda, this->totalServers, this->mu);
    float L = analytics::getL(this->lambda, Po, this->totalServers, this->mu);
    std::cout << "\tTotal Idle Time: " << Po << std::endl;
    std::cout << "\tThe average time a customer spends in the system: " << analytics::getW(this->lambda, L) << std::endl;
    std::cout << "\tThe average time a customer spends waiting in the queue: " << analytics::getWq(analytics::getLq(L, this->lambda, this->mu), this->lambda) << std::endl;
    std::cout << "\tThe utilization factor for the system: " << this->totalServiceTime / (this->totalServers * (this->totalServiceTime)) << std::endl;
}

void EventLoop::loadArrivals(uint32_t arrivals)
{
    for (uint32_t i = 0; i < arrivals; ++i)
    {
        this->EQueue->insert(new Event(this->getNextRandomInterval(this->lambda), false));
    }
}

bool EventLoop::moreArrivals()
{
    return this->totalNumberOfArrivals > 0;
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

            startOfServiceTime = currentTime;
            interval = this->getNextRandomInterval(this->mu);
            departureTime = startOfServiceTime + currentTime;
            Event *departureEvent = new Event(departureTime, true);
            departureEvent->setServiceTime(departureTime - currentTime);
            this->EQueue->removeEvent();
            this->EQueue->insert(departureEvent);
        }
        else
        {

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
        this->processStatistics(currentEvent);
        EQueue->removeEvent();
        if (this->FQueue->getSize() > 0)
        {
            Customer *fifoCustomer = this->FQueue->removeCustomer();
            interval = this->getNextRandomInterval(mu);
            departureTime = currentTime + interval;
            Event *departureEvent = new Event(departureTime, true);
            departureEvent->setWaitForServiceTime(currentTime - fifoCustomer->getQueueTime());
            departureEvent->setServiceTime(interval);
            EQueue->insert(departureEvent);
        }
    }
}

void EventLoop::processStatistics(Event *event)
{
    this->currentWaitTime = event->getWaitedForServiceTime();

    if (this->currentWaitTime > 0)
        ++this->customerWaitedCount;
    this->totalWaitTime = this->totalWaitTime + currentWaitTime;
    this->totalServiceTime += event->getServiceTime();
    if (this->serverAvailableCount == 0)
    {
        std::cout << "Accumulated idle time" << std::endl;
        this->idleTime += this->EQueue->getNextEvent()->getEventTime() - event->getEventTime();
    }
}
