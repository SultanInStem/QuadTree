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
        void setColor(sf::Color color){
            circle.setFillColor(color);
        }
        void move(int windowWidth, int windowHeight){
            float x = getPos().x; 
            float y = getPos().y; 
            if(x + velocity.x > windowWidth || x + velocity.x < 0){
                velocity.x = -1 * velocity.x; 
            }
            if(y + velocity.y > windowHeight || y + velocity.y < 0){
                velocity.y = -1 * velocity.y;
            }
            circle.move(velocity.x, velocity.y);
        }
        float getRadius(){
            return circle.getRadius(); 
        }
        sf::Vector2f getPos(){
            return circle.getPosition(); 
        }
        sf::Vector2f getVelocity(){
            return velocity;
        }
        void show(sf::RenderWindow& window){
            window.draw(circle);
        }
};

#endif