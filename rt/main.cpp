#include <iostream>
#include <thread>
#include <chrono>
#include "grid.h"
#include "templates.h"

int main() {
    std::cout << "Conway's Game of Life\n\n";
    std::cout << "Vali pattern:\n";
    std::cout << "  1. Block       - 2x2 (stable)\n";
    std::cout << "  2. R-pentomino - 5 rakku ebakorr. (-> stable)\n";
    std::cout << "  3. Vertical    - 4 rakku veerus (-> stable)\n";
    std::cout << "  4. Diehard     - sureb 130 gen jargi (death)\n";
    std::cout << "  5. Blinker     - 3 rakku reas (repeat)\n";
    std::cout << "  6. Boat        - 5 rakku paat (stable)\n";
    std::cout << "\nValik: ";

    int choice;
    std::cin >> choice;

    Grid grid(40, 40);

    switch (choice) {
        case 1: Templates::block(grid);      break;
        case 2: Templates::rpentomino(grid); break;
        case 3: Templates::vertical(grid);   break;
        case 4: Templates::diehard(grid);    break;
        case 5: Templates::blinker(grid);    break;
        case 6: Templates::boat(grid);       break;
        default: Templates::block(grid);     break;
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
