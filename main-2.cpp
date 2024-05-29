#include <iostream>
#include "Ship.h"
#include "Mine.h"
#include "Explosion.h"

int main() {
    Ship ship(10, 10);
    Mine mine(15, 15);

    std::cout << "Initial Ship Position: (" << std::get<0>(ship.getPos()) << ", " << std::get<1>(ship.getPos()) << ")\n";
    ship.move(2, 3);
    std::cout << "Ship Position after move: (" << std::get<0>(ship.getPos()) << ", " << std::get<1>(ship.getPos()) << ")\n";

    std::cout << "Mine Position: (" << std::get<0>(mine.getPos()) << ", " << std::get<1>(mine.getPos()) << ")\n";
    Explosion explosion = mine.explode();
    std::cout << "Mine Position after explode: (" << std::get<0>(mine.getPos()) << ", " << std::get<1>(mine.getPos()) << ")\n";
    std::cout << "Mine Type after explode: " << mine.getType() << "\n";

    explosion.apply(ship);
    std::cout << "Ship Position after explosion: (" << std::get<0>(ship.getPos()) << ", " << std::get<1>(ship.getPos()) << ")\n";
    std::cout << "Ship Type after explosion: " << ship.getType() << "\n";

    return 0;
}
