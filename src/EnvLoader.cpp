#include "../include/EnvLoader/EnvLoader.h"
#include <fstream>
#include <iostream>
#include <cstdlib> // For setenv
#include <algorithm> // For remove

void loadEnvFile(const std::string& filePath) {
    
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open .env file" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        size_t delimiterPos = line.find('=');
        if (delimiterPos == std::string::npos) {
            continue; // Skip lines without '='
        }

        std::string name = line.substr(0, delimiterPos);
        std::string value = line.substr(delimiterPos + 1);

        // Remove surrounding quotes if they exist
        if (!value.empty() && ((value.front() == '"' && value.back() == '"') || (value.front() == '\'' && value.back() == '\''))) {
            value = value.substr(1, value.size() - 2);
        }

        // Set the environment variable
        if (setenv(name.c_str(), value.c_str(), 1) != 0) {
            std::cerr << "Error: Failed to set environment variable " << name << std::endl;
        } else {
            std::cout << "Set environment variable: " << name << " = " << value << std::endl;
        }
    }

    file.close();
}
