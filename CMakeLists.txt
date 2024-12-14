cmake_minimum_required(VERSION 3.10)
project(TMDBTool)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories (for header files)
include_directories(include)

# Add all source files
set(SOURCES
    src/main.cpp
    src/TMDBTool.cpp
    src/HTTPClient.cpp
)

include_directories(include)
# Define the executable
add_executable(TMDBTool ${SOURCES})

find_package(CURL REQUIRED)
target_link_libraries(TMDBTool PRIVATE CURL::libcurl)

find_package(nlohmann_json REQUIRED)
target_link_libraries(TMDBTool PRIVATE nlohmann_json::nlohmann_json)