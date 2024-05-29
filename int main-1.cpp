#include <iostream>
#include "GameEntity.h"
#include "Utils.h"

int main() {
    srand(static_cast<unsigned>(time(0)));

    // Generate random positions
    auto pos1 = Utils::generateRandomPos(100, 100);
    auto pos2 = Utils::generateRandomPos(100, 100);

    // Create GameEntity objects
    GameEntity entity1(std::get<0>(pos1), std::get<1>(pos1), 'A');
    GameEntity entity2(std::get<0>(pos2), std::get<1>(pos2), 'B');

    // Output positions and types
    std::cout << "Entity 1: (" << std::get<0>(entity1.getPos()) << ", " << std::get<1>(entity1.getPos()) << "), Type: " << entity1.getType() << std::endl;
    std::cout << "Entity 2: (" << std::get<0>(entity2.getPos()) << ", " << std::get<1>(entity2.getPos()) << "), Type: " << entity2.getType() << std::endl;

    // Calculate and output distance
    double distance = Utils::calculateDistance(entity1.getPos(), entity2.getPos());
    std::cout << "Distance between Entity 1 and Entity 2: " << distance << std::endl;

    return 0;
}
