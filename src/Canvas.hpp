#include <iostream>
#include "Boundary.hpp"
#include "QuadTree.hpp"
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
        Boundary* shape = nullptr;
        Boundary* queryRegion = nullptr;
        std::vector<Point*> foundPoints;
        std::vector<Point*> myPoints;

        void handleEvents();
        void update(float dt); 
        void primitiveUpdate(float dt);
        void render();

        void logFPS(float dt);
        int frameCount =  0; 
        float fpsTime  =  0;


        QuadTree* qtree = nullptr;
};


#endif 