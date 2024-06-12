#include "Canvas.hpp"
#include "Utils.hpp"

Canvas::Canvas(int width, int height, int numPoints){
    // shape.setSize(sf::Vector2f(width,height));
    // shape.setFillColor(sf::Color::Red);
    // shape.setOrigin(sf::Vector2f(width / 2, height / 2));
    // shape.setPosition(sf::Vector2f(width / 2, height / 2));


    sf::RectangleShape boundaryBox; 
    boundaryBox.setSize(sf::Vector2f(width, height));
    boundaryBox.setOrigin(sf::Vector2f(width / 2.0f, height / 2.0f));
    boundaryBox.setPosition(sf::Vector2f(width / 2.0f, height / 2.0f));
    qtree = new QuadTree(boundaryBox, 4);

    this->numPoints = numPoints; 
    p_pointsArray = new Point[numPoints];

    for(int i = 0; i < numPoints; i++){
        p_pointsArray[i] = Point(randomInt(10, width-10), randomInt(10, height-10), 5);
        qtree->insert(p_pointsArray[i]);
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