/***************************************************************
  Student Name:Serghei Berezovschi
  File Name: EventQueue.cpp
  Assignment number:Project 2-DS&AII

 
***************************************************************/
#include "EventQueue.hpp"
#include "Event.hpp"
#include <stdint.h>


EventQueue::EventQueue() : eventQueue{}, size{0}
{
}

bool Comparator::operator()(Event *lhs, Event *rhs)
{
    
    return lhs->getEventTime() > rhs->getEventTime();
}

Event *EventQueue::getNextEvent()
{
    return this->eventQueue.top();
}
void EventQueue::removeEvent()
{
    this->eventQueue.pop();
    this->size--;
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
