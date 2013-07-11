/*
 * File:   Ground.h
 * Author: floran
 *
 * Created on 18 juin 2013, 00:07
 */

#ifndef MAPELEMENT_H
#define	MAPELEMENT_H

#include "AObject.hpp"
#include "IRessourceManager.h"

class Ground : public AObject {
private:
    IRessourceManager *manager_;
    gdl::Image texture_;
        int maxX_;
    int maxZ_;

public:
    Ground(int, int, IRessourceManager *);
    virtual ~Ground();

    void initialize(void);
    void update(gdl::GameClock const &, gdl::Input &);
    void draw(void);
};

class Selector : public AObject {
private:
    IRessourceManager *manager_;
    gdl::Image texture_;
    int maxX_;
    int maxZ_;

public:
    Selector(int, int, int, int);
    virtual ~Selector();

    void initialize(void);
    void update(gdl::GameClock const &, gdl::Input &);
    void draw(void);
};

#endif	/* MAPELEMENT_H */

