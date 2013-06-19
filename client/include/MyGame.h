#ifndef MYGAME_H
#define MYGAME_H

#include "AObject.hpp"
#include "Network.h"
#include "Camera.h"
#include "Ground.h"
#include "Trantorien.h"

#define WINDOW_HEIGHT 700
#define WINDOW_WIDHT 1024

class MyGame : public gdl::Game {
private:
    std::list<AObject*> objects_;
    Camera camera_;
    Network network_;
    IRessourceManager manager_;

public:
    virtual void initialize(void);
    virtual void update(void);
    virtual void draw(void);
    virtual void unload(void);

    void initNetwork(int, char *);
};

#endif
