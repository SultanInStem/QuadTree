#include "Point.hpp"
#include <SFML/Graphics.hpp>
#ifndef BOUNDARY_HPP 
#define BOUNDARY_HPP

class Boundary{
    public: 
        float x,y,w,h; 
        Boundary(float x, float y, float w, float h);
        ~Boundary();
        sf::RectangleShape getShape(){
            return this->shape; 
        }
        bool contains(Point* point){
            return (
                point->getPos().x >= x - (w / 2) && 
                point->getPos().x <= x + (w / 2) && 
                point->getPos().y >= y - (h / 2) &&
                point->getPos().y <= y + (h / 2)
            ); 
        }
        void setBorderColor(sf::Color color){
            shape.setOutlineColor(color);
        }
        void setPosition(float x1, float y1){
            x = x1;
            y = y1;
            shape.setPosition(sf::Vector2f(x,y));
        }
        bool intersects(Boundary*& treeRegion){
            return!(
                x + (w / 2) < treeRegion->x - (treeRegion->w / 2) ||    
                x - (w / 2) > treeRegion->x + (treeRegion->w / 2) || 
                y - (h / 2)  > treeRegion->y + (treeRegion->h / 2)|| 
                y + (h / 2) < treeRegion->y - (treeRegion->h / 2)
            );
        }
        
    private: 
        sf::RectangleShape shape;        
};

#endif