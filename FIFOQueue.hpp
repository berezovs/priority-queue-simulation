
/***************************************************************
  Student Name:Serghei Berezovschi
  File Name: FIFOQueue.hpp
  Assignment number:Project 2-DS&AII

 
***************************************************************/
#ifndef FIFOQUEUE_H
#define FIFOQUEUE_H
#include "Customer.hpp"
#include <stdint.h>

class FIFOQueue{
public:
FIFOQueue();
void insertCustomer(Customer* customer);
Customer* removeCustomer();
uint32_t getSize() const;

private:
Customer *head, *tail;
uint32_t size;
};
#endif