#include "cell.h"
std::ostream& operator<<(std::ostream& os, const Cell& cell) {
    os << (cell.value == 1 ? '#' : '.');
    return os;
}