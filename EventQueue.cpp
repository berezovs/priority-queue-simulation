#include "EventQueue.hpp"
#include "Event.hpp"


EventQueue::EventQueue() : eventQueue{}, size{0}
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
    size++;
}
bool EventQueue::isDeparture() const
{
    return this->eventQueue.top()->isDeparture();
}

uint32_t EventQueue::getSize(){
    return this->size;
} 

bool EventQueue::isEmpty(){
    return this->eventQueue.empty();
}
