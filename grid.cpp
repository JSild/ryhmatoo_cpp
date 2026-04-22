#include "grid.h"
#include "cell.h"

Grid::Grid(int width, int height) : width(width), height(height) {
    cells.resize(height, std::vector<Cell>(width));
}

Cell& Grid::getCell(int x, int y) {
    return cells[y][x];
}

void Grid::setCell(int x, int y, const Cell& cell) {
    cells[y][x] = cell;
}

int Grid::getWidth() const {
    return width;
}

int Grid::getHeight() const {
    return height;
}

std::ostream& operator<<(std::ostream& os, const Grid& grid) {
    for (const auto& row : grid.cells) {
        for (const auto& cell : row) {
            os << cell << " ";
        }
        os << std::endl;
    }
    return os;
}