#include "IRessourceManager.h"

t_Ressource ressources[4] = {
    {
        GROUND, gdl::Image::load("gui/assets/ground2.png")

    },
    {
        FEUILLE, gdl::Image::load("gui/assets/feuille.png")
    },
    {
        TREE, gdl::Image::load("gui/assets/tree.png")
    },
    {
        TRANTORIEN, gdl::Image::load("gui/assets/boy.png")
    }
};

IRessourceManager::IRessourceManager() {
}

IRessourceManager::~IRessourceManager() {
}

gdl::Image IRessourceManager::getRessource(e_Ressource name) {
    return ressources[name].image;
}