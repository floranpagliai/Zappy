/*
 * File:   Trantorien.h
 * Author: floran
 *
 * Created on 19 juin 2013, 02:37
 */

#ifndef TRANTORIEN_H
#define	TRANTORIEN_H

#include "AObject.hpp"

class Trantorien : public AObject {
private:
    gdl::Image texture_;
    gdl::Model model_;
    IRessourceManager *manager_;
public:
    Trantorien(int, int, IRessourceManager *);
    virtual ~Trantorien(void);

    void initialize(void);
    void update(gdl::GameClock const &, gdl::Input &);
    void draw(void);
};

#endif	/* TRANTORIEN_H */

