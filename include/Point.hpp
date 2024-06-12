#include <SFML/Graphics.hpp> 
#ifndef POINT_HPP
#define POINT_HPP 

class Point{
    private:
        sf::CircleShape circle;
    public:
        Point(float x, float y, float r){
            circle.setPosition(sf::Vector2f(x,y));
            circle.setRadius(r);
            circle.setFillColor(sf::Color::White); 
        };
        ~Point(){

        };
        float getRadius(){
            return circle.getRadius(); 
        }
        sf::Vector2f getPos(){
            return circle.getPosition(); 
        }
};

#endif