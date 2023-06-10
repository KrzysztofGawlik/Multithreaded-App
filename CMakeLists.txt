cmake_minimum_required(VERSION 3.20)

project(MultithreadedApp)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} main.cpp ${SOURCES})