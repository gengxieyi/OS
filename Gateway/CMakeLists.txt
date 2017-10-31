cmake_minimum_required(VERSION 2.8)

PROJECT(FILE_SERVER)
FILE(GLOB SRC_LIST Main/Main.cpp ./Request/*.cpp ./Request/*.hpp ../Common/*.hpp ../Common/*.cpp ./Manage/*.cpp)
SET(CMAKE_CXX_FLAGS "-lpthread -g")
ADD_EXECUTABLE(main ${SRC_LIST})
