#pragma once
#include <vector>
#include <iostream>

class Cell {
public:
    Cell() : value(0) {}
    Cell(int value) : value(value) {}
    int getValue() const { return value; }
    void setValue(int newValue) { value = newValue; }
    bool operator==(const Cell& other) const { return value == other.value; }
    friend std::ostream& operator<<(std::ostream& os, const Cell& cell);
private:
    int value;
};