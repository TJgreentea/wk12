#ifndef MINE_H
#define MINE_H

#include "GameEntity.h"
#include "Explosion.h"

class Mine : public GameEntity {
public:
    Mine(int x, int y) : GameEntity(x, y, 'M') {}

    Explosion explode() {
        type = 'X';
        return Explosion(std::get<0>(position), std::get<1>(position));
    }
};

#endif // MINE_H
