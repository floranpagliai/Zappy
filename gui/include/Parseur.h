#ifndef PARSEUR_H
#define	PARSEUR_H

#include <string>
#include <vector>

#include "AObject.hpp"
#include "MyGame.h"

namespace rfcFuncs {
    void msz(MyGame*, std::string);
    void bct(MyGame*, std::string);
    void tna(MyGame*, std::string);
    void pnw(MyGame*, std::string);
    void ppo(MyGame*, std::string);
    void plv(MyGame*, std::string);
    void pin(MyGame*, std::string);
    void pex(MyGame*, std::string);
    void pbc(MyGame*, std::string);
    void pic(MyGame*, std::string);
    void pie(MyGame*, std::string);
    void pfk(MyGame*, std::string);
    void pdr(MyGame*, std::string);
    void pgt(MyGame*, std::string);
    void pdi(MyGame*, std::string);
    void enw(MyGame*, std::string);
    void eht(MyGame*, std::string);
    void ebo(MyGame*, std::string);
    void edi(MyGame*, std::string);
    void sgt(MyGame*, std::string);
    void seg(MyGame*, std::string);
    void smg(MyGame*, std::string);
    void suc(MyGame*, std::string);
    void sbp(MyGame*, std::string);
}

typedef void (*func)(MyGame*, std::string);

class Parseur {
private:
    std::list<std::string> list;
    std::map<std::string, func> funcs;

public:
    Parseur();
    virtual ~Parseur();

    void parse(std::string, MyGame*);
    bool interpret(MyGame*);
};

#endif	/* PARSEUR_H */

