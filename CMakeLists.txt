cmake_minimum_required(VERSION 3.10)
# set(CMAKE_CXX_COMPILER "C:/MinGW/bin/g++.exe")
# Use this for wsl (windows subsystem for linux)
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Data_structures VERSION 1.0)

# Add the executable
add_executable(main test.cpp)

# Include the Array directory for header files
target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Array)

# Include the List directory for header files
target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/List)

# Include the Map directory for header files
target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Map)

# Include the Tree directory for header files
target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Tree)