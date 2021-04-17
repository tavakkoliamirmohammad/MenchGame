cmake_minimum_required(VERSION 3.19)
project(mensch)

set(CMAKE_CXX_STANDARD 14)

add_executable(mensch main.cpp GameActor.h Piece.cpp Piece.h Command.h Player.cpp Player.h Board.cpp Board.h Circle.cpp Circle.h ColorModel.cpp ColorModel.h Game.cpp Game.h)