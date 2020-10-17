#ifndef CUSTOMER_H
#define CUSTOMER_H
class Customer
{
public:
    Customer(float arrivalTime);
    Customer *getNext();
    void setNext(Customer *next);
    Customer *getPrevious();
    void setPrevious(Customer *previous);
    float getArrivalTime() const;
    void setQueueTime(float time);
    float getQueueTime() const;

private:
    float arrivalTime, queueTime;
    Customer *next, *previous;
};
#endif