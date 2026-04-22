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

int Grid::countLiveNeighbors(int x, int y) const {
    int count = 0;
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (dx == 0 && dy == 0) continue;
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < width && ny >= 0 && ny < height)
                count += cells[ny][nx].getValue();
        }
    }
    return count;
}

void Grid::nextGeneration() {
    std::vector<std::vector<Cell>> next(height, std::vector<Cell>(width));
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int neighbors = countLiveNeighbors(x, y);
            int alive = cells[y][x].getValue();
            if (alive == 1)
                next[y][x] = Cell((neighbors == 2 || neighbors == 3) ? 1 : 0);
            else
                next[y][x] = Cell(neighbors == 3 ? 1 : 0);
        }
    }
    cells = next;
}

bool Grid::isEmpty() const {
    for (const auto& row : cells)
        for (const auto& cell : row)
            if (cell.getValue() == 1) return false;
    return true;
}

bool Grid::operator==(const Grid& other) const {
    return cells == other.cells;
}

std::ostream& operator<<(std::ostream& os, const Grid& grid) {
    for (const auto& row : grid.cells) {
        for (const auto& cell : row) {
            os << cell << " ";
        }
        os << "\n";
    }
    return os;
}