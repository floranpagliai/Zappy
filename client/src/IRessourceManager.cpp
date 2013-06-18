#include "IRessourceManager.h"

t_Ressource ressources[1] = {
    {
        GROUND, "client/assets/ground.png", gdl::Image::load("client/assets/ground.png")
    }
};

IRessourceManager::IRessourceManager() {
}

IRessourceManager::~IRessourceManager() {
}

//void IRessourceManager::initialize(void) {
//    for (int i = 0; ressources[i].name; i++) {
//        ressources[i].image = gdl::Image::load(ressources[i].path);
//    }
//}


gdl::Image IRessourceManager::getRessource(e_Ressource name) {
    return ressources[name].image;
}