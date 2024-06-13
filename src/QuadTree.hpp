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
        void deleteNodes(QuadTree* node){
            if (node == nullptr) {
                return;
            }
            // Recursively delete children nodes
            deleteNodes(node->NE);
            deleteNodes(node->NW);
            deleteNodes(node->SW);
            deleteNodes(node->SE);
            // Delete the current node (except the root)
            if (node != this) {
                delete node;
            }
        }
    public:
        QuadTree(Boundary* bounds, int capacity); 
        ~QuadTree();
        void deleteAllNodes(){
            deleteNodes(this);
        }
        bool insert(Point& point){
            // if this quadtree does not contain a point, return 
            if(!boundary->contains(point)) return false;

            if(points.size() < capacity - 1){
                points.push_back(point);
                return true; 
            }else{
                if(!isDivided){
                    subdivide();
                }
                if(NE != nullptr && NE->insert(point)) return true;
                if(NW != nullptr && NW->insert(point)) return true;
                if(SW != nullptr && SW->insert(point)) return true; 
                if(SE != nullptr && SE->insert(point)) return true;
            }
            return false;
        }
        void subdivide(){
            float x = boundary->x; 
            float y = boundary->y;
            float w = boundary->w / 2; 
            float h = boundary->h / 2;
            isDivided = true;

            NE = new QuadTree(new Boundary(x + (w / 2), y - (h / 2), w, h), this->capacity);

            NW = new QuadTree(new Boundary(x - (w / 2), y - (h / 2), w, h), this->capacity);

            SE = new QuadTree(new Boundary(x + (w / 2), y + (h / 2), w, h), this->capacity);

            SW = new QuadTree(new Boundary(x - (w / 2), y + (h / 2), w, h), this->capacity);

        }
        std::vector<Point> query(){
            return points;
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