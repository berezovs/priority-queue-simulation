#ifndef ANALYTICS_H
#define ANALYTICS_H

namespace analytics{
    float getPo(float lambda, float M, float mu);
    float getL(float lambda, float Po, float M, float mu);
    float getW(float lambda, float Po, float M, float mu);
    float getLq(float L, float lambda, float mu);
    float getWq(float W, float Lq, float mu, float lambda);
    int factorial(int factor);

};

#endif