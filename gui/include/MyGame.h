#ifndef MYGAME_H
#define MYGAME_H

#include <ctime>
#include "AObject.hpp"
#include "Camera.h"
#include "IRessourceManager.h"
#include "Map.h"
#include "Ressources.h"
#include "Egg.h"

#define WINDOW_HEIGHT 700
#define WINDOW_WIDHT 1024

class MyGame : public gdl::Game {
private:
    std::list<AObject*> objects_;
    Camera camera_;
    IRessourceManager manager_;
    gdl::Image loading_;
    gdl::Image score_;
    gdl::Text text_;

public:
    Map map_;
    bool isActive_;
    bool gameOver_;

public:
    virtual void initialize(void);
    virtual void update(void);
    virtual void draw(void);
    virtual void unload(void);

    void loadingScreen(int, int);
    void drawScore(int, int);

    void generateMap(int, int);

    void invocatePlayer(int, int, int, eDir, int);
    void movePlayer(int, int, int, eDir);
    void setPlayerLvl(int, int);
    void expulsePlayer(int);

    void setRessources(int, int, int*);
    void dropRessource(int, eRessource);
    void getRessource(int, eRessource);

    void dropEgg(int, int, int, int);
};

std::string intToStr(int nb);
void pause(float);
#endif
