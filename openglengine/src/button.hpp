//this is the button class
#include "gameObject.hpp"

class button : public gameObject{
    public:
        button(string name, int posx, int posy, int sizex, int sizey);
        button(string name, int posx, int posy);
        button(string name);
        void drawObject(RenderWindow& w) override;
        void startObject(RenderWindow& w) override;
    private:
        int xpos;
        int ypos;
        int xs;
        int ys;
};