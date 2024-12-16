#include "../include/TMDBTool/TMDBTool.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

TMDBTool::TMDBTool() {
}

TMDBTool::~TMDBTool() {
}


string TMDBTool::fetchtTypeTMDBTool(const string& type) {
  return getenv("TMDB_KEY");
}

void TMDBTool::processApiResponse(const string& response) {
  cout << "API Response: " << response << endl;
}