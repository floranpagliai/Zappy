#include "Ground.h"

Ground::Ground(int maxX, int maxZ, IRessourceManager manager) {
    this->position_.x = maxX * (BLOCK_SIZE * 2);
    this->position_.y = 0.0f;
    this->position_.z = maxZ * (BLOCK_SIZE * 2);
    this->manager_ = manager;
    this->initialize();
}

Ground::~Ground() {
}

void Ground::initialize(void) {
    this->texture_ = manager_.getRessource(GROUND);
    //this->texture_ = gdl::Image::load("client/assets/ground.png");
}

void Ground::update(gdl::GameClock const & gameClock, gdl::Input & input) {
}

void Ground::draw(void) {
    texture_.bind();
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(this->position_.x, this->position_.y, this->position_.z);

    glBegin(GL_QUADS);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-BLOCK_SIZE, -BLOCK_SIZE, -BLOCK_SIZE);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-BLOCK_SIZE, -BLOCK_SIZE, BLOCK_SIZE);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(BLOCK_SIZE, -BLOCK_SIZE, BLOCK_SIZE);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(BLOCK_SIZE, -BLOCK_SIZE, -BLOCK_SIZE);

    glEnd();
    glPopMatrix();
}
