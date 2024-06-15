#include <iostream> 
#include "Canvas.hpp"
#include "ctime"
using std::cout; 
// Dear friend, this code is prolly not the best implementation of the quadtree
// Please feel free to fix any bugs you find ;)
int main(){
    srand(time(0));

    Canvas canvas(1100,750, 1500);
    canvas.run(); 
    
    return 0; 
}