#include <SFML/Graphics.hpp>
#include "QuadTree.hpp"

QuadTree::QuadTree(const sf::RectangleShape& bounds, int capacity){
    NE = nullptr; 
    NW = nullptr;
    SE = nullptr;
    SW = nullptr;
    boundary = bounds; 
    this->capacity = capacity;
}

QuadTree::~QuadTree(){
    delete NE;
    delete NW;
    delete SE;
    delete SW; 
}