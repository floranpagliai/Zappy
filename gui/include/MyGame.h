#ifndef MYGAME_H
#define MYGAME_H

#include "AObject.hpp"
#include "Camera.h"
#include "IRessourceManager.h"
#include "Map.h"
#include "Ressources.h"

#define WINDOW_HEIGHT 700
#define WINDOW_WIDHT 1024

class MyGame : public gdl::Game {
private:
    std::list<AObject*> objects_;
    Camera camera_;
    IRessourceManager manager_;

public:
    Map map_;

public:
    virtual void initialize(void);
    virtual void update(void);
    virtual void draw(void);
    virtual void unload(void);

    void generateMap(int, int);

    void invocatePlayer(int, int, int, eDir, int);
    void movePlayer(int, int, int, eDir);
    void setPlayerLvl(int, int);
    void expulsePlayer(int);

    void setRessources(int, int, int*);
    void dropRessource(int, eRessource);
    void getRessource(int, eRessource);
};

#endif
