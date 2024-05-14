cmake_minimum_required(VERSION 3.22.0)

project(machine_learning VERSION 1.0.0 LANGUAGES CXX)

set(EXE_NAME app)
set(LIB_NAME mnist)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)



add_subdirectory(mnist)
add_subdirectory(app)
