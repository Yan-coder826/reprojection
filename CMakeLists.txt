cmake_minimum_required(VERSION 3.16)
project(reprojection LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Eigen3 3.3 REQUIRED NO_MODULE)

add_library(reprojection_lib src/reprojection.cpp)
target_include_directories(reprojection_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(reprojection_lib PUBLIC Eigen3::Eigen)

add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE reprojection_lib)
