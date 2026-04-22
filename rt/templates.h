#pragma once
#include "grid.h"
#include <vector>
#include <utility>

class Templates {
public:
    static void block(Grid& grid);       // 2x2  → stable
    static void rpentomino(Grid& grid);  // 5 rakku ebakorr. → stable
    static void vertical(Grid& grid);    // 4 rakku veerus → stable
    static void diehard(Grid& grid);     // 7 rakku → death (130 gen)
    static void blinker(Grid& grid);     // 3 rakku reas → repeat
    static void boat(Grid& grid);        // 5 rakku paat → stable
private:
    static void apply(Grid& grid, const std::vector<std::pair<int,int>>& offsets);
};
