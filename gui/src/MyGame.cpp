#include "MyGame.h"

void MyGame::initialize() {
    window_.setTitle("Zappy");
    window_.setHeight(WINDOW_HEIGHT);
    window_.setWidth(WINDOW_WIDHT);
    window_.create();
    camera_.initialize();

    for (std::list<AObject*>::iterator it = this->objects_.begin(); it != this->objects_.end(); ++it)
        (*it)->initialize();
}

void MyGame::update(void) {
    for (std::list<AObject*>::iterator it = this->objects_.begin(); it != this->objects_.end(); ++it) {
        (*it)->update(gameClock_, input_);
    }
    sleep(0.9);
    camera_.update(gameClock_, input_);
    if (input_.isKeyDown(gdl::Keys::Right) == true && camera_.getPosition().x - 10.0f <= (this->map_.getSizeZ() * BLOCK_SIZE * 2 - BLOCK_SIZE * 2))
        camera_.setPosition(camera_.getPosition().x + 10.0f, camera_.getPosition().y, camera_.getPosition().z);
    if (input_.isKeyDown(gdl::Keys::Left) == true && camera_.getPosition().x - 10.0f >= 1)
        camera_.setPosition(camera_.getPosition().x - 10.0f, camera_.getPosition().y, camera_.getPosition().z);
    if (input_.isKeyDown(gdl::Keys::Down) == true && camera_.getPosition().z - 10.0f <= (this->map_.getSizeZ() * BLOCK_SIZE * 2))
        camera_.setPosition(camera_.getPosition().x, camera_.getPosition().y, camera_.getPosition().z + 10.0f);
    if (input_.isKeyDown(gdl::Keys::Up) == true && camera_.getPosition().z - 10.0f >= 1)
        camera_.setPosition(camera_.getPosition().x, camera_.getPosition().y, camera_.getPosition().z - 10.0f);
    if (input_.isKeyDown(gdl::Keys::F1) == true)
        camera_.setPosition(camera_.getPosition().x, camera_.getPosition().y + 10.0f, camera_.getPosition().z);
    if (input_.isKeyDown(gdl::Keys::F2) == true && camera_.getPosition().y - 10.0f >= 0)
        camera_.setPosition(camera_.getPosition().x, camera_.getPosition().y - 10.0f, camera_.getPosition().z);
    if (input_.isKeyDown(gdl::Keys::F3) == true) {
        std::cout << "==========================" << std::endl;
        std::cout << "X: " << camera_.getPosition().x << std::endl;
        std::cout << "Y: " << camera_.getPosition().y << std::endl;
        std::cout << "Z: " << camera_.getPosition().z << std::endl;
        std::cout << "==========================" << std::endl;
    }
    if (input_.isKeyDown(gdl::Keys::Escape) == true)
        exit(0);
}

void MyGame::draw(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.f);
    for (std::list<AObject*>::iterator it = this->objects_.begin(); it != this->objects_.end(); ++it)
        (*it)->draw();
    this->window_.display();
}

void MyGame::unload(void) {
    for (std::list<AObject *>::iterator it = this->objects_.begin(); it != this->objects_.end(); it++)
        delete (*it);
    this->objects_.clear();
}

void MyGame::generateMap(int x, int z) {
    this->map_ = Map(x, z, &this->objects_, &this->manager_);
}

void MyGame::invocatePlayer(int id, int x, int z, eDir dir, int lvl) {
    this->objects_.push_back(new Player(id, x, z, dir, lvl, &this->manager_));
}

void MyGame::movePlayer(int id, int x, int z, eDir dir) {
    (void) dir;
    for (std::list<AObject*>::iterator it = this->objects_.begin(); it != this->objects_.end(); ++it) {
        if ((*it)->getType() == TRANTORIEN && (*it)->getId() == id) {
            (*it)->setNextPosition(x * (BLOCK_SIZE * 2), (*it)->getPosition().y, z * (BLOCK_SIZE * 2));
            break;
        }
    }
}

void MyGame::setPlayerLvl(int id, int lvl) {
    for (std::list<AObject*>::iterator it = this->objects_.begin(); it != this->objects_.end(); ++it) {
        if ((*it)->getType() == TRANTORIEN && (*it)->getId() == id) {
            (*it)->setLvl(lvl);
            break;
        }
    }
}

void MyGame::expulsePlayer(int id) {
    for (std::list<AObject*>::iterator it = this->objects_.begin(); it != this->objects_.end(); ++it) {
        if ((*it)->getType() == TRANTORIEN && (*it)->getId() == id) {
            delete (*it);
            this->objects_.erase(it);
            break;
        }
    }
}

void MyGame::putRessources(int x, int z, int *ressources) {
    for (std::list<AObject*>::iterator it = this->objects_.begin(); it != this->objects_.end(); ++it) {
        if ((*it)->getType() == RESSOURCES && (*it)->getPosition().x == x * (BLOCK_SIZE * 2) && (*it)->getPosition().z == z * (BLOCK_SIZE * 2)) {
            (*it)->setRessources(ressources);
            break;
        }
    }

}

void MyGame::putRessource(int id, eRessource type) {
    int x;
    int z;
    for (std::list<AObject*>::iterator it = this->objects_.begin(); it != this->objects_.end(); ++it) {
        if ((*it)->getType() == TRANTORIEN && (*it)->getId() == id) {
            x = (*it)->getNextPosition().x;
            z = (*it)->getNextPosition().z;

        }
    }
    for (std::list<AObject*>::iterator it = this->objects_.begin(); it != this->objects_.end(); ++it) {
        if ((*it)->getType() == RESSOURCES && (*it)->getPosition().x == x && (*it)->getPosition().z == z) {
            (*it)->dropRessource(type);
        }
    }
}
