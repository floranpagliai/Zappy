#ifndef MYGAME_H
#define MYGAME_H

#include "AObject.hpp"
#include "Camera.h"
#include "IRessourceManager.h"
#include "Map.h"
#include "Network.h"

#define WINDOW_HEIGHT 700
#define WINDOW_WIDHT 1024

class MyGame : public gdl::Game {
private:
    std::list<AObject*> objects_;
    Camera camera_;
    IRessourceManager manager_;
    int mapSizeX_;
    int mapSizeZ_;

public:
    virtual void initialize(void);
    virtual void update(void);
    virtual void draw(void);
    virtual void unload(void);

    void connect(int, char *);
};

#endif
