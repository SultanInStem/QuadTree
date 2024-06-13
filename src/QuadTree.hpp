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
            if(!contains(point)) return false; 

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
            Boundary northeast(x + (w /2), y - (h / 2), w / 2, h / 2 );
            NE = new QuadTree(&northeast, this->capacity);

            Boundary northwest(x - (w /2), y - (h / 2), w / 2, h / 2 );
            NW = new QuadTree(&northwest,this->capacity);


            Boundary southeast(x + (w/2), y + (h/2), w/2, h/2);
            SE = new QuadTree(&southeast,this->capacity);


            Boundary southwest(x - (w / 2), y + (h / 2), w / 2, h / 2);
            SW = new QuadTree(&southwest,this->capacity);

        }
        bool contains(Point& point){
            return (
                point.getPos().x > boundary->x - (boundary->x / 2) && 
                point.getPos().x < boundary->x + (boundary->x / 2) && 
                point.getPos().y > boundary->y - (boundary->y / 2) &&
                point.getPos().y < boundary->y + (boundary->y / 2)
            ); 
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