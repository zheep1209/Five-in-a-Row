cmake_minimum_required(VERSION 3.27)
project(game01 C)

set(CMAKE_C_STANDARD 23)

add_executable(
        game01
        test.c
        game.c
        game.h)
