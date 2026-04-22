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

// ###  <->   #   simple oscillator
//            #
//            #
void Templates::blinker(Grid& grid) {
    apply(grid, {{-1,0},{0,0},{1,0}});
}

// .###   period-2 oscillator
// ###.
void Templates::toad(Grid& grid) {
    apply(grid, {{0,0},{1,0},{2,0},{-1,1},{0,1},{1,1}});
}

// .#.
// ..#   moves diagonally
// ###
void Templates::glider(Grid& grid) {
    apply(grid, {{0,-1},{1,0},{-1,1},{0,1},{1,1}});
}

// #..#.   moves horizontally
// ....#
// #...#
// .####
void Templates::lightweightSpaceship(Grid& grid) {
    apply(grid, {{-2,-1},{1,-1},{2,0},{-2,1},{2,1},{-1,2},{0,2},{1,2},{2,2}});
}

// ......#.
// ##......   dies after many generations
// .#...###
void Templates::diehard(Grid& grid) {
    apply(grid, {{2,-1},{-4,0},{-3,0},{-3,1},{1,1},{2,1},{3,1}});
}

// .##
// ##.   famous long-lasting pattern
// .#.
void Templates::rpentomino(Grid& grid) {
    apply(grid, {{0,-1},{1,-1},{-1,0},{0,0},{0,1}});
}
