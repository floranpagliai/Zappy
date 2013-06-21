/*
 * File:   Parseur.cpp
 * Author: floran
 *
 * Created on 20 juin 2013, 16:48
 */

#include <vector>

#include "Parseur.h"

Parseur::Parseur() {
    this->funcs["msz"] = &rfcFuncs::msz;
    this->funcs["bct"] = &rfcFuncs::bct;

    this->funcs["ppo"] = &rfcFuncs::ppo;
}

Parseur::~Parseur() {
}

void Parseur::parse(std::string str, MyGame* game) {
    std::istringstream input(str);
    std::string buffer;

    while (input) {
        buffer.clear();
        getline(input, buffer);
        if (buffer.size() > 0) {
            this->list.push_back(buffer);
            std::cout << "Receive : " << buffer << std::endl;
        }
    }
    this->interpret(game);
}

bool Parseur::interpret(MyGame* game) {
    if (this->list.size() == 0)
        return (true);
    for (std::list<std::string>::iterator it = list.begin(); it != list.end(); it++) {
        if (this->funcs[it->substr(0, 3)]) {
            std::cout << "Exec : " << *it << std::endl;
            this->funcs[it->substr(0, 3)](game, *it);
        }
    }
    list.clear();
    return (true);
}

namespace rfcFuncs {
    void msz(MyGame* game, std::string cmd) {
        game->generateMap(20, 20);
    }

    void bct(MyGame* game, std::string cmd) {
    }

    void ppo(MyGame* game, std::string cmd) {
        game->invocatePlayer(0, 0);
    }
}
