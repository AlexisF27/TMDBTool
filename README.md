# TMDBTool

## Overview
TMDBTool is a command-line application that interacts with the The Movie Database (TMDB) API to retrieve movie information based on categories like "Now Playing," "Popular," "Top Rated," and "Upcoming."

# Project URL
```bash
https://roadmap.sh/projects/tmdb-cli
```

## Features
- Fetch movie data from the TMDB API.
- Support for multiple movie categories.
- Environment variable management for the API key.
- Clean and minimal CMake configuration for dependency management.

## Prerequisites
1. C++ Compiler:
  - Requires a C++17-compatible compiler.
2. CMake:
  - Version 3.10 or higher.
3. Libraries:
  - libcurl: For making HTTP requests.
  - nlohmann/json: For JSON parsing.

## Installation

1. Clone the Repository:

```bash
git clone <repository-url>
cd TMDBTool
```

2. Prepare a .env File: Create a .env file in the project root directory with the following content:
```bash
TMDB_API_KEY=your_tmdb_api_key_here
```

3. Build the Project: Use CMake to configure and build the project:
```bash
mkdir build && cd build
cmake ..
make
```

4. Run the Application: After a successful build, run the application as follows:
```bash
./TMDBTool --type <type>
```

## Usage

- Command Syntax

  ```bash
   ./TMDBTool --type <type>
  ```


## Parameters:
- --type <type>: Specifies the category of movies to fetch.
  - **playing** → Fetches "Now Playing" movies.
  - **popular** → Fetches "Popular" movies.
  - **top** → Fetches "Top Rated" movies.
  - **upcoming** → Fetches "Upcoming" movies.


## Example:
This command retrieves a list of movies currently "Now Playing" from the TMDB API.
```bash
  ./TMDBTool --type playing
```

## Project Structure: 
```bash
TMDBTool/
├── include/
│   ├── EnvLoader/
│   │   ├── EnvLoader.h
│   ├── TMDBTool/
│       ├── TMDBTool.h
├── src/
│   ├── main.cpp
│   ├── TMDBTool.cpp
│   ├── HTTPClient.cpp
│   ├── EnvLoader.cpp
├── .env               # File containing your TMDB API key
├── CMakeLists.txt     # Build configuration
└── README.md
```

## CMake Configuration | Dependecies

The project uses CMake to manage dependencies:
- libcurl: For HTTP requests.
- nlohmann/json: For JSON parsing.
Dependencies are found and linked automatically using find_package in CMakeLists.txt:

```bash
# Find and link libraries
find_package(CURL REQUIRED)
find_package(nlohmann_json REQUIRED)

# Link libraries to the target executable
target_link_libraries(TMDBTool
    CURL::libcurl
    nlohmann_json::nlohmann_json
)
```

## Environment Variables
The .env file is used to store the TMDB API Key securely. The EnvLoader module reads this file and sets the environment variable:

- **.env** File Example:
```bash
TMDB_API_KEY=your_tmdb_api_key_here
```

The program reads the environment variable using getenv:

```bash
const char* apiKey = getenv("TMDB_API_KEY");
```

## License
This project is licensed under the MIT License. See LICENSE for more details.

