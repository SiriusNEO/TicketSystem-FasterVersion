cmake_minimum_required(VERSION 3.15)
project(code)

set(CMAKE_CXX_STANDARD 14)

add_definitions("-g -O2 -Wall")

add_executable(code
               src/main.cpp src/cmdprocessor.hpp src/systemcore.hpp
               lib/mytools.hpp lib/hashtable.hpp lib/timetype.hpp
               db/blocklist.h db/filemanager.hpp )