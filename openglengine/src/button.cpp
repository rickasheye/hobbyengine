//the base class for all buttons
#include "button.hpp"
#include <SFML/Graphics.hpp> 
#include <SFML/System/Vector2.hpp>
using namespace sf;
RectangleShape shape;

button::button(string name, int xpos, int ypos, int xs, int ys){
    gameObject::setupGameObject(name, xpos, ypos, xs, ys);
}

void button::drawObject(RenderWindow& w){
    //draw a button here.
    //w.draw(shape);
}

void button::startObject(RenderWindow &w){
    //When the scene starts execute this function!
    gameObject::startObject(w);
    shape.setFillColor(Color(100, 250, 50));
    shape.setOutlineThickness(5);
    shape.setOutlineColor(Color(250, 150, 100));
    printf("started a button");
}