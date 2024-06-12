#include <SFML/Graphics.hpp> 
#pragma once


class Rectangle{
    public: 
        float h, w; 
        Rectangle(float x, float y, float w, float h){
            rect.setPosition(sf::Vector2f(x,y)); 
            
        };
        ~Rectangle(){

        }; 
    private:
        sf::RectangleShape rect;
};