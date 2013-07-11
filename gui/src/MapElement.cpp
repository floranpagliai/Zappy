#include "MapElement.h"

Ground::Ground(int maxX, int maxZ, IRessourceManager* manager) : manager_(manager) {
    this->position_.x = maxX * (BLOCK_SIZE * 2);
    this->position_.y = 0.0f;
    this->position_.z = maxZ * (BLOCK_SIZE * 2);
//    this->position_.x = 0.0f;
//    this->position_.y = 0.0f;
//    this->position_.z = 0.0f;
//    this->maxX_ = maxX * (BLOCK_SIZE * 2);
//    this->maxZ_ = maxZ * (BLOCK_SIZE * 2);
    this->type_ = GROUND;
    this->initialize();
}

Ground::~Ground() {
}

void Ground::initialize(void) {
    this->texture_ = manager_->getRessource(GROUND);
}

void Ground::update(gdl::GameClock const & gameClock, gdl::Input & input) {
}

void Ground::draw(void) {
    texture_.bind();
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(this->position_.x, this->position_.y, this->position_.z);

    glBegin(GL_QUADS);

    glTexCoord2f(0, 0);
    glVertex3f(-BLOCK_SIZE, -BLOCK_SIZE, -BLOCK_SIZE);
    glTexCoord2f(0, 1);
    glVertex3f(-BLOCK_SIZE, -BLOCK_SIZE, BLOCK_SIZE);
    glTexCoord2f(1, 1);
    glVertex3f(BLOCK_SIZE, -BLOCK_SIZE, BLOCK_SIZE);
    glTexCoord2f(1, 0);
    glVertex3f(BLOCK_SIZE, -BLOCK_SIZE, -BLOCK_SIZE);

    glEnd();
    glPopMatrix();
}

Selector::Selector(int x, int z, int maxX, int maxZ) {
    this->position_.x = x * (BLOCK_SIZE * 2);
    this->position_.y = 1.0f;
    this->position_.z = z * (BLOCK_SIZE * 2);
    this->type_ = SELECTOR;
    this->maxX_ = (maxX - 1) * (BLOCK_SIZE * 2);
    this->maxZ_ = (maxZ - 1) * (BLOCK_SIZE * 2);
    this->initialize();
}

Selector::~Selector() {
}

void Selector::initialize(void) {
    this->texture_ = manager_->getRessource(SELECTOR);
}

void Selector::update(gdl::GameClock const & gameClock, gdl::Input & input) {
    if (input.isKeyDown(gdl::Keys::Z) == true && this->position_.z > 0) {
        this->position_.z -= BLOCK_SIZE * 2;
    }
    if (input.isKeyDown(gdl::Keys::S) == true && this->position_.z < this->maxZ_) {
        this->position_.z += BLOCK_SIZE * 2;
    }
    if (input.isKeyDown(gdl::Keys::D) == true && this->position_.x < this->maxX_) {
        this->position_.x += BLOCK_SIZE * 2;
    }
    if (input.isKeyDown(gdl::Keys::Q) == true && this->position_.x > 0) {
        this->position_.x -= BLOCK_SIZE * 2;
    }
}

void Selector::draw(void) {
    texture_.bind();
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(this->position_.x, this->position_.y, this->position_.z);

    glBegin(GL_QUADS);

    glTexCoord2f(0, 0);
    glVertex3f(-BLOCK_SIZE, -BLOCK_SIZE, -BLOCK_SIZE);
    glTexCoord2f(0, 1);
    glVertex3f(-BLOCK_SIZE, -BLOCK_SIZE, BLOCK_SIZE);
    glTexCoord2f(1, 1);
    glVertex3f(BLOCK_SIZE, -BLOCK_SIZE, BLOCK_SIZE);
    glTexCoord2f(1, 0);
    glVertex3f(BLOCK_SIZE, -BLOCK_SIZE, -BLOCK_SIZE);

    glEnd();
    glPopMatrix();
}