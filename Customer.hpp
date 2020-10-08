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
    float getArrivalTime();
    float getStartOfServiceTime();
    void setStartOfServiceTime(float startOfServiceTime);
    float getDepartureTime();
    void setDepartureTime(float departureTime);
    float getServiceTime();

private:
    float arrivalTime, startOfServiceTime, departureTime;
    Customer *next, *previous;
};
#endif