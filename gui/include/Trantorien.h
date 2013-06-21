/*
 * File:   Trantorien.h
 * Author: floran
 *
 * Created on 19 juin 2013, 02:37
 */

#ifndef TRANTORIEN_H
#define	TRANTORIEN_H

#include "AObject.hpp"
#include "IRessourceManager.h"

class Trantorien : public AObject {
private:
    gdl::Image texture_;
    gdl::Model model_;
    IRessourceManager *manager_;
    eDir dir_;
    int lvl_;

public:
    Trantorien(int, int, int, eDir, int, IRessourceManager *);
    virtual ~Trantorien(void);

    void initialize(void);
    void update(gdl::GameClock const &, gdl::Input &);
    void draw(void);

    void setLvl(int);

    int getLvl(void) const;
};

#endif	/* TRANTORIEN_H */

