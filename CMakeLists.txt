cmake_minimum_required(VERSION 3.19)
project(mensch)

set(CMAKE_CXX_STANDARD 14)
add_executable(mensch main.cpp GameActor.h Piece.cpp Piece.h Command.h Player.cpp Player.h Board.cpp Board.h Circle.cpp Circle.h ColorModel.cpp ColorModel.h Game.cpp Game.h AIEngine.cpp AIEngine.h BoardCirclePieceInfo.cpp BoardCirclePieceInfo.h MoveCommand.cpp MoveCommand.h CommandStream.cpp CommandStream.h PhysicsEngine.cpp PhysicsEngine.h Observer.cpp Observer.h ColorModelFactory.cpp ColorModelFactory.h Subject.cpp Subject.h GamePlay.cpp GamePlay.h AnalyticalEngine.cpp AnalyticalEngine.h DataCarrier.h GameFinishedDataCarrier.cpp GameFinishedDataCarrier.h WaitingCountDataCarrier.cpp WaitingCountDataCarrier.h MovingPieceInDataCarrier.cpp MovingPieceInDataCarrier.h Dice.cpp Dice.h DistanceCoveredDataCarrier.cpp DistanceCoveredDataCarrier.h MovePieceOutOfBoardCommand.cpp MovePieceOutOfBoardCommand.h PieceCollisionDataCarrier.cpp PieceCollisionDataCarrier.h matplotlibcpp.h PlottingEngine.cpp PlottingEngine.h GameExecutioner.cpp GameExecutioner.h StepIntoTrapDataCarrier.cpp StepIntoTrapDataCarrier.h)
include_directories(mensch /usr/include/python3.8/)
add_compile_definitions(WITHOUT_NUMPY)
target_link_libraries(mensch python3.8)
