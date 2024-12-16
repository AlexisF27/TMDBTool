#ifndef TMDBTOOL_H
#define TMDBTOOL_H

#include <string>

using namespace std;

class TMDBTool
{
public:
  TMDBTool();
  ~TMDBTool();
  string fetchtTypeTMDBTool(const string& type);
  void processApiResponse(const string& response);
private:
  string apiKey;
  void transformType(string& type);
};

#endif