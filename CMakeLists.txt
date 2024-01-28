# Minimum required CMake version
cmake_minimum_required(VERSION 3.28.1)

# Project name
project(laserThingConsole)

# Set C++ standard (e.g., C++11, C++14, C++17)
set(CMAKE_CXX_STANDARD 20)

# Source files
set(SOURCES
    src/main.cpp
    src/getFirstSquare.cpp
    src/getNextSquare.cpp
    src/printZeroGrid.cpp
    src/setGridPattern.cpp
    src/squareParamSetup.cpp
    src/visualize.cpp
)

# Header files
set(HEADERS
    include/gridElement.hpp
)

# Add include directories
include_directories(include)

# Create an executable
add_executable(laserThingConsole ${SOURCES} ${HEADERS})

# Check the operating system and set platform-specific configurations
#if(UNIX)
    # Linux-specific settings
    # (Add Linux-specific libraries or compiler flags as needed)
#elseif(WIN32)
    # Windows-specific settings
    # (Add Windows-specific libraries or compiler flags as needed)
#endif()
