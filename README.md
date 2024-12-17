# TMDBTool

## Overview
TMDBTool is a command-line application that interacts with the The Movie Database (TMDB) API to retrieve movie information based on categories like "Now Playing," "Popular," "Top Rated," and "Upcoming."

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
