
set(MNIST_LIB_FILES "./data_handler.cc"
                "./data.cc"
                "./../include/data_handler.hpp"
                "./../include/data.hpp")

add_library(${MNIST_LIB_NAME} STATIC ${MNIST_LIB_FILES})
target_include_directories(${MNIST_LIB_NAME} PUBLIC "./../include")
