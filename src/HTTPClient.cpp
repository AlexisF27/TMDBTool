#include "../include/HTTPCLient/HTTPClient.h"
#include <curl/curl.h>
#include <stdexcept>

// Constructor
HTTPClient::HTTPClient() {
    // Initialize libcurl globally (optional but good practice)
    curl_global_init(CURL_GLOBAL_DEFAULT);
}

// Destructor
HTTPClient::~HTTPClient() {
    // Cleanup libcurl resources
    curl_global_cleanup();
}

// Callback to write received data into a string
size_t HTTPClient::WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userData) {
    size_t totalSize = size * nmemb;
    userData->append((char*)contents, totalSize);
    return totalSize;
}

// Perform an HTTP GET request
std::string HTTPClient::performHttpGet(const std::string& url) {
    CURL* curl = curl_easy_init();
    if (!curl) {
        throw std::runtime_error("Failed to initialize CURL.");
    }

    std::string response;
    CURLcode res;

    // Configure CURL
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "github-activity-cli");

    // Perform the request
    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        curl_easy_cleanup(curl);
        throw std::runtime_error("HTTP request failed: " + std::string(curl_easy_strerror(res)));
    }

    // Cleanup
    curl_easy_cleanup(curl);
    return response;
}
