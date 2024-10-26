cmake_minimum_required(VERSION 3.16)
project(ConvertApp)

set(CMAKE_CXX_STANDARD 17)
set(PROJECT_SOURCE_DIR ${CMAKE_SOURCE_DIR})

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)

find_package(OpenCV REQUIRED)

add_executable(ConvertApp ${SOURCES})

target_link_libraries(ConvertApp ${OpenCV_LIBS})
