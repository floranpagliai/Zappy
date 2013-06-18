/*
 * File:   Ground.h
 * Author: floran
 *
 * Created on 18 juin 2013, 00:07
 */

#ifndef GROUND_H
#define	GROUND_H

#include "AObject.hpp"

#define BLOCK_SIZE 50

class Ground : public AObject {
private:
    gdl::Image texture_;
    IRessourceManager manager_;

public:
    Ground(int, int, IRessourceManager);
    virtual ~Ground();

    void initialize(void);
    void update(gdl::GameClock const &, gdl::Input &);
    void draw(void);
};

#endif	/* MAP_H */

