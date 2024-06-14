#include "Canvas.hpp"
#include "Utils.hpp"
#include "Boundary.hpp"
using std::cout; 


Canvas::Canvas(int width, int height, int numPoints){
    
    queryRegion = new Boundary(width / 2, height / 2, 100, 100);
    queryRegion->setBorderColor(sf::Color::Green);
    shape = new Boundary(width / 2,height / 2, width, height);

    qtree = new QuadTree(shape, 4);


    for(int i = 0; i < numPoints; i++){
        myPoints.push_back(new Point(randomInt(40, width - 500), randomInt(30, height - 100), 3));
        myPoints[i]->setVelocity(1,0.5);
    }
    for(int i = 0; i < numPoints; i++){
        qtree->insert(myPoints[i]);
    }

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    window.create(sf::VideoMode(width, height), "Title", sf::Style::Titlebar | sf::Style::Close, settings);
    window.setFramerateLimit(90);
}

Canvas::~Canvas(){
    if(qtree != nullptr){
        delete qtree;
        qtree = nullptr; 
    }
    if(queryRegion != nullptr){
        delete queryRegion;
        queryRegion = nullptr;
    }
    for(int i = 0; i < foundPoints.size(); i++){
        delete foundPoints[i];
    }
    for(int i = 0; i < myPoints.size();i++){
        delete myPoints[i];
    }
}

void Canvas::run(){
    while (window.isOpen()){
        float dt = clock.restart().asSeconds();
        window.clear(sf::Color::Black);
        logFPS(dt);
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
        // else if(event.type == sf::Event::MouseMoved){
        //     // float mouseX = sf::Mouse::getPosition(window).x;
        //     // float mouseY = sf::Mouse::getPosition(window).y;
        //     // queryRegion->setPosition(mouseX,mouseY);
        // }
    }
    
}
void Canvas::update(float dt){
    if(qtree != nullptr) qtree->clearExceptRoot();
    foundPoints.clear();

    for(int i = 0; i < myPoints.size(); i++){
        myPoints[i]->setColor(sf::Color::White);
        myPoints[i]->move(window.getSize().x, window.getSize().y, dt);
        myPoints[i]->show(window);
        qtree->insert(myPoints[i]);
    }
}
void Canvas::render(){

    if(qtree != nullptr) qtree->show(window);
    // window.draw(queryRegion->getShape());
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