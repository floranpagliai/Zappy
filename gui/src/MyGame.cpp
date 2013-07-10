#include "MyGame.h"

void MyGame::initialize() {
    window_.setTitle("Zappy");
    window_.setHeight(WINDOW_HEIGHT);
    window_.setWidth(WINDOW_WIDHT);
    window_.create();
    camera_.initialize();
    this->loading_ = gdl::Image::load("gui/assets/loading.jpg");
    this->score_ = gdl::Image::load("gui/assets/score.png");
    for (std::list<AObject*>::iterator it = this->objects_.begin(); it != this->objects_.end(); ++it)
        (*it)->initialize();
}

void MyGame::update(void) {
    glViewport(0, 0, window_.getWidth(), window_.getHeight());
    while (gameClock_.getTotalGameTime() < 3.0f)
        loadingScreen(window_.getHeight(), window_.getWidth());
    for (std::list<AObject*>::iterator it = this->objects_.begin(); it != this->objects_.end(); ++it) {
        (*it)->update(gameClock_, input_);
    }
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
    this->drawScore(this->window_.getWidth());
    this->window_.display();
}

void MyGame::unload(void) {
    for (std::list<AObject *>::iterator it = this->objects_.begin(); it != this->objects_.end(); it++)
        delete (*it);
    this->objects_.clear();
}

void MyGame::loadingScreen(int height, int widht) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.f);

    loading_.bind();
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();

    glViewport(0, 0, widht, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, widht, 0, height);

    glBegin(GL_QUADS);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.0f, height, 0.0f);

    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(widht, 0.0f, 0.0f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(widht, height, 0.0f);

    glEnd();
    glPopMatrix();
    this->window_.display();
}

void MyGame::drawScore(int widht) {
    this->camera_.setPosition(this->camera_.getPosition().x, this->camera_.getPosition().y - 1, this->camera_.getPosition().z);
    score_.bind();
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();

    glViewport(0, 0, WINDOW_WIDHT, 150);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100, 0, 100);

    glBegin(GL_QUADS);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.0f, 100, 0.0f);

    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(100, 0.0f, 0.0f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(100, 100, 0.0f);

    glEnd();
    glPopMatrix();

    Vector3f pos;
    int *ressources;
    for (std::list<AObject*>::iterator it = this->objects_.begin(); it != this->objects_.end(); ++it) {
        if ((*it)->getType() == SELECTOR) {
            pos = (*it)->getPosition();
            break;
        }
    }
    for (std::list<AObject*>::iterator it = this->objects_.begin(); it != this->objects_.end(); ++it) {
        if ((*it)->getType() == RESSOURCES && (*it)->getPosition().x == pos.x && (*it)->getPosition().z == pos.z) {
            ressources = (*it)->getRessources();
            break;
        }
    }
    for (int i = 0; i != 7; i++) {
        text_.setText(intToStr(ressources[i]));
        text_.setSize(30);
        text_.setPosition((50 + (widht/15) * i), 615);
        text_.draw();
    }
    this->camera_.setPosition(this->camera_.getPosition().x, this->camera_.getPosition().y + 1, this->camera_.getPosition().z);

}

void MyGame::generateMap(int x, int z) {
    this->map_ = Map(x, z, &this->objects_, &this->manager_);
}

void MyGame::invocatePlayer(int id, int x, int z, eDir dir, int lvl) {
    this->objects_.push_back(new Player(id, x, z, dir, lvl, &this->manager_));
}

void MyGame::movePlayer(int id, int x, int z, eDir dir) {
    for (std::list<AObject*>::iterator it = this->objects_.begin(); it != this->objects_.end(); ++it) {
        if ((*it)->getType() == TRANTORIEN && (*it)->getId() == id) {
            (*it)->setNextPosition(x * (BLOCK_SIZE * 2), (*it)->getPosition().y, z * (BLOCK_SIZE * 2));
            (*it)->setDir(dir);
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

void MyGame::setRessources(int x, int z, int *ressources) {
    for (std::list<AObject*>::iterator it = this->objects_.begin(); it != this->objects_.end(); ++it) {
        if ((*it)->getType() == RESSOURCES && (*it)->getPosition().x == x * (BLOCK_SIZE * 2) && (*it)->getPosition().z == z * (BLOCK_SIZE * 2)) {
            (*it)->setRessources(ressources);
            break;
        }
    }

}

void MyGame::dropRessource(int id, eRessource type) {
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

void MyGame::getRessource(int id, eRessource type) {
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
            (*it)->getRessource(type);
        }
    }
}

void MyGame::dropEgg(int id, int idPlayer, int x, int z) {
    (void) idPlayer;
    this->objects_.push_back(new Egg(x, z, id, &this->manager_));
}

std::string intToStr(int nb) {
    std::ostringstream os;

    os << nb;
    return os.str();
}
