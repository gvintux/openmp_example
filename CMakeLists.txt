cmake_minimum_required(VERSION 3.0)
project(openmp_example)

set(CMAKE_CXX_STANDARD 11)


add_executable(${PROJECT_NAME} main.cpp)
target_compile_definitions(${PROJECT_NAME} PRIVATE PARALLEL)
target_compile_options(${PROJECT_NAME} PRIVATE -fopenmp)
target_link_libraries(${PROJECT_NAME} gomp)

add_executable("no_${PROJECT_NAME}" main.cpp)

