#include "Event.hpp"

Event::Event(float time, bool departure): time{time}, departure{departure}
{

}

float Event::getTime()const{
    return this->time;
}


bool Event::isDeparture() const{
    return this->departure;
}

