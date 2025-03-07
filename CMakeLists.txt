cmake_minimum_required(VERSION 3.28.3)

project(out)

add_subdirectory(libs)


add_executable(out main.cpp)

target_link_libraries(out sfml-system sfml-window sfml-graphics sfml-audio page scrollbar text)