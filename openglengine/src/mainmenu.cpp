#include "mainmenu.hpp"
#include "button.hpp"

void mainmenu::loadScene(RenderWindow &w){
    //yeeett
    button buttonObject = button("button", 10, 10, 40, 40);
    addGameObject(buttonObject, w);
}

void mainmenu::updateScene(){

}

void mainmenu::endScene(){

}