/*
 * File:   Ground.h
 * Author: floran
 *
 * Created on 18 juin 2013, 00:07
 */

#ifndef MAPELEMENT_H
#define	MAPELEMENT_H

#include "AObject.hpp"

class Ground : public AObject {
private:
    IRessourceManager *manager_;
    gdl::Image texture_;

public:
    Ground(int, int, IRessourceManager *);
    virtual ~Ground();

    void initialize(void);
    void update(gdl::GameClock const &, gdl::Input &);
    void draw(void);
};

class Tree : public AObject {
private:
    IRessourceManager *manager_;
    gdl::Image texture_;
    int type_;

public:
    Tree(int, int, int, int, IRessourceManager *);
    virtual ~Tree();

    void initialize(void);
    void update(gdl::GameClock const &, gdl::Input &);
    void draw(void);
};

#endif	/* MAPELEMENT_H */

