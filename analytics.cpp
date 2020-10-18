/***************************************************************
  Student Name:Serghei Berezovschi
  File Name: analytics.cpp
  Assignment number:Project 2-DS&AII

 this namespace contains functions that generate data for the analytical model
***************************************************************/
#include "analytics.hpp"
#include <math.h>
#include <stdint.h>



float analytics::getPo(float lambda, float M, float mu)
{
    int counter = 0;
    float sum = 0;
    while (counter < M)
    {
        sum += (1 / factorial(counter)) * pow((lambda / mu), counter);
        counter++;
    }
    return 1 / (sum + ((1 / M) * pow(lambda / mu, M)) * (M / (M * (mu - lambda))));
}

float analytics::getL(float lambda, float Po, float M, float mu)
{
    return ((lambda * mu * pow(lambda / mu, M)) / (factorial(M - 1) * pow((M * mu - lambda), 2))) * Po + (lambda / mu);
}
float analytics::getW(float lambda, float L)
{
    return L / lambda;
}
float analytics::getLq(float L, float lambda, float mu)
{
    return (L - (lambda / mu));
}
float analytics::getWq(float Lq, float lambda)
{
    return Lq / lambda;
}

float analytics::rho(float lambda, float M, float mu)
{
    return lambda / (M * mu);
}

uint32_t analytics::factorial(uint32_t factor)
{
    if (factor == 0)
        return 1;
    int result = 1;
    while (factor >= 1)
    {
        result *= factor;
        --factor;
    }
    return result;
}
