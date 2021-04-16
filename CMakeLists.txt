cmake_minimum_required(VERSION 3.10)
project(MTParser)

set(CMAKE_CXX_STANDARD 17)
add_library(libmtparser STATIC Parser.cpp Tokenizer.cpp)
add_executable(MTParser main.cpp)
target_link_libraries(MTParser libmtparser)