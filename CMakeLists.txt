# min config
cmake_minimum_required (VERSION 2.8.1)

PROJECT ("procWorldGen")

set (procLibName "procNoise")
set (mapGenName "wgen")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++1y -fdiagnostics-color")
endif()

#include
set (MAPGEN_INC ${CMAKE_SOURCE_DIR}/${procLibName}/include)
set (PROCNOISE_INC ${CMAKE_SOURCE_DIR}/${procLibName}/include)

#lib
set (LIBNOISE_LIB ${CMAKE_BINARY_DIR}/${procLibName}/)

add_subdirectory (${procLibName})
add_subdirectory (${mapGenName})
