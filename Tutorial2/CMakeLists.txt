cmake_minimum_required(VERSION 3.19)

# set the project name and version
project(Factorial VERSION 2.1)

# configure a header file to pass some of the CMake settings to the source code
configure_file(factorialConfig.h.in factorialConfig.h)

add_executable(factorial factorial.cpp)

# add the binary tree to the search path for include files, so that we will find factorialConfig.h
target_include_directories(factorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
