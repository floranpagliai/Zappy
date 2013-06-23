#include "Player.h"

Player::Player(int id, int x, int z, eDir dir, int lvl, IRessourceManager* manager) : manager_(manager) {
    this->position_.x = x * (BLOCK_SIZE * 2);
    this->position_.y = 1.0f;
    this->position_.z = z * (BLOCK_SIZE * 2);
    this->nextPosition_.x = this->position_.x;
    this->nextPosition_.y = this->position_.y;
    this->nextPosition_.z = this->position_.z;
    this->type_ = TRANTORIEN;
    this->id_ = id;
    this->dir_ = dir;
    this->lvl_ = lvl;
    this->initialize();
}

Player::~Player() {
}

void Player::initialize(void) {
    this->texture_ = this->manager_->getRessource(TRANTORIEN);
}

void Player::update(gdl::GameClock const & gameClock, gdl::Input & input) {
    if (this->position_.x != this->nextPosition_.x)
        this->position_.x += 10.0f;
    else if (this->position_.z != this->nextPosition_.z)
        this->position_.z += 10.0f;
}

void Player::draw(void) {
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

void Player::setLvl(int lvl) {
    if (lvl <= 8)
        this->lvl_ = lvl;
}

int Player::getLvl() const {
    return (this->lvl_);
}