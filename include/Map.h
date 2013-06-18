/*
 * File:   Map.h
 * Author: floran
 *
 * Created on 18 juin 2013, 00:07
 */

#ifndef MAP_H
#define	MAP_H

#include "AObject.hpp"

#define BLOCK_SIZE 50

class Map : public AObject {
private:
    int maxX_;
    int maxZ_;
    gdl::Image texture_;
public:
    Map(int, int);
    virtual ~Map();

    void initialize(void);
    void update(gdl::GameClock const &, gdl::Input &);
    void draw(void);
};

#endif	/* MAP_H */

