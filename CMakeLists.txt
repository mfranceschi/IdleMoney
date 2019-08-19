cmake_minimum_required(VERSION 3.0)  # Minimum version of CMake required.
project(IdleMoney LANGUAGES CXX)  # Project name and languages list
set(CMAKE_CXX_STANDARD 11)  # The required C++ standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # The C++11 standard must be set

# # # The project itself # # #
# It does not contains any other subdir with a CMakeLists.txt file so no need to do "add_subdirectory"
file(GLOB CPPFILES *.cpp)
add_executable(${PROJECT_NAME} ${CPPFILES})  # Sets the executable name and all source files that need to be looked at by CMake.
target_include_directories(${PROJECT_NAME} PUBLIC extlibs/)  # (normally) adds the PDCurses lib folder to include path
