#include "templates.h"

void Templates::apply(Grid& grid, const std::vector<std::pair<int,int>>& offsets) {
    int cx = grid.getWidth() / 2;
    int cy = grid.getHeight() / 2;
    for (auto [dx, dy] : offsets) {
        int x = cx + dx;
        int y = cy + dy;
        if (x >= 0 && x < grid.getWidth() && y >= 0 && y < grid.getHeight())
            grid.setCell(x, y, Cell(1));
    }
}

// ##   →  stable
// ##
void Templates::block(Grid& grid) {
    apply(grid, {{0,0},{1,0},{0,1},{1,1}});
}

// .##  →  stable (pikk evolutsioon)
// ##.
// .#.
void Templates::rpentomino(Grid& grid) {
    apply(grid, {{0,-1},{1,-1},{-1,0},{0,0},{0,1}});
}

// #.  →  stable
// #.
// #.
// ##
void Templates::vertical(Grid& grid) {
    apply(grid, {{0,-2},{0,-1},{0,0},{1,0}});
}

// ......#.  →  death pärast 130 generatsiooni
// ##......
// .#...###
void Templates::diehard(Grid& grid) {
    apply(grid, {{2,-1},{-4,0},{-3,0},{-3,1},{1,1},{2,1},{3,1}});
}

// ###  ↔  #   →  repeat (periood 2)
//          #
//          #
void Templates::blinker(Grid& grid) {
    apply(grid, {{-1,0},{0,0},{1,0}});
}

// ##.  →  stable
// #.#
// .#.
void Templates::boat(Grid& grid) {
    apply(grid, {{-1,-1},{0,-1},{-1,0},{1,0},{0,1}});
}
