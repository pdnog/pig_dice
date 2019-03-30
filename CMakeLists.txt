cmake_minimum_required(VERSION 2.4)

project(pig_dice)

include_directories(./include)

add_executable( pig ./src/main.cpp ./src/dice.cpp ./src/pig_dice.cpp ./src/player.cpp)