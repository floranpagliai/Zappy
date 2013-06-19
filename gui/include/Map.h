/*
 * File:   Map.h
 * Author: floran
 *
 * Created on 19 juin 2013, 22:38
 */

#ifndef MAP_H
#define	MAP_H

#include "MapElement.h"
#include "Trantorien.h"

class Map {
public:
    Map(int, int, std::list<AObject*> *, IRessourceManager*);
    virtual ~Map();

private:
    IRessourceManager *manager_;
    int sizeX_;
    int sizeY_;
};

#endif	/* MAP_H */

