#include "analytics.hpp"
#include <iostream>
#include <math.h>

float analytics::getPo(float lambda, float M, float mu)
{
    int counter = 0;
    float summation = 0;
    while (counter<M)
    {
        summation += (1 / factorial(counter)) * pow((lambda / mu), counter);
        counter++;
    }
    return 1/(summation+((1/M)*pow(lambda/mu, M))*(M/(M*(mu-lambda))));
    }

    float analytics::getL(float lambda, float Po, float M, float mu)
    {
    }
    float analytics::getW(float lambda, float Po, float M, float mu)
    {
    }
    float analytics::getLq(float L, float lambda, float mu)
    {
    }
    float analytics::getWq(float W, float Lq, float mu, float lambda)
    {
    }

    int analytics::factorial(int factor)
    {
        if(factor == 0)
            return 1;
        int result = 1;
        while (factor >= 1)
        {
            result *= factor;
            --factor;
        }
        return result;
    }
