#include <SFML/Graphics.hpp>
#include "QuadTree.hpp"
#include "Boundary.hpp"

QuadTree::QuadTree(Boundary* bounds, int capacity){
    NE = nullptr; 
    NW = nullptr;
    SE = nullptr;
    SW = nullptr;
    boundary = bounds;
    this->capacity = capacity;
}

QuadTree::~QuadTree(){
        if (NE != nullptr) {
        delete NE;
        NE = nullptr; // Reset the pointer after deletion
    }
    if (NW != nullptr) {
        delete NW;
        NW = nullptr;
    }
    if (SE != nullptr) {
        delete SE;
        SE = nullptr;
    }
    if (SW != nullptr) {
        delete SW;
        SW = nullptr;
    }
    if (boundary != nullptr) {
        delete boundary;
        boundary = nullptr;
    }
    // delete NE;
    // delete NW;
    // delete SE;
    // delete SW; 
    // delete boundary;
}