#min config
cmake_minimum_required (VERSION 2.8.1)

set (projectName "wgen")
project(${projectName})

include_directories (${PROJECT_SOURCE_DIR}/include)

link_directories (${PROCNOISE_INC})

file (GLOB headers "*.hpp")
file (GLOB sources "*.cpp")

set (DIRS "src" "include")

foreach (dir ${DIRS})
   file (GLOB h_${dir} "${dir}/*.hpp")
   file (GLOB s_${dir} "${dir}/*.cpp")
   source_group (${dir} FILES ${s_${dir}} ${h_${dir}})
   set (sources ${sources} ${s_${dir}})
   set (header ${headers} ${h_${dir}})
endforeach ()

add_executable (${projectName} ${sources})

find_package(SFML 2 REQUIRED system window graphics network audio)

target_link_libraries (${projectName} procNoise ${SFML_LIBRARIES})

set_target_properties(${projectName}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/target"
)
