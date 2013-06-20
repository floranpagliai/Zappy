/*
 * File:   Parseur.h
 * Author: floran
 *
 * Created on 20 juin 2013, 16:48
 */

#ifndef PARSEUR_H
#define	PARSEUR_H

#include <string.h>

#include "MyGame.h"

struct t_Funcs {
    char *cmd;
};

class Parseur {
private:

public:
    Parseur();
    virtual ~Parseur();

    void parse(char*, MyGame*);

    void msz();
};

#endif	/* PARSEUR_H */

