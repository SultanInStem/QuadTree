#include <SFML/Graphics.hpp> 
#ifndef POINT_HPP
#define POINT_HPP 

class Point{
    private:
        sf::Vector2f velocity;
        sf::CircleShape circle;
    public:
        Point(float x, float y, float r){
            circle.setPosition(sf::Vector2f(x,y));
            circle.setRadius(r);
            circle.setFillColor(sf::Color::White); 
            velocity.x = 1; 
            velocity.y = 1; 
        };
        ~Point(){

        };
        void setVelocity(float x, float y){
            velocity.x = x; 
            velocity.y = y;
        }
        void move(){
            circle.move(velocity.x, velocity.y);
        }
        float getRadius(){
            return circle.getRadius(); 
        }
        sf::Vector2f getPos(){
            return circle.getPosition(); 
        }
};

#endif