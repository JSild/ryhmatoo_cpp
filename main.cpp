#include <iostream>
#include "grid.h"

int main() {
    Grid grid(5, 5);
    grid.setCell(2, 2, Cell(42));
    std::cout << grid;
    return 0;
}