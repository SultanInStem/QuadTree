#include "Canvas.hpp"
#include "Utils.hpp"
#include "Boundary.hpp"

Canvas::Canvas(int width, int height, int numPoints){
    shape = new Boundary(width / 2,height / 2, width, height);

    qtree = new QuadTree(shape, 4);

    this->numPoints = numPoints; 
    p_pointsArray = new Point[numPoints];

    for(int i = 0; i < numPoints; i++){
        p_pointsArray[i] = Point(randomInt(400, width - 200), randomInt(30, height), 3);
    }
    for(int j = 0; j < numPoints; j++){
        qtree->insert(p_pointsArray[j]);
    }   

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    window.create(sf::VideoMode(width, height), "Title", sf::Style::Titlebar | sf::Style::Close, settings);
}

Canvas::~Canvas(){
    delete[] p_pointsArray; 
    delete qtree;
}


void Canvas::run(){
    while (window.isOpen()){
        float dt = clock.restart().asSeconds();
        handleEvents(); 
        update(dt); 
        render();
    }
}

void Canvas::handleEvents(){
    sf::Event event;
    while (window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            window.close(); 
        }
    }
    
}
void Canvas::update(float dt){
}
void Canvas::render(){
    window.clear(sf::Color::Black); 
    for(int i = 0; i < numPoints; i++){
        p_pointsArray[i].show(window);
    }
    qtree->show(window);
    window.display();
}