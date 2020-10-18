#ifndef EVENT_H
#define EVENT_H
#include "Customer.hpp"

class Event
{
public:
    Event(float eventTime, bool departure);
    float getEventTime() const;
    bool isDeparture() const;
    void setToDeparture(bool departure);
    void setEventTime(float time);
    void setWaitForServiceTime(float time);
    float getWaitedForServiceTime() const;
    void setServiceTime(float time);
    float getServiceTime() const;
    
  

private:
    float eventTime, waitForServiceTime, serviceTime;
    bool departure;
};

#endif