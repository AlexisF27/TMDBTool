#include "../include/HTTPCLient/HTTPClient.h"
#include "../include/TMDBTool/TMDBTool.h"
#include "../include/EnvLoader/EnvLoader.h"
#include "nlohmann/json.hpp"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>

using namespace std;
using json = nlohmann::json;

TMDBTool::TMDBTool() {
  loadEnvFile("../build/.env");
  const char* key = getenv("TMDB_API_KEY");
  if (key) { 
    apiKey = key; 
  } else { 
    throw runtime_error("TMDB_API_KEY environment variable not set"); 
  }
}

TMDBTool::~TMDBTool() {
}

void TMDBTool::transformType(string& type) { 
  if (type == "playing") {
    type = "now_playing"; 
    } else if (type == "top") { 
      type = "top_rated";
    }
  }


string TMDBTool::fetchtTypeTMDBTool(const string& type) {
    string mutableType = type;
    transformType(mutableType);
    const std::string url = "https://api.themoviedb.org/3/movie/" + mutableType + "?api_key=" + apiKey;
    HTTPClient httpClient;
    std::string response;
    try {
        response = httpClient.performHttpGet(url);
    } catch (const std::exception& e) {
        throw std::runtime_error("Failed to fetch the type of the movie: " + std::string(e.what()));
    }
    return response;
}

void TMDBTool::processApiResponse(const string& response) { 
  try { 
    auto jsonResponse = json::parse(response); 
    for (const auto& movie : jsonResponse["results"]) {
      cout << "Title: " << movie["title"] << endl; 
      cout << "Overview: " << movie["overview"] << endl; 
      cout << "Release Date: " << movie["release_date"] << endl; 
      cout << "Vote Average: " << movie["vote_average"] << endl; 
      cout << "----------------------------------------" << endl; 
    } 
    } catch (const std::exception& e) { 
      cerr << "Error parsing API response: " << e.what() << endl;
    }
}