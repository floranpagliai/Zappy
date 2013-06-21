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
    this->funcs["tna"] = &rfcFuncs::tna;
    this->funcs["pnw"] = &rfcFuncs::pnw;
    this->funcs["ppo"] = &rfcFuncs::ppo;
    this->funcs["plv"] = &rfcFuncs::plv;
    this->funcs["pin"] = &rfcFuncs::pin;
    this->funcs["pex"] = &rfcFuncs::pex;
    this->funcs["pbc"] = &rfcFuncs::pbc;
    this->funcs["pic"] = &rfcFuncs::pic;
    this->funcs["pie"] = &rfcFuncs::pie;
    this->funcs["pfk"] = &rfcFuncs::pfk;
    this->funcs["pdr"] = &rfcFuncs::pdr;
    this->funcs["pgt"] = &rfcFuncs::pgt;
    this->funcs["pdi"] = &rfcFuncs::pdi;
    this->funcs["enw"] = &rfcFuncs::enw;
    this->funcs["eht"] = &rfcFuncs::eht;
    this->funcs["ebo"] = &rfcFuncs::ebo;
    this->funcs["edi"] = &rfcFuncs::edi;
    this->funcs["sgt"] = &rfcFuncs::sgt;
    this->funcs["seg"] = &rfcFuncs::seg;
    this->funcs["smg"] = &rfcFuncs::smg;
    this->funcs["suc"] = &rfcFuncs::suc;
    this->funcs["sbp"] = &rfcFuncs::sbp;
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
        int X = cmd.find(' ', 0);
        int Z = cmd.find(' ', X + 1);
        game->generateMap(atoi(cmd.substr(X + 1, Z - (X + 1)).c_str()),
                atoi(cmd.substr(Z + 1, cmd.size()-(Z + 1)).c_str()));
    }

    void bct(MyGame* game, std::string cmd) {
    }

    void tna(MyGame* game, std::string cmd) {
    }

    void pnw(MyGame* game, std::string cmd) {
        int id = cmd.find(' ', 0);
        int X = cmd.find(' ', id + 1);
        int Z = cmd.find(' ', X + 1);
        int O = cmd.find(' ', Z + 1);
        int lvl = cmd.find(' ', O + 1);
        game->invocatePlayer(atoi(cmd.substr(id + 1, X - (id + 1)).c_str()),
                atoi(cmd.substr(X + 1, Z - (X + 1)).c_str()),
                atoi(cmd.substr(Z + 1, O - (Z + 1)).c_str()),
                (eDir) atoi(cmd.substr(O + 1, lvl - (O + 1)).c_str()),
                atoi(cmd.substr(lvl + 1, cmd.size()-(lvl + 1)).c_str()));
    }

    void ppo(MyGame* game, std::string cmd) {
        int id = cmd.find(' ', 0);
        int X = cmd.find(' ', id + 1);
        int Z = cmd.find(' ', X + 1);
        int O = cmd.find(' ', Z + 1);
        game->movePlayer(atoi(cmd.substr(id + 1, X - (id + 1)).c_str()),
                atoi(cmd.substr(X + 1, Z - (X + 1)).c_str()),
                atoi(cmd.substr(Z + 1, O - (Z + 1)).c_str()),
                (eDir) atoi(cmd.substr(O + 1, cmd.size()-(O + 1)).c_str()));
    }

    void plv(MyGame* game, std::string cmd) {
        int id = cmd.find(' ', 0);
        int lvl = cmd.find(' ', id + 1);
        game->setPlayerLvl(atoi(cmd.substr(id + 1, id - (id + 1)).c_str()),
                atoi(cmd.substr(lvl + 1, cmd.size()-(lvl + 1)).c_str()));
    }

    void pin(MyGame* game, std::string cmd) {

    }

    void pex(MyGame* game, std::string cmd) {
        int id = cmd.find(' ', 0);
        game->expulsePlayer(atoi(cmd.substr(id + 1, id - (id + 1)).c_str()));
    }

    void pbc(MyGame* game, std::string cmd) {
    }

    void pic(MyGame* game, std::string cmd) {
    }

    void pie(MyGame* game, std::string cmd) {
    }

    void pfk(MyGame* game, std::string cmd) {
    }

    void pdr(MyGame* game, std::string cmd) {
    }

    void pgt(MyGame* game, std::string cmd) {
    }

    void pdi(MyGame* game, std::string cmd) {
    }

    void enw(MyGame* game, std::string cmd) {
    }

    void eht(MyGame* game, std::string cmd) {
    }

    void ebo(MyGame* game, std::string cmd) {
    }

    void edi(MyGame* game, std::string cmd) {
    }

    void sgt(MyGame* game, std::string cmd) {
    }

    void seg(MyGame* game, std::string cmd) {
    }

    void smg(MyGame* game, std::string cmd) {
    }

    void suc(MyGame* game, std::string cmd) {
    }

    void sbp(MyGame* game, std::string cmd) {
    }
}
