#ifndef HTTP_CLIENT_H
#define HTTP_CLIENT_H

#include <string>

class HTTPClient {
public:
    HTTPClient();
    ~HTTPClient();

    // Performs an HTTP GET request
    std::string performHttpGet(const std::string& url);

private:
    // Callback function to write data into a string
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userData);
};

#endif // HTTP_CLIENT_H