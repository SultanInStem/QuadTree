#include "Canvas.hpp"
#include "Utils.hpp"
#include "Boundary.hpp"
#include <SFML/Graphics.hpp>
using std::cout; 


Canvas::Canvas(int width, int height, int numPoints){
    
    queryRegion = new Boundary(width / 2, height / 2, 100, 100);
    shape = new Boundary(width / 2,height / 2, width, height);
    qtree = new QuadTree(shape, 4);




    for(int i = 0; i < numPoints; i++){
        myPoints.push_back(new Point(randomInt(0, width), randomInt(30, height), 4));
        myPoints[i]->setVelocity(0.1,0.1);
        qtree->insert(myPoints[i]);
    }

    // if(!font.loadFromFile("assets/OpenSans-Medium.ttf")){
    //     cout << "Font is failed to load \n"; 
    //     exit(1);
    // }
    // fpsText.setFont(font);
    // fpsText.setCharacterSize(40);
    // fpsText.setString("FPS Without QT: _");
    // fpsText.setPosition(sf::Vector2f(0,0));
    // fpsText.setFillColor(sf::Color::Green);

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    window.create(sf::VideoMode(width, height), "QuadTree Collisions", sf::Style::Titlebar | sf::Style::Close, settings);
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
        // primitiveUpdate(dt);
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
    if(qtree != nullptr) qtree->clearExceptRoot();
    foundPoints.clear();

    for(int i = 0; i < myPoints.size(); i++){
        myPoints[i]->setColor(sf::Color::White);
        qtree->insert(myPoints[i]);
    }

    for(int i = 0; i < myPoints.size(); i++){
        float r = myPoints[i]->getRadius(); 
        foundPoints.clear(); 
        myPoints[i]->randomMove(window.getSize().x, window.getSize().y);
        queryRegion->setPosition(myPoints[i]->getPos().x,  myPoints[i]->getPos().y);
        queryRegion->setSize(r + 40, r + 40);
        qtree->query(queryRegion, foundPoints);
        for(int j = 0; j < foundPoints.size(); j++){                
            if(myPoints[i] != foundPoints[j] && myPoints[i]->isCollided(foundPoints[j])){
                myPoints[i]->setColor(sf::Color::Red);
                foundPoints[j]->setColor(sf::Color::Red);
            }
        }
        myPoints[i]->show(window); 
    }
}
void Canvas::primitiveUpdate(float dt){
    for(int i = 0; i < myPoints.size(); i++){
        myPoints[i]->setColor(sf::Color::White);
        myPoints[i]->randomMove(window.getSize().x, window.getSize().y);
        for(int j = 0; j < myPoints.size(); j++){
            if(myPoints[i] != myPoints[j] && myPoints[i]->isCollided(myPoints[j])){
                myPoints[i]->setColor(sf::Color::Red);
                myPoints[j]->setColor(sf::Color::Red);
            }
        }
        myPoints[i]->show(window);
    }
}
void Canvas::render(){
    if(qtree != nullptr) qtree->show(window);
    window.display();
}
void Canvas::logFPS(float dt){
    if(fpsTime < 1.0f){
        fpsTime += dt;
        frameCount++; 
    }else{
        // std::string s = "FPS With QT: "; 
        // s.append(std::to_string(frameCount));
        // s.append("  N-of Points: ");
        // s.append(std::to_string(myPoints.size()));
        // fpsText.setString(s);
        cout << "FPS: " << frameCount << "\n";
        fpsTime = 0; 
        frameCount = 0;
    }
}