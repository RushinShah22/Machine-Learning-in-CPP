
set(EXE_FILES app.cc)

add_executable(${EXE_NAME} ${EXE_FILES})
target_link_libraries(${EXE_NAME} PUBLIC ${LIB_NAME})
