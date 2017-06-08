cmake_minimum_required(VERSION 3.6)
project(LinList)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    LinList.cpp
    LinList.h
    LinListTst.cpp
    ListElement.cpp
    ListElement.h)

add_executable(LinList ${SOURCE_FILES})