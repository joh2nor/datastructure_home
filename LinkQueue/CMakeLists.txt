cmake_minimum_required(VERSION 3.23)
project(LinkQeue)

set(CMAKE_CXX_STANDARD 14)

add_executable(LinkQeue main.cpp Node.h LinkQueue.h LinkQueue.cpp)
