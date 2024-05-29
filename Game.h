#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Ship.h"
#include "Mine.h"
#include "Utils.h"

class Game {
private:
    std::vector<GameEntity*> entities;

public:
    std::vector<GameEntity*> get_entities() { return entities; }
    void set_entities(const std::vector<GameEntity*>& entities) { this->entities = entities; }

    std::vector<GameEntity*> initGame(int numShips, int numMines, int gridWidth, int gridHeight) {
        for (int i = 0; i < numShips; ++i) {
            auto pos = Utils::generateRandomPos(gridWidth, gridHeight);
            entities.push_back(new Ship(std::get<0>(pos), std::get<1>(pos)));
        }
        for (int i = 0; i < numMines; ++i) {
            auto pos = Utils::generateRandomPos(gridWidth, gridHeight);
            entities.push_back(new Mine(std::get<0>(pos), std::get<1>(pos)));
        }
        return entities;
    }

    void gameLoop(int maxIterations, double mineDistanceThreshold) {
        for (int iteration = 0; iteration < maxIterations; ++iteration) {
            for (auto& entity : entities) {
                if (entity->getType() == 'S') {
                    dynamic_cast<Ship*>(entity)->move(1, 0);
                }
            }

            for (auto& shipEntity : entities) {
                if (shipEntity->getType() == 'S') {
                    for (auto& mineEntity : entities) {
                        if (mineEntity->getType() == 'M') {
                            double distance = Utils::calculateDistance(shipEntity->getPos(), mineEntity->getPos());
                            if (distance < mineDistanceThreshold) {
                                Explosion explosion = dynamic_cast<Mine*>(mineEntity)->explode();
                                explosion.apply(*shipEntity);
                            }
                        }
                    }
                }
            }

            bool allShipsDestroyed = true;
            for (auto& entity : entities) {
                if (entity->getType() == 'S') {
                    allShipsDestroyed = false;
                    break;
                }
            }

            if (allShipsDestroyed) {
                break;
            }
        }
    }

    ~Game() {
        for (auto entity : entities) {
            delete entity;
        }
    }
};

#endif // GAME_H
