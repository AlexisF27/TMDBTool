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
    src/EnvLoader.cpp
)

# Define the executable
add_executable(TMDBTool ${SOURCES})

# Link libraries
find_package(CURL REQUIRED)
find_package(nlohmann_json REQUIRED)

# Link the dotenv library, assuming it's correctly named
target_link_libraries(TMDBTool
    CURL::libcurl
    nlohmann_json::nlohmann_json
)

target_include_directories(TMDBTool PRIVATE lib/dotenv/include)

set(CMAKE_BUILD_TYPE Debug)
