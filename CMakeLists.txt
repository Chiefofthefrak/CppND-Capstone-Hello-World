cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS} -pthread" )

project(OrbitGame)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})


file(GLOB project_SRCS temp/*.cpp) #temp/*.h

# Add project executable
add_executable(OrbitGame ${project_SRCS})


target_link_libraries(OrbitGame ${SDL2_LIBRARIES})
