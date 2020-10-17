#include "Customer.hpp"

Customer::Customer(float arrivalTime)
{
    this->arrivalTime = arrivalTime;
    this->queueTime = 0.f;
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
float Customer::getArrivalTime() const
{
    return this->arrivalTime;
}

void Customer::setQueueTime(float time)
{
    this->queueTime = time;
}

float Customer::getQueueTime() const
{
    return this->queueTime;
}
