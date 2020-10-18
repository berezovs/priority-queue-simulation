/***************************************************************
  Student Name:Serghei Berezovschi
  File Name: Customer.hpp
  Assignment number:Project 2-DS&AII

 
***************************************************************/
#ifndef CUSTOMER_H
#define CUSTOMER_H
class Customer
{
public:
    Customer(float arrivalTime);
    Customer *getNext();
    void setNext(Customer *next);
    Customer *getPrevious() const;
    void setPrevious(Customer *previous);
    float getArrivalTime() const;
    float getDepartureTime() const;
    void setDepartureTime(float time);
    void setArrivalTime(float time);
    void setQueueTime(float time);
    float getQueueTime() const;

private:
    float arrivalTime, departureTime, queueTime;
    Customer *next, *previous;
};
#endif