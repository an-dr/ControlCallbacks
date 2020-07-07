set(CMAKE_CXX_STANDARD 14)

project(ControlCallbacks)
cmake_minimum_required(VERSION 3.15)

add_executable(ControlCallbacks examples/simple_demo.cpp)
target_include_directories(ControlCallbacks PUBLIC include)
target_sources(ControlCallbacks PUBLIC src/ControlCallbacks.cpp)

