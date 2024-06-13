#include <iostream> 
#include "Canvas.hpp"
#include "ctime"
using std::cout; 

int main(){
    srand(time(0));
    
    Canvas canvas(800,700, 30);
    canvas.run(); 
    
    return 0; 
}