cmake_minimum_required(VERSION 3.20)
project(ryhmatoo)

add_executable(ryhmatoo
    src/main.cpp
    src/cell.cpp
    src/grid.cpp
    src/templates.cpp
)

target_include_directories(ryhmatoo PRIVATE include)
target_compile_features(ryhmatoo PRIVATE cxx_std_20)