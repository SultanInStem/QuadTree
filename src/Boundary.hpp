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
        bool contains(Point& point){
            return (
                point.getPos().x >= x - (w / 2) && 
                point.getPos().x <= x + (w / 2) && 
                point.getPos().y >= y - (h / 2) &&
                point.getPos().y <= y + (h / 2)
            ); 
        }
        void setBorderColor(sf::Color color){
            shape.setOutlineColor(color);
        }
        
    private: 
        sf::RectangleShape shape;        
};

#endif