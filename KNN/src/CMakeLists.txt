set(KNN_LIB_FILES knn.cc ./../include/knn.hpp)

add_library(${KNN_LIB_NAME} STATIC ${KNN_LIB_FILES})
target_include_directories(${KNN_LIB_NAME} PUBLIC ./../include ./../../mnist/include)
