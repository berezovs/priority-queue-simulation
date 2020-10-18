/***************************************************************
  Student Name:Serghei Berezovschi
  File Name: Event.cpp
  Assignment number:Project 2-DS&AII

 
***************************************************************/

#include "Event.hpp"
#include <iostream>

Event::Event(float eventTime, bool departure) : eventTime{eventTime}, departure{departure}
{
    this->waitForServiceTime = 0.0f;
    this->serviceTime = 0.0f;
}

float Event::getEventTime() const
{
    return this->eventTime;
}

void Event::setEventTime(float time)
{
    this->eventTime = time;
}

void Event::setToDeparture(bool departure)
{
    this->departure = true;
}

bool Event::isDeparture() const
{
    return this->departure;
}

void Event::setWaitForServiceTime(float time)
{
    this->waitForServiceTime = time;
}

float Event::getWaitedForServiceTime() const
{

    return this->waitForServiceTime;
}

void Event::setServiceTime(float time)
{
    this->serviceTime = time;
}
float Event::getServiceTime() const
{
    return this->serviceTime;
}
