#ifndef EVENTQUEUE_H
#define EVENTQUEUE_H
#include <queue>
#include <vector>
#include "Event.hpp"
class Comparator
{
public:
    bool operator()(Event *lhs, Event *rhs);
};

class EventQueue
{

public:
    EventQueue();
    Event *getNextEvent();
    void removeEvent();
    void insert(Event *event);
    bool isDeparture() const;
    uint32_t getSize();
    bool isEmpty();

private:
    uint32_t size;
    std::priority_queue<Event *, std::vector<Event *>, Comparator> eventQueue;
};

#endif