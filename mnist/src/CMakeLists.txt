
set(LIB_FILES "./data_handler.cc"
                "./data.cc"
                "./../include/data_handler.hpp"
                "./../include/data.hpp")

add_library(${LIB_NAME} STATIC ${LIB_FILES})
target_include_directories(${LIB_NAME} PUBLIC "./../include")
