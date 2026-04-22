#pragma once
#include "grid.h"
#include <vector>
#include <utility>

class Templates {
public:
    static void blinker(Grid& grid);
    static void toad(Grid& grid);
    static void glider(Grid& grid);
    static void lightweightSpaceship(Grid& grid);
    static void diehard(Grid& grid);
    static void rpentomino(Grid& grid);
private:
    static void apply(Grid& grid, const std::vector<std::pair<int,int>>& offsets);
};
