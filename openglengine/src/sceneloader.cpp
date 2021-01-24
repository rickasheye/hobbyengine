#include "sceneloader.hpp"

bool sceneLoader::loadScene(scene &readscene, RenderWindow &win)
{
    //load the scene duh
    if (sceneLoader::sceneExists(readscene))
    {
        //some how write stuff to the display!
        sceneCurrent = readscene;
        readscene.loadScene(win);
        Console::WriteLine(Concatenate::JoinString("Loading Scene", readscene.name, " ").c_str());
        return true;
    }
    else
    {
        bool sucess = writeScene(readscene);
        Console::WriteWarning(Concatenate::JoinString("Scene", readscene.name, "doesnt exist maybe it was not written yet? so writing and retrying!", " ").c_str());
        if (sucess)
        {
            Console::WriteLine(Concatenate::JoinString("Write sucessful for scene", readscene.name, "reloading...", " ").c_str());
            loadScene(readscene, win);
        }
        else
        {
            Console::WriteLine(Concatenate::JoinString("Unfortunately the scene write for", readscene.name, "was unsuccesful so quitting...", " ").c_str());
            return false;
        }
    }
}

bool sceneLoader::writeScene(scene writescene)
{
    //write the scene
    if (!sceneExists(writescene))
    {
        //Good now write it.
        sceneLoader::sceneList.push_back(writescene);
        Console::WriteLine(Concatenate::JoinString("Written the scene", writescene.name, "to memory sucessfully", " ").c_str());
        return true;
    }
    else
    {
        //Not good warn the user
        Console::WriteWarning(Concatenate::JoinString("Scene", writescene.name, "already exists! so not writing to memory", " ").c_str());
        return false;
    }
}

int sceneLoader::getScene(scene scenecompare)
{
    //get the scene
    list<scene> list = sceneLoader::sceneList;
    for (int i = 0; i < list.size(); i++)
    {
        scene sceneSel = get(list, i);
        if (sceneSel.name == scenecompare.name)
        {
            return i;
            break;
        }
    }
}

scene sceneLoader::get(list<scene> _list, int _i)
{
    list<scene>::iterator it = _list.begin();
    for (int i = 0; i < _i; i++)
    {
        ++it;
    }
    return *it;
}

bool sceneLoader::sceneExists(scene scenecompare)
{
    //check if the scene given already exists!
    bool yes = false;
    list<scene> list = sceneLoader::sceneList;
    for (int i = 0; i < list.size(); i++)
    {
        scene sceneObjectAT = get(list, i);
        if (scenecompare.name == sceneObjectAT.name)
        {
            //this is a good comparison
            yes = true;
        }
    }
    return yes;
}

bool sceneLoader::deleteScene(scene deleteScene)
{
    //delete the scene
    if (sceneExists(deleteScene))
    {
        list<scene>::iterator it = sceneList.begin();
        for (int i = 0; i < getScene(deleteScene); i++)
        {
            ++it;
        }
        sceneLoader::sceneList.erase(it);
        Console::WriteLine(Concatenate::JoinString("Sucesfully deleted the scene", deleteScene.name, " ").c_str());
        return true;
    }
    else
    {
        //unable to delete it as it doesnt exist
        Console::WriteWarning(Concatenate::JoinString("Unable to delete", deleteScene.name, "as it doesnt exist!", " ").c_str());
        return false;
    }
}