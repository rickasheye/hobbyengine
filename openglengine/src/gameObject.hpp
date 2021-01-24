//the header file for gameobjects
#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP
#include <stdio.h>
#include <string>
#include <list>
#include <SFML/Graphics.hpp>
#include "scene.hpp"

using namespace std;
using namespace sf;

class sceneLoader;
class gameObject
{
public:
    string name;
    int posx;
    int posy;
    int sizex;
    int sizey;
    gameObject();
    gameObject(string name, int posx, int posy, int sizex, int sizey);
    gameObject(string name, int posx, int posy);
    gameObject(string name);
    bool operator != (gameObject const &obj);
    void setupGameObject(string name, int posx, int posy, int sizex, int sizey);
    virtual void drawObject(RenderWindow &w){};
    virtual void startObject(RenderWindow &w){};
};
#endif