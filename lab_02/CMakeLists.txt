cmake_minimum_required(VERSION 3.17)
project(lab_02)

set(CMAKE_CXX_STANDARD 17)

add_library(${PROJECT_NAME} include/TaskData.h src/Newton.cpp include/Newton.h include/VectorUtils.h src/TaskData.cpp src/Approximation.cpp include/Approximation.h)

target_include_directories(${PROJECT_NAME} PRIVATE include)


add_executable(${PROJECT_NAME}_debug main.cpp)

target_link_libraries(${PROJECT_NAME}_debug PUBLIC ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}_debug PRIVATE include)