/*
 * File:   Parseur.cpp
 * Author: floran
 *
 * Created on 20 juin 2013, 16:48
 */

#include "Parseur.h"

t_Funcs funcs[5] = {
    {
        (char*)"msz"
    },
    {
        (char*)"bct"
    },
    {
        (char*)"tna"
    },
    {
        (char*)"pnw"
    },
    {
        (char*)"ppo"
    }
};

Parseur::Parseur() {
}

Parseur::~Parseur() {
}

void Parseur::parse(char *cmd, MyGame* game) {
    for (int i = 0; i != 4; i++) {
        if (strncmp(cmd, funcs[i].cmd, 3) == 0) {
            std::cout << cmd << std::endl;
            game->generateMap(20, 15);
        }
    }
}

void Parseur::msz() {

}
