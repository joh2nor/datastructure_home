cmake_minimum_required(VERSION 3.23)
project(LinkStack)

set(CMAKE_CXX_STANDARD 14)

add_executable(LinkStack main.cpp Node.h LinkStack.cpp LinkStack.h)
