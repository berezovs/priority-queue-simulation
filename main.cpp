#include "Shell.hpp"

int main()
{
    
    Shell *shell = new Shell();
    shell->run();
    delete shell;
    return 0;
}