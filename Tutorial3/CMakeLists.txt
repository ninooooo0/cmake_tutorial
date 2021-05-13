cmake_minimum_required(VERSION 3.19)

# set the project name and version
project(Factorial VERSION 2.1)

option(USE_MYFACTORIAL "Use another big number facorial implementation" OFF)
# configure a header file to pass some of the CMake settings to the source code
configure_file(factorialConfig.h.in factorialConfig.h)


if(USE_MYFACTORIAL)
    # add our factorial lib
    add_subdirectory(ExtensibleFactorial)
    list(APPEND EXTRA_LIBS ExtensibleFactorial)
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/ExtensibleFactorial")
endif()

add_executable(factorial factorial.cpp)

# link library ExtensibleFactorial
target_link_libraries(factorial PUBLIC ${EXTRA_LIBS})

# add the binary tree to the search path for include files, so that we will find factorialConfig.h
target_include_directories(factorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${EXTRA_INCLUDES}"
                           )

                           