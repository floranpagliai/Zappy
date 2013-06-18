#include "Map.h"

Map::Map(int maxX, int maxZ) {
    this->maxX_ = maxX;
    this->maxZ_ = maxZ;
    this->position_.x = maxX * (BLOCK_SIZE * 2);;
    this->position_.y = 0.0f;
    this->position_.z = maxZ * (BLOCK_SIZE * 2);;
    this->initialize();
}

Map::~Map() {
}

void Map::initialize(void) {
    this->texture_ = gdl::Image::load("assets/ground.png");
}

void Map::update(gdl::GameClock const & gameClock, gdl::Input & input) {
}

void Map::draw(void) {
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
