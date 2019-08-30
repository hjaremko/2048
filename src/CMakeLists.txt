project(2048_src)

set(SOURCE_FILES main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})
