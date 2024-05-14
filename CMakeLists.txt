cmake_minimum_required(VERSION 3.22.0)

project(machine_learning VERSION 1.0.0 LANGUAGES CXX)

set(EXE_NAME app)
set(MNIST_LIB_NAME mnist_lib)
set(KNN_LIB_NAME KNN_lib)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)



add_subdirectory(mnist)
add_subdirectory(KNN)
add_subdirectory(app)
