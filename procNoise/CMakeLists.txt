#min config
cmake_minimum_required (VERSION 2.8.1)
cmake_policy(SET CMP0042 NEW)

set (projectName "procNoise")
project(${projectName})

include_directories (${PROJECT_SOURCE_DIR}/include)

file (GLOB headers "*.h")
file (GLOB sources "*.c")

SET_SOURCE_FILES_PROPERTIES( ${sources} PROPERTIES LANGUAGE CXX )

set (DIRS "src" "include")

foreach (dir ${DIRS})
   file (GLOB h_${dir} "${dir}/*.h")
   file (GLOB s_${dir} "${dir}/*.c")
   source_group (${dir} FILES ${s_${dir}} ${h_${dir}})
   set (sources ${sources} ${s_${dir}})
   set (header ${headers} ${h_${dir}})
endforeach ()

add_library(${projectName} SHARED ${sources})

set_target_properties(${projectName}
    PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/target"
)
