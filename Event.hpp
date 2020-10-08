#ifndef EVENT_H
#define EVENT_H

class Event{
public:
Event(float arrivalTime);
float getArrivalTime() const;
float getDepartureTime() const;
void setDepartureTime(const float departureTime);

private:
float arrivalTime, departureTime;
};

#endif