#include <SFML/Graphics.hpp>
#include "QuadTree.hpp"

QuadTree::QuadTree(const sf::FloatRect& bounds, int capacity){
    NE = nullptr; 
    NW = nullptr;
    SE = nullptr;
    SW = nullptr;
    boundary = bounds; 
    this->capacity = capacity;

    
}

QuadTree::~QuadTree(){

}