#include <iostream> 
#include "Canvas.hpp"
#include "ctime"
using std::cout; 

int main(){
    srand(time(0));

    Canvas canvas(800,700, 80);
    canvas.run(); 
    
    return 0; 
}