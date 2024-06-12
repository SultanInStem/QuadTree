#include "Point.hpp"
#include <SFML/Graphics.hpp> 
#ifndef CANVAS_HPP 
#define CANVAS_HPP 

class Canvas{
    public:
        Canvas(int width, int height, int numPoints=0); 
        ~Canvas();

        void run(); 
    private:
        sf::RenderWindow window; 
        sf::Clock clock;

        void handleEvents();
        void update(float dt); 
        void render();

        Point* p_pointsArray;
        int numPoints;
};


#endif 