#include "EventQueue.hpp"
#include "Event.hpp"

EventQueue::EventQueue() : eventQueue{}
{
}

bool Comparator::operator()(Event *lhs, Event *rhs)
{
    return lhs->getTime() < rhs->getTime();
}

Event *EventQueue::getNextEvent()
{
    return this->eventQueue.top();
}
void EventQueue::removeEvent()
{
    this->eventQueue.pop();
}
void EventQueue::insert(Event *event)
{
    eventQueue.push(event);
}
bool EventQueue::isDeparture() const
{
    return this->eventQueue.top()->isDeparture();
}
