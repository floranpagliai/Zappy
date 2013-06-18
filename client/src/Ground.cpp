#include "Ground.h"

Ground::Ground(int maxX, int maxZ, IRessourceManager* manager) : manager_(manager) {
    this->position_.x = maxX * (BLOCK_SIZE * 2);
    this->position_.y = 0.0f;
    this->position_.z = maxZ * (BLOCK_SIZE * 2);
    //this->manager_ = manager;
    this->initialize();
}

Ground::~Ground() {
}

void Ground::initialize(void) {
    //this->model_ = gdl::Model::load("client/assets/tree/tree.fbx");
    this->texture_ = manager_->getRessource(GROUND);
}

void Ground::update(gdl::GameClock const & gameClock, gdl::Input & input) {
    //this->model_.update(gameClock);
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

//    glMatrixMode(GL_MODELVIEW);
//    glPushMatrix();
//
//    glTranslatef(this->position_.x, this->position_.y, this->position_.z);
//    glRotatef(this->rotation_.y, 0.0f, 1.0f, 0.0f);
//
//    this->model_.draw();
//    glPopMatrix();
}
