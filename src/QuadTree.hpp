#include "Boundary.hpp"
#include "Point.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#ifndef QUAD_TREE_HPP
#define QUAD_TREE_HPP

class QuadTree{
    private: 
        int capacity;
        bool isDivided = false;
        Boundary* boundary; 
        QuadTree* NE;
        QuadTree* NW;
        QuadTree* SW;
        QuadTree* SE; 
        std::vector<Point> points;
        sf::RectangleShape shape; 
    public:
        QuadTree(Boundary* bounds, int capacity); 
        ~QuadTree();

        bool insert(Point& point){
            // if this quadtree does not contain a point, return 
            if(!boundary->contains(point)) return false;

            if(points.size() < capacity){
                points.push_back(point);
                return true; 
            }else{
                if(!isDivided){
                    subdivide();
                }
                if(NE != nullptr && NE->insert(point)) return true;
                else if(NW != nullptr && NW->insert(point)) return true;
                else if(SW != nullptr && SW->insert(point)) return true; 
                else if(SE != nullptr && SE->insert(point)) return true;
            }
            return false;
        }
        void subdivide(){
            float x = boundary->x; 
            float y = boundary->y;
            float w = boundary->w; 
            float h = boundary->h;
            isDivided = true;

            NE = new QuadTree(new Boundary(x + (w / 4), y - (h / 4), w / 2, h / 2), 4);

            NW = new QuadTree(new Boundary(x - (w / 4), y - (h / 4), w / 2, h / 2 ),4);

            SE = new QuadTree(new Boundary(x + (w / 4), y + (h / 4), w / 2, h / 2),4);

            SW = new QuadTree(new Boundary(x - (w / 4), y + (h / 4), w / 2, h / 2), 4);

        }
        void show(sf::RenderWindow& window){
            window.draw(boundary->getShape());
            if(isDivided){
                if(NW != nullptr){
                    NW->show(window);
                }
                if(NE != nullptr){
                    NE->show(window); 
                }
                if(SW != nullptr){
                    SW->show(window); 
                }
                if(SE != nullptr){
                    SE->show(window);
                }
            }
        }
};


#endif