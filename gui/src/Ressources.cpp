#include "Ressources.h"

Ressources::Ressources(int x, int z, IRessourceManager* manager) : manager_(manager) {
    this->position_.x = x * (BLOCK_SIZE * 2);
    this->position_.y = 1.0f;
    this->position_.z = z * (BLOCK_SIZE * 2);
    this->type_ = RESSOURCES;
    this->initialize();
}

Ressources::~Ressources() {
}

void Ressources::initialize(void) {
    this->texture_ = this->manager_->getRessource(RESSOURCES);
}

void Ressources::update(gdl::GameClock const & gameClock, gdl::Input & input) {

}

void Ressources::draw(void) {
    texture_.bind();
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glPushMatrix();
    glTranslatef(this->position_.x, this->position_.y, this->position_.z);

    glBegin(GL_QUADS);
    float pos = 0.142f;
    for (int i = 0; i != 7; i++) {
        if (this->ressources_[i] > 0) {
            glTexCoord2f((i * pos), 0.0f);
            glVertex3f(-BLOCK_SIZE, -BLOCK_SIZE, -BLOCK_SIZE);
            glTexCoord2f((i * pos), 1.0f);
            glVertex3f(-BLOCK_SIZE, -BLOCK_SIZE, BLOCK_SIZE);
            glTexCoord2f((i + 1.0f) * pos, 1.0f);
            glVertex3f(BLOCK_SIZE, -BLOCK_SIZE, BLOCK_SIZE);
            glTexCoord2f((i + 1.0f) * pos, 0.0f);
            glVertex3f(BLOCK_SIZE, -BLOCK_SIZE, -BLOCK_SIZE);
        }
    }
    glEnd();
    glPopMatrix();
}

void Ressources::setRessources(int *ressources) {
    for (int i = 0; i != 7; i++)
        this->ressources_[i] = ressources[i];
}

int *Ressources::getRessources() {
    return this->ressources_;
}

void Ressources::dropRessource(eRessource type) {
    this->ressources_[type] += 1;
}

void Ressources::getRessource(eRessource type) {
    this->ressources_[type] -= 1;
}