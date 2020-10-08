#include "Customer.hpp"

 Customer::Customer(float arrivalTime) 
{
    this->arrivalTime = arrivalTime;
    this->departureTime = 0;
    this->next = nullptr;
    this->previous = nullptr;
    
}
Customer *Customer::getNext()
{
    return this->next;
}
void Customer::setNext(Customer *next)
{
    this->next = next;
}
Customer *Customer::getPrevious()
{
    return this->previous;
}
void Customer::setPrevious(Customer *previous)
{
    this->previous = previous;
}
float Customer::getArrivalTime()
{
    return this->arrivalTime;
}
float Customer::getStartOfServiceTime()
{
    return this->startOfServiceTime;
}
void Customer::setStartOfServiceTime(float startOfServiceTime)
{
    this->startOfServiceTime = startOfServiceTime;
}
float Customer::getDepartureTime()
{
    return this->departureTime;
}
void Customer::setDepartureTime(float departureTime)
{
    this->departureTime = departureTime;
}

float Customer::getServiceTime()
{
    return this->departureTime - this->arrivalTime;
}