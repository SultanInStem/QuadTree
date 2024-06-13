#include <iostream> 
#include "Canvas.hpp"
#include "ctime"
using std::cout; 

int main(){
    srand(time(0));

    Canvas canvas(1100,700, 200);
    canvas.run(); 
    
    return 0; 
}