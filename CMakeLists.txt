cmake_minimum_required(VERSION 3.15)
project(code)

set(CMAKE_CXX_STANDARD 14)

add_definitions(-O2)

include_directories(db)
include_directories(lib)
include_directories(src)

add_executable(code
        db/database.hpp
        db/database_cached.hpp
        db/filemanager.hpp
        db/List.hpp
        lib/hashtable.hpp
        lib/mytools.hpp
        lib/timetype.hpp
        src/cmdprocessor.hpp
        src/main.cpp
        src/systemcore.hpp
        CMakeLists.txt)
