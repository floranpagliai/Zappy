#include "Egg.h"

Egg::Egg(int x, int z, int id, IRessourceManager* manager) : manager_(manager) {
    this->position_.x = x * (BLOCK_SIZE * 2);
    this->position_.y = 1.0f;
    this->position_.z = z * (BLOCK_SIZE * 2);
    this->type_ = EGG;
    this->id_ = id;
    this->initialize();
}

Egg::~Egg() {
}

void Egg::initialize(void) {
    this->texture_ = this->manager_->getRessource(EGG);
}

void Egg::update(gdl::GameClock const & gameClock, gdl::Input & input) {
}

void Egg::draw(void) {
    texture_.bind();
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
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
