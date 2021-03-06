/***************************************************************
  Student Name:Serghei Berezovschi
  File Name: analytics.hpp
  Assignment number:Project 2-DS&AII

 
***************************************************************/
#ifndef ANALYTICS_H
#define ANALYTICS_H
#include <stdint.h>

namespace analytics{
    float getPo(float lambda, float M, float mu);
    float getL(float lambda, float Po, float M, float mu);
    float getW(float lambda, float L);
    float getLq(float L, float lambda, float mu);
    float getWq(float Lq, float lambda);
    float rho(float lambda, float M, float mu);
    uint32_t factorial(uint32_t factor);

};

#endif