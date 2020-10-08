#include "Shell.hpp"
#include "Customer.hpp"
#include "FIFOQueue.hpp"
#include "Event.hpp"
#include <iostream>

#define print std::cout<< 

int main()
{
    // Shell shell;
    // shell.run();
    // Customer *customer1 = new Customer(11.55);
    // Customer *customer2 = new Customer(12.55);
    // Customer *customer3 = new Customer(13.55);
    // Customer *customer4 = new Customer(114.55);

    // FIFOQueue *fQueue = new FIFOQueue();
    // fQueue->insertCustomer(customer1);
    // fQueue->insertCustomer(customer2);
    // fQueue->insertCustomer(customer3);
    // fQueue->insertCustomer(customer4);

    // fQueue->printAllArrivals();
    // std::cout<<fQueue->removeCustomer()->getArrivalTime()<<std::endl;
    // fQueue->printAllArrivals();
    // std::cout<<fQueue->removeCustomer()->getArrivalTime()<<std::endl;
    // fQueue->printAllArrivals();
    // std::cout<<fQueue->removeCustomer()->getArrivalTime()<<std::endl;
    // fQueue->printAllArrivals();

    Event *event = new Event(3.14);

    print event->getArrivalTime();

    delete event;
    
    return 0;
}