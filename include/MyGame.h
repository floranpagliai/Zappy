#ifndef MYGAME_H
#define MYGAME_H

#include "AObject.hpp"
#include "Camera.h"
#include "Ground.h"

#define WINDOW_HEIGHT 700
#define WINDOW_WIDHT 1024

class MyGame : public gdl::Game {
private:
    std::list<AObject*> objects_;
    Camera camera_;

public:
    virtual void initialize();
    virtual void update(void);
    virtual void draw(void);
    virtual void unload(void);
};

#endif
