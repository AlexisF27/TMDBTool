#include <iostream>
#include <nlohmann/json.hpp>
#include <cstdlib>
#include "../include/TMDBTool/TMDBTool.h"
#include "../include/EnvLoader/EnvLoader.h"

using namespace std;

int main(int argc, char* argv[])
{
  try
  {
    cout << "Loading environment variables from .env file..." << endl;
    loadEnvFile("../build/.env");
    cout << "Checking environment variables..." << endl;
    extern char **environ; 
    for (char **env = environ; *env != 0; env++) { 
      cout << *env << endl; 
      } 
    const char* apiKey = getenv("TMDB_API_KEY"); 
    if (apiKey) { 
      cout << "API Key: " << apiKey << endl; 
    } else { 
      cerr << "Error: API Key not set" << endl; 
    }

    cout << "Checking command line arguments..." << endl;
    
    if (argc != 3)
      {
        cerr << "Error: Invalid command line arguments.\n";
        cerr << "Usage: tmdb-app --type <type>\n";
        return 1;
      }

    string argType = argv[1];
    if (argType != "--type")
    {
      cerr << "Error: Missing '--type' argument.\n";
      cerr << "Usage: tmdb-app --type <type>\n";
      return 2;
    }

    string type = argv[2];

    if (type == "playing" || type == "popular" || type == "top" || type == "upcoming")
    {
      /* TODO */
    }else{
      cerr << "Error: Invalid type.\n";
      cerr << "Usage: tmdb-app --type <type>\n";
      cerr << "Types: playing, popular, top, upcoming\n";
      return 3;
    }
    
    
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  
}