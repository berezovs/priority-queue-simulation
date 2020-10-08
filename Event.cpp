#include "Event.hpp"

Event::Event(float arrivalTime): arrivalTime{arrivalTime}, departureTime{0}
{

}

float Event::getArrivalTime()const{
    return this->arrivalTime;
}

float Event::getDepartureTime()const{
    return this->departureTime;
}

void Event::setDepartureTime(const float departureTime){
    this->departureTime = departureTime;
}