/***************************************************************
  Student Name:Serghei Berezovschi
  File Name: main.cpp
  Assignment number:Project 2-DS&AII

 
***************************************************************/

#include "Shell.hpp"

int main()
{
    
    Shell *shell = new Shell();
    shell->run();
    delete shell;
    return 0;
}