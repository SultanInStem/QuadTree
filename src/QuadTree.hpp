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
        std::vector<Point*> points;
        sf::RectangleShape shape; 
        void clearChildren(QuadTree*& node){
            // *& means 'give me a reference to a pointer and not a copy'; 
            if (node != nullptr) {
                // Clear the child node recursively
                node->clearExceptRoot();
                // Delete the child node
                delete node;
                // Set the pointer to null
                node = nullptr;
            }
        }
    public:
        QuadTree(Boundary* bounds, int capacity); 
        ~QuadTree();
        void clearExceptRoot() {
            clearChildren(NW);
            clearChildren(NE);
            clearChildren(SW);
            clearChildren(SE);

            // Clear the points vector
            points.clear();

            // Reset the isDivided flag
            isDivided = false;
        }


        bool insert(Point* point){
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
        std::vector<Point*> query(Boundary*& region, std::vector<Point*>& foundPoints){
            if(!region->intersects(boundary)){
                return (foundPoints);
            }
            for(int i = 0; i < points.size(); i++){
                if(region->contains(points[i])){
                    foundPoints.push_back(points[i]);
                }
            }
            if(isDivided){
                NW->query(region, foundPoints);
                NE->query(region, foundPoints); 
                SW->query(region, foundPoints); 
                SE->query(region, foundPoints);
            }
            return foundPoints;
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