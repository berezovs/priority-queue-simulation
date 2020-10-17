#include "Event.hpp"

Event::Event(float eventTime, bool departure) : eventTime{eventTime}, departure{departure}
{
}

float Event::getEventTime() const
{
    return this->eventTime;
}

void Event::setEventTime(float time)
{
    this->eventTime = eventTime;
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
