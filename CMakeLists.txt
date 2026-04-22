cmake_minimum_required(VERSION 3.20)
project(ryhmatoo)

add_executable(ryhmatoo
        rt/cell.cpp
        rt/grid.cpp
        rt/main.cpp)
target_compile_features(ryhmatoo PRIVATE cxx_std_20)
