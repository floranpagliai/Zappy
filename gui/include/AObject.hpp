#ifndef AOBJECT_HPP
#define	AOBJECT_HPP

#include <GL/gl.h>
#include <GL/glu.h>

#include "AnimStates.hpp"
#include "Assert.hpp"
#include "Clock.hpp"
#include "Color.hpp"
#include "Game.hpp"
#include "GameClock.hpp"
#include "GlError.hpp"
#include "IClock.hpp"
#include "Image.hpp"
#include "Input.hpp"
#include "Model.hpp"
#include "ModelException.hpp"
#include "Resource.hpp"
#include "Text.hpp"
#include "Window.hpp"

#include <cstdlib>
#include <list>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <pthread.h>
#include <stdio.h>

#include "Vector3f.hpp"

#define BLOCK_SIZE 50
#define CHARACTER_SIZE 50

enum eType {
    GROUND = 0,
    SELECTOR,
    TRANTORIEN,
    EGG,
    RESSOURCES
};

enum eRessource {
    FOOD = 0,
    LINEMATE,
    DERAUMATRE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
};

enum eDir {
    NORD = 1,
    EST,
    SUD,
    OUEST
};

class AObject {
protected:
    Vector3f position_;
    Vector3f nextPosition_;
    Vector3f rotation_;
    eType type_;
    int id_;

public:

    AObject(void) : position_(0.0f, 0.0f, 0.0f), rotation_(0.0f, 0.0f, 0.0f) {
    }

    virtual ~AObject(void) {
    }

    virtual void initialize(void) = 0;
    virtual void update(gdl::GameClock const &, gdl::Input &) = 0;
    virtual void draw(void) = 0;

    Vector3f getPosition(void) const {
        return (this->position_);
    }

    Vector3f getNextPosition(void) const {
        return (this->nextPosition_);
    }

    Vector3f getRotation(void) const {
        return (this->rotation_);
    }

    void setPosition(float newx, float newy, float newz) {
        this->position_.x = newx;
        this->position_.y = newy;
        this->position_.z = newz;
    }

    void setNextPosition(float newx, float newy, float newz) {
        this->nextPosition_.x = newx;
        this->nextPosition_.y = newy;
        this->nextPosition_.z = newz;
    }

    int getId(void) {
        return (this->id_);
    }

    eType getType() {
        return (this->type_);
    }

    virtual void setLvl(int) {
    };

    virtual void setDir(eDir) {
    };

    virtual void setRessources(int*) {
    };

    virtual int *getRessources() {
        return 0;
    };

    virtual void dropRessource(eRessource) {
    };

    virtual void getRessource(eRessource) {
    };
};

#endif	/* AOBJECT_HPP */

