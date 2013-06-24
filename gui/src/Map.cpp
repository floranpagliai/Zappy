#include "Map.h"

Map::Map() {
}

Map::Map(int sizeX, int sizeZ, std::list<AObject*> *objects, IRessourceManager *manager) : objects_(objects), manager_(manager) {
    this->generateMap(sizeX, sizeZ);
}

Map &Map::operator=(const Map& old) {
    this->manager_ = old.manager_;
    this->sizeX_ = old.sizeX_;
    this->sizeZ_ = old.sizeZ_;
    return (*this);
}

Map::~Map() {
}

int Map::getSizeX() const {
    return (this->sizeX_);
}

int Map::getSizeZ() const {
    return (this->sizeZ_);
}

void Map::generateMap(int sizeX, int sizeZ) {
    this->sizeX_ = sizeX;
    this->sizeZ_ = sizeZ;
    for (int x = 0; x != sizeX; x++) {
        for (int z = 0; z != sizeZ; z++) {
            this->objects_->push_front(new Ground(x, z, this->manager_));
            this->objects_->push_back(new Ressources(x, z, this->manager_));
        }
    }
//    int x = 2, y = 0, z = -1;
//    while (x < sizeX) {
//        objects_->push_back(new Tree(x, y++, z, TRUNK, this->manager_));
//        objects_->push_back(new Tree(x, y++, z, TRUNK, this->manager_));
//        objects_->push_back(new Tree(x, y, z, TRUNK, this->manager_));
//        while (y != 5) {
//            objects_->push_back(new Tree(x - 1, y, z - 1, LEAF, this->manager_));
//            objects_->push_back(new Tree(x, y, z - 1, LEAF, this->manager_));
//            objects_->push_back(new Tree(x + 1, y, z - 1, LEAF, this->manager_));
//
//            objects_->push_back(new Tree(x - 1, y, z, LEAF, this->manager_));
//            objects_->push_back(new Tree(x, y, z, LEAF, this->manager_));
//            objects_->push_back(new Tree(x + 1, y, z, LEAF, this->manager_));
//
//            objects_->push_back(new Tree(x + 1, y, z + 1, LEAF, this->manager_));
//            objects_->push_back(new Tree(x, y, z + 1, LEAF, this->manager_));
//            objects_->push_back(new Tree(x - 1, y, z + 1, LEAF, this->manager_));
//            y++;
//        }
//        x += 4;
//        y = 0;
//
//    }
}