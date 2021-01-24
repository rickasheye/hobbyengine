#ifndef SCENELOADER_HPP
#define SCENELOADER_HPP
#include "scene.hpp"
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "gameObject.hpp"

using namespace std;
class gameObject;
class scene;
class sceneLoader{
    public:
        sceneLoader(){printf("based \n");}
        list<scene> sceneList;
        
        bool loadScene(scene &readscene, RenderWindow &win);
        bool writeScene(scene writescene);
        int getScene(scene scenecompare);
        bool sceneExists(scene scenecompare);
        bool deleteScene(scene deleteScene);
        scene get(list<scene>, int _i);
        scene sceneCurrent;
};
#endif