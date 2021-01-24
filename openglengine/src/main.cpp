#include <SFML/Graphics.hpp>
#include "sceneloader.hpp"
#include "gameObject.hpp"
#include "mainmenu.hpp"
#include <stdio.h>
#include <iostream>

using namespace sf;

sceneLoader loader;

//create an empty scene before start to save on memory!
scene newScene = scene("empty");

const string engineName = "subright";

int main()
{
    try
    {
        Console::WriteLine(Concatenate::JoinString("Loading", engineName, "engine", " ").c_str());
        RenderWindow window(VideoMode(256, 240), "If your seeing this, it means that the engine has not loaded properly.");
        loader = sceneLoader();
        //loader.loadScene(newScene, window);
        mainmenu menuScene = mainmenu("mainmenu");
        loader.loadScene(menuScene, window);
        window.setTitle(engineName + " game-engine window");
        window.setFramerateLimit(50);
        Console::WriteLine(Concatenate::JoinString("Finished loading the", engineName, "engine (READY)", " ").c_str());
        //try to load the menu scene
        while (window.isOpen())
        {
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window.close();
            }
            //loader.sceneCurrent.updateGameObjects(window);

            window.setTitle(engineName + " - " + loader.sceneCurrent.name);
            window.clear();
            window.display();
        }
    }
    catch (char* errorMessage)
    {
        Console::WriteError(errorMessage);
        system("pause");
    }
}