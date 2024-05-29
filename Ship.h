#ifndef SHIP_H
#define SHIP_H

#include "GameEntity.h"

class Ship : public GameEntity {
public:
    Ship(int x, int y) : GameEntity(x, y, 'S') {}

    void move(int dx, int dy) {
        position = std::make_tuple(std::get<0>(position) + dx, std::get<1>(position) + dy);
    }
};

#endif // SHIP_H
