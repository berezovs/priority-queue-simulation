/***************************************************************
  Student Name:Serghei Berezovschi
  File Name: EventQueue.cpp
  Assignment number:Project 2-DS&AII

 This class creates a priority queue for arrival and departure events
 std::priority_queue supplied by the STL was used for this purpose
***************************************************************/
#include "EventQueue.hpp"
#include "Event.hpp"
#include <stdint.h>


EventQueue::EventQueue() : eventQueue{}, size{0}
{
}

//operator overload function for the Comparator class
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

uint32_t EventQueue::getSize(){
    return this->size;
} 

bool EventQueue::isEmpty(){
    return this->eventQueue.empty();
}
