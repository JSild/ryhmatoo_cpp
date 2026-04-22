#include <iostream>
#include <thread>
#include <chrono>
#include "grid.h"

int main() {
    Grid grid(20, 20);

    // Glider
    grid.setCell(1, 0, Cell(1));
    grid.setCell(2, 1, Cell(1));
    grid.setCell(0, 2, Cell(1));
    grid.setCell(1, 2, Cell(1));
    grid.setCell(2, 2, Cell(1));

    for (int gen = 0; ; gen++) {
        system("cls");
        std::cout << "Generation: " << gen << "\n\n";
        std::cout << grid << std::endl;
        std::cout << "---------------------------" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        grid.nextGeneration();
    }

    return 0;
}
