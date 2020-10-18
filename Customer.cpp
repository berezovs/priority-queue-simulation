/***************************************************************
  Student Name:Serghei Berezovschi
  File Name: Customer.cpp
  Assignment number:Project 2-DS&AII

 This class creates instances of Customer, which are stored in a FIFO queue
***************************************************************/
#include "Customer.hpp"
#include <iostream>

Customer::Customer(float arrivalTime)
{
    this->arrivalTime = arrivalTime;
    this->queueTime = 0.0f;
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
Customer *Customer::getPrevious() const
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

void Customer::setDepartureTime(float time)
{
    this->departureTime = time;
}
void Customer::setArrivalTime(float time)
{
    this->arrivalTime = time;
}
