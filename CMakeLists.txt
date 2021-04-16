cmake_minimum_required(VERSION 3.10)
project(MTParser)

set(CMAKE_CXX_STANDARD 17)

add_executable(MTParser main.cpp Tokenizer.cpp Tokenizer.h Parser.cpp Parser.h)