#include "Boundary.hpp"

Boundary::Boundary(float x, float y, float w, float h){
    this->x = x; 
    this->y = y; 
    this->w = w;
    this->h = h;
    shape.setSize(sf::Vector2f(w, h));
    shape.setOrigin(sf::Vector2f(w / 2, h / 2));
    shape.setPosition(sf::Vector2f(x,y));

    shape.setOutlineColor(sf::Color::White); 
    shape.setOutlineThickness(0.3);
    shape.setFillColor(sf::Color::Transparent);
}

Boundary::~Boundary(){

}