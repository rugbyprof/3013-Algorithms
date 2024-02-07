#include <iostream>
#include <fstream>
#include "./headers/json.hpp" // Make sure this points to the correct path of json.hpp
#include "./headers/timer.hpp"

using namespace std;

using json = nlohmann::json;

int main() {

    Timer T;   // create a timer
    T.Start(); // start it

    // Load your JSON object as shown in previous examples
    std::string filePath = "./data/dictionary.json";
    std::ifstream fileStream(filePath);
    json myJson;
    if (fileStream.is_open()) {
        fileStream >> myJson;
        fileStream.close();
    } else {
        std::cerr << "Failed to open file: " << filePath << std::endl;
        return 1;
    }

    T.End(); // end the current timer
    printf("Nanoseconds: %.17f\n", (double)T.NanoSeconds() / 1000000000);

    // The substring you are looking for in the keys
    std::string partialKey = "abax";

    // Iterate over all key-value pairs
    for (auto& element : myJson.items()) {
        std::string key = element.key();
        
        // Check if the key contains the partialKey substring
        if (key.find(partialKey) != std::string::npos) {
            // Found a match, do something with it
            std::cout << "Found partial match: " << key << " -> " << element.value() << std::endl;
        }
    }

    return 0;
}