cmake_minimum_required(VERSION 3.5)

project(foc LANGUAGES C)

INCLUDE_DIRECTORIES(./inc)
AUX_SOURCE_DIRECTORY(./src  SRC)

ADD_EXECUTABLE(foc ${SRC})





