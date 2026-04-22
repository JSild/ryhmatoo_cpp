#pragma once
#include <vector>
#include <iostream>
#include "cell.h"

class Grid {
public:
    Grid(int width, int height);
    Cell& getCell(int x, int y);
    void setCell(int x, int y, const Cell& cell);
    int getWidth() const;
    int getHeight() const;
    int countLiveNeighbors(int x, int y) const;
    void nextGeneration();
    friend std::ostream& operator<<(std::ostream& os, const Grid& grid);
private:
    std::vector<std::vector<Cell>> cells;
    int width;
    int height;
};