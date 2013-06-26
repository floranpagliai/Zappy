#include "IRessourceManager.h"

t_Ressource ressources[6] = {
    {
        GROUND, gdl::Image::load("gui/assets/ground.png")
    },
    {
        TRUNK, gdl::Image::load("gui/assets/trunk.png")
    },
    {
        LEAF, gdl::Image::load("gui/assets/leaf.png")
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