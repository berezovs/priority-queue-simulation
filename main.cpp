 #include "Shell.hpp"
 #include "Customer.hpp"

 int main(){
     Shell shell;
     shell.run();
     Customer * customer = new Customer(11.55);

     return 0;
 }