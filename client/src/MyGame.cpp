#include "MyGame.h"

void MyGame::initialize() {
    window_.setTitle("Zappy");
    window_.setHeight(WINDOW_HEIGHT);
    window_.setWidth(WINDOW_WIDHT);
    window_.create();
    camera_.initialize();


    for (int i = 0; i != 10; i++) {
        for (int x = 0; x != 10; x++) {
            this->objects_.push_front(new Ground(i, x, &this->manager_));
        }
    }
    int x = 0, y = 0, z = -1;
    while (x <= 10) {
        this->objects_.push_back(new Tree(x, y++, z, 0, &this->manager_));
        this->objects_.push_back(new Tree(x, y++, z, 0, &this->manager_));
        while (y != 5) {
            this->objects_.push_back(new Tree(x - 1, y, z - 1, 1, &this->manager_));
            this->objects_.push_back(new Tree(x, y, z - 1, 1, &this->manager_));
            this->objects_.push_back(new Tree(x + 1, y, z - 1, 1, &this->manager_));

            this->objects_.push_back(new Tree(x - 1, y, z, 1, &this->manager_));
            this->objects_.push_back(new Tree(x, y, z, 1, &this->manager_));
            this->objects_.push_back(new Tree(x + 1, y, z, 1, &this->manager_));

            this->objects_.push_back(new Tree(x + 1, y, z + 1, 1, &this->manager_));
            this->objects_.push_back(new Tree(x, y, z + 1, 1, &this->manager_));
            this->objects_.push_back(new Tree(x - 1, y, z + 1, 1, &this->manager_));
            y++;
        }
        x += 4;
        y = 0;

    }
    this->objects_.push_back(new Trantorien(5, 5, &this->manager_));
    for (std::list<AObject*>::iterator it = this->objects_.begin(); it != this->objects_.end(); ++it)
        (*it)->initialize();
}

void MyGame::update(void) {
    this->network_.do_client();
    for (std::list<AObject*>::iterator it = this->objects_.begin(); it != this->objects_.end(); ++it) {
        (*it)->update(gameClock_, input_);
    }
    camera_.update(gameClock_, input_);
    if (input_.isKeyDown(gdl::Keys::Right) == true)
        camera_.setPosition(camera_.getPosition().x + 10.0f, camera_.getPosition().y, camera_.getPosition().z);
    if (input_.isKeyDown(gdl::Keys::Left) == true && camera_.getPosition().x - 10.0f >= 1)
        camera_.setPosition(camera_.getPosition().x - 10.0f, camera_.getPosition().y, camera_.getPosition().z);
    if (input_.isKeyDown(gdl::Keys::Down) == true)
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

void MyGame::initNetwork(int port, char *ip) {
    this->network_.initClient(port, ip);
}
