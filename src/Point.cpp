#include "Point.hpp"

Point::Point(float x, float y, float r){
    circle.setPosition(sf::Vector2f(x,y));
    circle.setRadius(r);
    circle.setFillColor(sf::Color::White); 
    velocity.x = 1; 
    velocity.y = 1; 
}

Point::~Point(){

}