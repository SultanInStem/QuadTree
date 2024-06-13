#include "Point.hpp"

Point::Point(float x, float y, float r){
    circle.setPosition(sf::Vector2f(x,y));
    circle.setRadius(r);
    circle.setFillColor(sf::Color::White); 
    velocity.x = 0.03; 
    velocity.y = 0.01; 
}

Point::~Point(){

}