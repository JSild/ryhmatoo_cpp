#include <iostream>
#include <thread>
#include <chrono>
#include "grid.h"
#include "templates.h"

int main() {
    std::cout << "Conway's Game of Life\n\n";
    std::cout << "Vali pattern:\n";
    std::cout << "  1. Blinker               - lihtne ostsillaator\n";
    std::cout << "  2. Toad                  - 2-sammuline ostsillaator\n";
    std::cout << "  3. Glider                - liigub diagonaalis\n";
    std::cout << "  4. Lightweight Spaceship - liigub horisontaalselt\n";
    std::cout << "  5. Diehard               - sureb umbes 130 generatsiooni jarel\n";
    std::cout << "  6. R-pentomino           - pikk ja kaootiline areng\n";
    std::cout << "\nValik: ";

    int choice;
    std::cin >> choice;

    Grid grid(20, 20);

    switch (choice) {
        case 1: Templates::blinker(grid);              break;
        case 2: Templates::toad(grid);                 break;
        case 3: Templates::glider(grid);               break;
        case 4: Templates::lightweightSpaceship(grid); break;
        case 5: Templates::diehard(grid);              break;
        case 6: Templates::rpentomino(grid);           break;
        default: Templates::blinker(grid);             break;
    }

    for (int gen = 0; ; gen++) {
        system("cls");
        std::cout << "Generation: " << gen << "\n\n";
        std::cout << grid << std::endl;

        if (grid.isEmpty()) {
            std::cout << "Koik rakud surnud. Mang loppes.\n";
            break;
        }

        Grid prev = grid;
        grid.nextGeneration();

        if (grid == prev) {
            std::cout << "Stabiilne seisund. Mang loppes.\n";
            break;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    return 0;
}
