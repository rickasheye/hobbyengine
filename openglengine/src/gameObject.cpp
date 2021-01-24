#include "gameObject.hpp"

gameObject::gameObject(){
    Console::WriteError("Unable to create a gameobject without a name, position and size");
}

gameObject::gameObject(string name, int posx, int posy, int sizex, int sizey){
    setupGameObject(name, posx, posy, sizex, sizey);
}

gameObject::gameObject(string name, int posx, int posy){
    setupGameObject(name, posx, posy, 0, 0);
}

gameObject::gameObject(string name){
    Console::WriteWarning("Not recommended to create a gameobject without a position and size");
    setupGameObject(name, 0, 0, 0, 0);
}

void gameObject::setupGameObject(string name, int posx, int posy, int sizex, int sizey){
    Console::WriteLine(Concatenate::JoinString("Object by the name of", name, "has recently been instantiated!", " ").c_str());
    this->name = name;
    this->posx = posx;
    this->posy = posy;
    this->sizex = sizex;
    this->sizey = sizey;
}

bool gameObject::operator!=(gameObject const &obj){
    if(obj.name == name && obj.posx == posx && obj.posy == posy && obj.sizex == sizex && obj.sizey == sizey){
        return false;
    }else{
        return true;
    }
}