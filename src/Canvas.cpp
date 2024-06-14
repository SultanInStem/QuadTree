#include "Canvas.hpp"
#include "Utils.hpp"
#include "Boundary.hpp"
using std::cout; 


Canvas::Canvas(int width, int height, int numPoints){
    queryRegion = new Boundary(width / 2, height / 2, 100, 100);
    queryRegion->setBorderColor(sf::Color::Green);
    shape = new Boundary(width / 2,height / 2, width, height);

    qtree = new QuadTree(shape, 4);

    this->numPoints = numPoints; 
    p_pointsArray = new Point[numPoints];

    for(int i = 0; i < numPoints; i++){
        p_pointsArray[i] = Point(randomInt(40, width - 500), randomInt(30, height - 100), 3);
    }
    for(int i = 0; i < numPoints; i++){
        qtree->insert(&p_pointsArray[i]);
    }

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    window.create(sf::VideoMode(width, height), "Title", sf::Style::Titlebar | sf::Style::Close, settings);
    window.setFramerateLimit(90);
}

Canvas::~Canvas(){
    if(p_pointsArray != nullptr){
        delete[] p_pointsArray; 
        p_pointsArray = nullptr; 
    }
    if(qtree != nullptr){
        delete qtree;
        qtree = nullptr; 
    }
    delete queryRegion;
    queryRegion = nullptr;
    for(int i = 0; i < foundPoints.size(); i++){
        delete foundPoints[i];
    }
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
        }else if(event.type == sf::Event::MouseMoved){
            float mouseX = sf::Mouse::getPosition(window).x;
            float mouseY = sf::Mouse::getPosition(window).y;
            queryRegion->setPosition(mouseX,mouseY);
        }
    }
    
}
void Canvas::update(float dt){
    logFPS(dt);
    if(qtree != nullptr) qtree->clearExceptRoot();

    for(int i = 0; i < numPoints; i++){
        p_pointsArray[i].setColor(sf::Color::White);
        p_pointsArray[i].move();
        qtree->insert(&p_pointsArray[i]);
    }
    foundPoints.clear(); 
    qtree->query(queryRegion, foundPoints);
    for(auto point : foundPoints){
        point->setColor(sf::Color::Green);
    }
}
void Canvas::render(){
    window.clear(sf::Color::Black); 
    for(int i = 0; i < numPoints; i++){
        p_pointsArray[i].show(window);
    }
    if(qtree != nullptr) qtree->show(window);
    window.draw(queryRegion->getShape());
    window.display();
}
void Canvas::logFPS(float dt){
    if(fpsTime < 1.0f){
        fpsTime += dt;
        frameCount++; 
    }else{
        cout << "FPS: " << frameCount << "\n";
        fpsTime = 0; 
        frameCount = 0;
    }
}