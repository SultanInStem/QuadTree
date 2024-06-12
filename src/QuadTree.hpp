#include "Point.hpp"
#include <iostream>
#include <vector>
#ifndef QUAD_TREE_HPP
#define QUAD_TREE_HPP

class QuadTree{
    private: 
        int capacity;
        sf::FloatRect boundary; 
        QuadTree* NE;
        QuadTree* NW;
        QuadTree* SW;
        QuadTree* SE; 
        std::vector<Point> points;
    public:
        QuadTree(const sf::FloatRect& bounds, int capacity); 
        ~QuadTree();

        void insert(Point& point){
            
        }
};


#endif