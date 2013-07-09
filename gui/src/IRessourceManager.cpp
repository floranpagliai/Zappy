#include "IRessourceManager.h"

t_Ressource ressources[5] = {
    {
        GROUND, gdl::Image::load("gui/assets/ground.png")
    },
    {
        SELECTOR, gdl::Image::load("gui/assets/selector.png")
    },
    {
        TRANTORIEN, gdl::Image::load("gui/assets/trantorien.png")
    },
    {
        EGG, gdl::Image::load("gui/assets/egg.png")
    },
    {
        RESSOURCES, gdl::Image::load("gui/assets/stones.png")
    }
};

IRessourceManager::IRessourceManager() {
}

IRessourceManager::~IRessourceManager() {
}

gdl::Image IRessourceManager::getRessource(eType name) {
    return ressources[name].image;
}