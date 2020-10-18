/***************************************************************
  Student Name:Serghei Berezovschi
  File Name: FIFOQueue.cpp
  Assignment number:Project 2-DS&AII

 This class creates a FIFO queue where customers are stored
***************************************************************/
#include "FIFOQueue.hpp"
#include "Customer.hpp"
#include <stdint.h>

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
        this->size++;
        return;
    }
    this->head = customer;
    this->tail = customer;
    this->size++;
}
Customer *FIFOQueue::removeCustomer()
{
    if (this->head == this->tail)
    {
        Customer *customer = this->head;
        this->head = nullptr;
        this->tail = nullptr;
        this->size--;
        return customer;
    }
    else if (this->head != this->tail)
    {
        Customer* customer = this->head;
        this->head = head->getNext();
        this->head->setPrevious(nullptr);
        customer->setNext(nullptr);
        this->size--;
        return customer;
    }
    return nullptr;
}
uint32_t FIFOQueue::getSize()const
{
    return this->size;
}

