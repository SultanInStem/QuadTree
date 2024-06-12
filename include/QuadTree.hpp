#include <iostream>

#ifndef QUAD_TREE_HPP
#define QUAD_TREE_HPP

class QuadTree{
    private: 
        int capacity; 
        QuadTree* NE;
        QuadTree* NW;
        QuadTree* SW;
        QuadTree* SE; 
    public:
        QuadTree(); 
        ~QuadTree();

        void insert(){
            
        }
};


#endif