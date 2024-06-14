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
        Boundary* net = nullptr;
        std::vector<Point*> foundPoints;

        void handleEvents();
        void update(float dt); 
        void render();

        void logFPS(float dt);
        int frameCount; 
        float fpsTime;

        Point* p_pointsArray = nullptr;
        int numPoints;

        QuadTree* qtree = nullptr;
};


#endif 