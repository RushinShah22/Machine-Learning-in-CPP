
set(EXE_FILES app.cc)

add_executable(${EXE_NAME} ${EXE_FILES})
target_link_libraries(${EXE_NAME} PUBLIC ${MNIST_LIB_NAME} ${KNN_LIB_NAME})
