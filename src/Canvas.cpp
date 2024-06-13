#include "Canvas.hpp"
#include "Utils.hpp"
#include "Boundary.hpp"

Canvas::Canvas(int width, int height, int numPoints){

    // net = new Boundary(width / 2,height / 2, 100, 100);
    // net->setBorderColor(sf::Color::Green);

    shape = new Boundary(width / 2,height / 2, width, height);

    qtree = new QuadTree(shape, 4);

    this->numPoints = numPoints; 
    p_pointsArray = new Point[numPoints];

    for(int i = 0; i < numPoints; i++){
        p_pointsArray[i] = Point(randomInt(40, width - 500), randomInt(30, height - 100), 3);
        qtree->insert(p_pointsArray[i]);
    }

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    window.create(sf::VideoMode(width, height), "Title", sf::Style::Titlebar | sf::Style::Close, settings);
}

Canvas::~Canvas(){
    delete[] p_pointsArray; 
    delete qtree;
    delete shape;
    delete net;
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
    qtree->clearExceptRoot();
    for(int i = 0; i < numPoints; i++){
        p_pointsArray[i].move();
        qtree->insert(p_pointsArray[i]);
    }
    // float mouseX = sf::Mouse::getPosition().x; 
    // float mouseY = sf::Mouse::getPosition().y; 
}
void Canvas::render(){
    window.clear(sf::Color::Black); 
    for(int i = 0; i < numPoints; i++){
        p_pointsArray[i].show(window);
    }
    if(qtree != nullptr) qtree->show(window);
    // window.draw(net->getShape());
    window.display();
}