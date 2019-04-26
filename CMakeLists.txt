cmake_minimum_required(VERSION 3.13)
project(Yeetlang)

set(CMAKE_CXX_STANDARD 14)

add_executable(Yeetlang main.cpp ModeController.cpp ModeController.h YeetInterpreter.cpp YeetInterpreter.h YeetParser.cpp YeetParser.h Logger.cpp Logger.h Instruction.cpp Instruction.h YeetEnv.cpp YeetEnv.h Instructions.cpp Instructions.h)