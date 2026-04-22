#include "cell.h"
std::ostream& operator<<(std::ostream& os, const Cell& cell) {
    os << cell.value;
    return os;
}