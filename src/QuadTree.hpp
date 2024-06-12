#include "Point.hpp"
#include <iostream>
#include <vector>
#ifndef QUAD_TREE_HPP
#define QUAD_TREE_HPP

class QuadTree{
    private: 
        int capacity;
        bool isDivided = false;
        sf::RectangleShape boundary; 
        QuadTree* NE;
        QuadTree* NW;
        QuadTree* SW;
        QuadTree* SE; 
        std::vector<Point> points;
        sf::RectangleShape shape; 
    public:
        QuadTree(const sf::RectangleShape& bounds, int capacity); 
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
                if(NE->insert(point)) return true;
                else if(NW->insert(point)) return true;
                else if(SW->insert(point)) return true; 
                else if(SE->insert(point)) return true;
            }
            return false;
        }
        void subdivide(){
            float x = boundary.getPosition().x; 
            float y = boundary.getPosition().y; 
            float w = boundary.getSize().x / 2; 
            float h = boundary.getSize().y / 2;
            isDivided = true;
            sf::RectangleShape northeast;
            northeast.setPosition(sf::Vector2f(x + (w / 2), y - (h / 2) )); 
            NE = new QuadTree(northeast, this->capacity);

            sf::RectangleShape northwest;
            northwest.setPosition(sf::Vector2f(x - (w / 2), y - (h / 2) )); 
            NW = new QuadTree(northwest,this->capacity);


            sf::RectangleShape southeast;
            southeast.setPosition(sf::Vector2f(x + (w / 2), y + (h / 2) )); 
            SE = new QuadTree(southeast,this->capacity);


            sf::RectangleShape southwest;
            southwest.setPosition(sf::Vector2f(x - (w / 2), y + (h / 2) ));  
            SW = new QuadTree(southwest,this->capacity);

        }
        bool contains(Point& point){
            return (
                point.getPos().x > boundary.getPosition().x - (boundary.getSize().x / 2) && 
                point.getPos().x < boundary.getPosition().x + (boundary.getSize().x / 2) && 
                point.getPos().y > boundary.getPosition().y - (boundary.getSize().y / 2) &&
                point.getPos().y < boundary.getPosition().y + (boundary.getSize().y / 2)
            ); 
        }
};


#endif