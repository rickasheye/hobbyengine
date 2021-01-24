//base class for a scene and the scene loader
#ifndef SCENE_HPP
#define SCENE_HPP
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include "gameObject.hpp"
#include "Console.hpp"
using namespace std;

class sceneLoader;
class gameObject;
class scene {
    public:
        string name = "empty";
        vector<gameObject> *gameObjects;
        virtual void loadScene(sf::RenderWindow& w){ Console::WriteLine(Concatenate::JoinString("Loaded:", name, " ").c_str());};
        virtual void updateScene(){};
        virtual void endScene(){};
        scene(){}
        scene(string sceneName){name = sceneName;}
        bool operator != (scene const &obj);
        void addGameObject(gameObject &objectRef, sf::RenderWindow &w);
        void removeGameObject(gameObject &objectRef);
        bool gameObjectExists(string name);
        bool gameObjectExists(gameObject &gameObject);
        gameObject& getGameObject(int _i);
        gameObject& getGameObject(gameObject &ref);
};
#endif