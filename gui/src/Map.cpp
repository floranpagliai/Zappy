/*
 * File:   Map.cpp
 * Author: floran
 *
 * Created on 19 juin 2013, 22:38
 */

#include "Map.h"

Map::Map(int sizeX, int sizeY, std::list<AObject*>* objects_, IRessourceManager* manager) : manager_(manager) {
    this->sizeX_ = sizeX;
    this->sizeY_ = sizeY;
    for (int i = 0; i != sizeY; i++) {
        for (int x = -1; x != sizeX; x++) {
            objects_->push_front(new Ground(i, x, this->manager_));
        }
    }
    int x = 2, y = 0, z = -1;
    while (x < sizeX) {
        objects_->push_back(new Tree(x, y++, z, 0, this->manager_));
        objects_->push_back(new Tree(x, y++, z, 0, this->manager_));
        while (y != 5) {
            objects_->push_back(new Tree(x - 1, y, z - 1, 1, this->manager_));
            objects_->push_back(new Tree(x, y, z - 1, 1, this->manager_));
            objects_->push_back(new Tree(x + 1, y, z - 1, 1, this->manager_));

            objects_->push_back(new Tree(x - 1, y, z, 1, this->manager_));
            objects_->push_back(new Tree(x, y, z, 1, this->manager_));
            objects_->push_back(new Tree(x + 1, y, z, 1, this->manager_));

            objects_->push_back(new Tree(x + 1, y, z + 1, 1, this->manager_));
            objects_->push_back(new Tree(x, y, z + 1, 1, this->manager_));
            objects_->push_back(new Tree(x - 1, y, z + 1, 1, this->manager_));
            y++;
        }
        x += 4;
        y = 0;

    }
}

Map::~Map() {
}

