cmake_minimum_required(VERSION 3.10)
project(2048)

set(CMAKE_CXX_STANDARD 17)
set(CURSES_NEED_NCURSES TRUE)

find_package(Curses REQUIRED)

include_directories(SYSTEM "${CURSES_INCLUDE_DIR}")
include_directories("include")
include_directories("extern/cxxcurses/include")
link_directories("${CURSES_INCLUDE_DIRS}")

add_subdirectory(src)