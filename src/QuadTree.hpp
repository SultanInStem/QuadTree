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
                if(NE != nullptr && NE->insert(point)) return true;
                else if(NW != nullptr && NW->insert(point)) return true;
                else if(SW != nullptr && SW->insert(point)) return true; 
                else if(SE != nullptr && SE->insert(point)) return true;
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
            northeast.setSize(sf::Vector2f(w, h));
            northeast.setOrigin(sf::Vector2f(x + (w / 2), y - (h / 2)));
            northeast.setPosition(sf::Vector2f(x + (w / 2), y - (h / 2) )); 
            NE = new QuadTree(northeast, this->capacity);

            sf::RectangleShape northwest;
            northwest.setSize(sf::Vector2f(w, h));
            northwest.setOrigin(sf::Vector2f(x - (w / 2), y - (h / 2) ));
            northwest.setPosition(sf::Vector2f(x - (w / 2), y - (h / 2))); 
            NW = new QuadTree(northwest,this->capacity);


            sf::RectangleShape southeast;
            southeast.setSize(sf::Vector2f(w , h ));
            southeast.setOrigin(sf::Vector2f(x + (w / 2), y + (h / 2) ));
            southeast.setPosition(sf::Vector2f(x + (w / 2), y + (h / 2) )); 
            SE = new QuadTree(southeast,this->capacity);


            sf::RectangleShape southwest;
            southwest.setSize(sf::Vector2f(w , h ));
            southwest.setOrigin(sf::Vector2f(x - (w / 2), y + (h / 2) ));
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
        void show(sf::RenderWindow& window){
            boundary.setOutlineThickness(1); 
            boundary.setOutlineColor(sf::Color::White);  
            boundary.setFillColor(sf::Color::Transparent);
            window.draw(boundary);
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