#include "scene.hpp"

bool scene::operator!=(scene const &obj)
{
    bool mayYes = false;
    if (obj.name != name)
    {
        //they're not the same otherwise they cannot exist as one
        mayYes = true;
    }
    return mayYes;
}

//game object stuff
void scene::addGameObject(gameObject &objectRef, RenderWindow& w)
{
    if (gameObjectExists(objectRef.name))
    {
        Console::WriteWarning(Concatenate::JoinString("Object", objectRef.name, "already exists!", " ").c_str());
    }
    else
    {
        //add the object
        gameObjects->push_back(objectRef);
        objectRef.startObject(w);
    }
}

void scene::removeGameObject(gameObject &objectRef)
{
    if (gameObjectExists(objectRef.name))
    {
        //remove the object
        vector<gameObject>::iterator it = gameObjects->begin();
        for (int i = 0; i < gameObjects->size(); i++)
        {
            ++it;
            if (it->name == objectRef.name)
            {
                gameObjects->erase(it);
                break;
            }
        }
    }
    else
    {
        Console::WriteLine(Concatenate::JoinString("The Object", objectRef.name, "doesnt exist!", " ").c_str());
    }
}

bool scene::gameObjectExists(string name)
{
    vector<gameObject> gameObjects = gameObjects;
    bool yes = false;
    for (int i = 0; i < gameObjects.size(); i++)
    {
        gameObject objectGiven = getGameObject(i);
        if (objectGiven.name == name)
        {
            //this is the object we have to make reference to
            yes = true;
        }
    }
    return yes;
}

gameObject& scene::getGameObject(int _i)
{
    vector<gameObject>::iterator it = gameObjects->begin();
    for (int i = 0; i < _i; i++)
    {
        ++it;
    }
    return *it;
}

gameObject& scene::getGameObject(gameObject &ref)
{
    vector<gameObject> gameObjects = gameObjects;
    for (int i = 0; i < gameObjects.size(); i++)
    {
        gameObject select = getGameObject(i);
        if (select.name == ref.name && select != ref)
        {
            return select;
            break;
        }
    }
}