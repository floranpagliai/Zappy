#ifndef PARSEUR_H
#define	PARSEUR_H

#include <string>

#include "MyGame.h"

namespace rfcFuncs {
    void msz(MyGame*, std::string);
    void bct(MyGame*, std::string);

    void ppo(MyGame*, std::string);
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

