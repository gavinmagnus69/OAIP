cmake_minimum_required(VERSION 3.25)
project(map_and_set)

set(CMAKE_CXX_STANDARD 23)

add_executable(map_and_set main.cpp RBTree.h RBTree.cpp Tree.h Map.h Set.h unordered_map.h)
