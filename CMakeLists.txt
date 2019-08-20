cmake_minimum_required(VERSION 2.8)  # Minimum version of CMake required.
project(IdleMoney CXX)  # Project name and languages list
set(CMAKE_CXX_STANDARD 11)  # The required C++ standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # The C++11 standard must be set

# The CURSES lib
set(pdcurses_folder extlibs/PDCurses/)
add_custom_target(
    curseslib_target 
    COMMAND nmake -f Makefile.vc 
    WORKING_DIRECTORY ../${pdcurses_folder}wincon/
)
add_library(curseslib STATIC IMPORTED GLOBAL)
add_dependencies(curseslib curseslib_target)
set_target_properties(
    curseslib
    PROPERTIES
    IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/${pdcurses_folder}wincon/pdcurses.lib
    INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/extlibs/
)

# The final project
file(GLOB CPPFILES *.cpp)
add_executable(${PROJECT_NAME} ${CPPFILES} ${PDCURSESFILES})  # Sets the executable name and all source files that need to be looked at by CMake.
target_link_libraries(${PROJECT_NAME} curseslib)
