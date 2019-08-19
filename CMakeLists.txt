cmake_minimum_required(VERSION 3.0)  # Minimum version of CMake required.
project(IdleMoney LANGUAGES CXX)  # Project name and languages list
set(CMAKE_CXX_STANDARD 11)  # The required C++ standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # The C++11 standard must be set

# # # The project itself # # #
# It does not contains any other subdir with a CMakeLists.txt file so no need to do "add_subdirectory"
add_executable(${PROJECT_NAME})  # Sets the executable name. Here it is the same as the project name.
target_include_directories(${PROJECT_NAME} PRIVATE extlibs/PDCurses-3.8/)  # (normally) adds the PDCurses lib folder to include path
