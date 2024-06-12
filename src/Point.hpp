#include <SFML/Graphics.hpp>
#ifndef POINT_HPP
#define POINT_HPP 

class Point{
    private:
        sf::Vector2f velocity;
        sf::CircleShape circle;
    public:
        Point(float x=10, float y=10, float r=10);
        ~Point();
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
        void show(sf::RenderWindow& window){
            window.draw(circle);
        }
};

#endif