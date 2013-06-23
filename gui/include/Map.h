/*
 * File:   Map.h
 * Author: floran
 *
 * Created on 19 juin 2013, 22:38
 */

#ifndef MAP_H
#define	MAP_H

#include "MapElement.h"
#include "Player.h"

class Map {
protected:
    std::list<AObject*> *objects_;
    IRessourceManager *manager_;
    int sizeX_;
    int sizeZ_;

public:
    Map();
    Map(int, int, std::list<AObject*> *, IRessourceManager*);
    Map &operator=(const Map&);
    virtual ~Map();

    int getSizeX() const;
    int getSizeZ() const;

    void generateMap(int, int);
};

#endif	/* MAP_H */

