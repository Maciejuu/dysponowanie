cmake_minimum_required(VERSION 3.21)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

set(Headers zdarzenia.h)
set(Headers pojazdy.h)

add_executable(untitled ${PROJECT_SOURCE_DIR}/ main.cpp zdarzenia.cpp pojazdy.cpp)
