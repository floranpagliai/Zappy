#include "IRessourceManager.h"

t_Ressource ressources[4] = {
    {
        GROUND, gdl::Image::load("client/assets/ground2.png")

    },
    {
        FEUILLE, gdl::Image::load("client/assets/feuille.png")
    },
    {
        TREE, gdl::Image::load("client/assets/tree.png")
    },
    {
        TRANTORIEN, gdl::Image::load("client/assets/boy.png")
    }
};

IRessourceManager::IRessourceManager() {
}

IRessourceManager::~IRessourceManager() {
}

gdl::Image IRessourceManager::getRessource(e_Ressource name) {
    return ressources[name].image;
}