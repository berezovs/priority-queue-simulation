#ifndef EVENTLOOP_H
#define EVENTLOOP_H
class EventLoop{
    public:
    EventLoop(float n, float lambda, float mu, float M);
    private:
    float M, mu, lambda, n;
};
#endif