#include "Shell.hpp"
#include "Customer.hpp"
#include "FIFOQueue.hpp"
#include "Event.hpp"
#include "analytics.hpp"
#include "EventQueue.hpp"
#include "EventLoop.hpp"
#include <iostream>

#define print std::cout<< 
#define newline std::cout<<std::endl;

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


    print analytics::getLq(0.75,2,3);
    print std::endl;
    print analytics::getWq(0.083, 2);

    EventLoop *loop = new EventLoop(3.0,3.0,3.0,3.0);
    

    for(int i = 0; i<15; ++i){
            print loop->getNextRandomInterval(3);
            newline
    }


    //Event *event = new Event(3.14);

   // print event->getArrivalTime();


    // EventQueue *queue = new EventQueue();
    // queue->insert(event1);
    // queue->insert(event2);
    // queue->insert(event3);
   
    // print queue->getNextEvent()->getTime();
    // newline
    // queue->removeEvent();
    // print queue->getNextEvent()->getTime();
    // newline
    // delete event1;
    // delete event2;
    // delete event3;
    
    return 0;
}