/*
 * File:   Trantorien.cpp
 * Author: floran
 *
 * Created on 19 juin 2013, 02:37
 */

#include "Trantorien.h"

Trantorien::Trantorien(int x, int z, IRessourceManager* manager) : manager_(manager) {
    this->position_.x = x * (BLOCK_SIZE * 2);
    this->position_.y = 50.0f;
    this->position_.z = z * (BLOCK_SIZE * 2);
    this->type_ = TRANTORIEN;
    this->initialize();
}

Trantorien::~Trantorien() {
}

void Trantorien::initialize(void) {
    this->texture_ = this->manager_->getRessource(TRANTORIEN);
}

void Trantorien::update(gdl::GameClock const & gameClock, gdl::Input & input) {
}

void Trantorien::draw(void) {
    texture_.bind();
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glPushMatrix();
    glTranslatef(this->position_.x, this->position_.y, this->position_.z);

    glBegin(GL_QUADS);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-CHARACTER_SIZE, -CHARACTER_SIZE, -CHARACTER_SIZE);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-CHARACTER_SIZE, -CHARACTER_SIZE, CHARACTER_SIZE);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(CHARACTER_SIZE, -CHARACTER_SIZE, CHARACTER_SIZE);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(CHARACTER_SIZE, -CHARACTER_SIZE, -CHARACTER_SIZE);

    glEnd();
    glPopMatrix();
}