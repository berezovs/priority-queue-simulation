#include "FIFOQueue.hpp"
#include "Customer.hpp"
#include <iostream>

FIFOQueue::FIFOQueue()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

void FIFOQueue::insertCustomer(Customer *customer)
{
    if (head)
    {
        Customer *temp = this->tail;
        this->tail = customer;
        temp->setNext(this->tail);
        this->tail->setPrevious(temp);
        temp = nullptr;
        size++;
        return;
    }
    this->head = customer;
    this->tail = customer;
    size++;
}
Customer *FIFOQueue::removeCustomer()
{
    return nullptr;
}
int FIFOQueue::getSize()
{
    return this->size;
}

void FIFOQueue::printAllArrivals()
{
    Customer *customer = this->head;
    while (customer)
    {
        std::cout << customer->getArrivalTime();
        if (customer->getNext())
        {
            std::cout << " --> ";
        }
        customer = customer->getNext();
    }
}
