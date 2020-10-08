#ifndef FIFOQUEUE_H
#define FIFOQUEUE_H
#include "Customer.hpp"

class FIFOQueue{
public:
FIFOQueue();
void insertCustomer(Customer* customer);
Customer* removeCustomer();
int getSize();
void printAllArrivals();

private:
Customer *head, *tail;
int size;
};
#endif