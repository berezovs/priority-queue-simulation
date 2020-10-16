#ifndef EVENTLOOP_H
#define EVENTLOOP_H
#include <stdint.h>
class EventLoop{
    public:
    EventLoop(float n, float lambda, float mu, float M);
    void beginLoop();
    float getNextRandomInterval(float avg);
    private:
    float M, mu, lambda, n;
    uint32_t firstArrivals;
};
#endif