/***************************************************************
  Student Name:Serghei Berezovschi
  File Name: Shell.cpp
  Assignment number:Project 2-DS&AII

 
***************************************************************/
#include <iostream>
#include "Shell.hpp"
#include "EventLoop.hpp"

Shell::Shell()
{
}

void Shell::run()
{
    const uint32_t MIN_NUM_OF_SERVERS = 1;
    const uint32_t MAX_NUM_OF_SERVERS = 10;
    float n, lambda, mu, M{0};

    std::cout << "Enter total number of arrivals(n): ";
    std::cin >> n;

    std::cout << "Enter average number of arrivals per time unit(lambda): ";
    std::cin >> lambda;

    std::cout << "Enter average number of people served in a time period(mu): ";
    std::cin >> mu;

    while (M > MAX_NUM_OF_SERVERS || M < MIN_NUM_OF_SERVERS)
    {
        std::cout << "Enter the number of service channels(M), min = 1, max = 10: ";
        std::cin >> M;
        std::cin.clear();
    }

    std::cout << "Starting the simulation...\n";
    EventLoop *eLoop = new EventLoop(n, lambda, mu, M);
    eLoop->loop();
    delete eLoop;
}