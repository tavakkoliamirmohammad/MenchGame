cmake_minimum_required(VERSION 3.19)
project(mensch)

set(CMAKE_CXX_STANDARD 14)

add_executable(mensch main.cpp GameActor.h Piece.cpp Piece.h Command.h Player.cpp Player.h Board.cpp Board.h Circle.cpp Circle.h ColorModel.cpp ColorModel.h Game.cpp Game.h AIEngine.cpp AIEngine.h BoardCirclePieceInfo.cpp BoardCirclePieceInfo.h MoveCommand.cpp MoveCommand.h CommandStream.cpp CommandStream.h PhysicsEngine.cpp PhysicsEngine.h Observer.cpp Observer.h ColorModelFactory.cpp ColorModelFactory.h Subject.cpp Subject.h)