//base class for a scene and the scene loader
#ifndef MAINMENU_HPP
#define MAINMENU_HPP
#include "scene.hpp"

class scene;
class mainmenu : public scene
{
public:
    mainmenu();
    mainmenu(string sceneName){name = sceneName;}
    bool operator!=(scene const &obj)
    {
        bool mayYes = false;
        if (obj.name != name)
        {
            //they're not the same otherwise they cannot exist as one
            mayYes = true;
        }
        return mayYes;
    }
    void loadScene(RenderWindow &w) override;
    void updateScene() override;
    void endScene() override;
};
#endif