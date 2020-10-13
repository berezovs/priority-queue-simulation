#ifndef EVENT_H
#define EVENT_H

class Event{
public:
Event(float Time, bool departure);
float getTime() const;
bool isDeparture() const;


private:
float time;
bool departure;
};

#endif