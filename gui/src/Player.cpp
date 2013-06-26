#include "Player.h"

t_Dir tdir[4] = {
    {
        NORD, 1, 0, 2
    },
    {
        EST, 4, 3, 5
    },
    {
        SUD, 7, 6, 8
    },
    {
        OUEST, 10, 9, 11
    }
};

Player::Player(int id, int x, int z, eDir dir, int lvl, IRessourceManager* manager) : manager_(manager) {
    this->position_.x = x * (BLOCK_SIZE * 2);
    this->position_.y = 2.0f;
    this->position_.z = z * (BLOCK_SIZE * 2);
    this->nextPosition_.x = this->position_.x;
    this->nextPosition_.y = this->position_.y;
    this->nextPosition_.z = this->position_.z;
    this->type_ = TRANTORIEN;
    this->id_ = id;
    this->dir_ = dir;
    this->lvl_ = lvl;
    this->isMoving_ = false;
    this->initialize();
}

Player::~Player() {
}

void Player::initialize(void) {
    this->texture_ = this->manager_->getRessource(TRANTORIEN);
}

void Player::update(gdl::GameClock const & gameClock, gdl::Input & input) {
    if (this->position_.x != this->nextPosition_.x || this->position_.z != this->nextPosition_.z) {
        this->isMoving_ = true;
        if (this->position_.x != this->nextPosition_.x)
            this->position_.x += 5.0f;
        else if (this->position_.z != this->nextPosition_.z)
            this->position_.z += 5.0f;
    } else
        this->isMoving_ = false;
    if (this->isMoving_ == false)
        this->posAnim_ = tdir[this->dir_ - 1].idle;
    else
        this->posAnim_++;
    if (this->posAnim_ > tdir[this->dir_ - 1].max)
        this->posAnim_ = tdir[this->dir_ - 1].min;
}

void Player::draw(void) {
    texture_.bind();
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glPushMatrix();
    glTranslatef(this->position_.x, this->position_.y, this->position_.z);

    glBegin(GL_QUADS);
    float pos = 0.084f;
    glTexCoord2f((this->posAnim_ * pos), 0.0f);
    glVertex3f(-BLOCK_SIZE, -BLOCK_SIZE, -70);
    glTexCoord2f((this->posAnim_ * pos), 1.0f);
    glVertex3f(-BLOCK_SIZE, -BLOCK_SIZE, BLOCK_SIZE);
    glTexCoord2f((this->posAnim_ + 1.0f) * pos, 1.0f);
    glVertex3f(BLOCK_SIZE, -BLOCK_SIZE, BLOCK_SIZE);
    glTexCoord2f((this->posAnim_ + 1.0f) * pos, 0.0f);
    glVertex3f(BLOCK_SIZE, -BLOCK_SIZE, -70);

    glEnd();
    glPopMatrix();
}

void Player::setLvl(int lvl) {
    if (lvl <= 8)
        this->lvl_ = lvl;
}

void Player::setDir(eDir dir) {
    this->dir_ = dir;
}

int Player::getLvl() const {
    return (this->lvl_);
}