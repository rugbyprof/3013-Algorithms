## Json Intro


### JSON (JavaScript Object Notation)

It is a lightweight data-interchange format that's easy for humans to read and write, and easy for machines to parse and generate. It's based on a subset of the JavaScript Programming Language, Standard ECMA-262 3rd Edition - December 1999. JSON is completely language-independent but uses conventions familiar to programmers of the C-family of languages, including C, C++, C#, Java, JavaScript, Perl, Python, and many others. This makes JSON an ideal data-interchange language.

### When and Why JSON is Useful:

- **APIs and Web Services**: JSON is extensively used in web APIs and web services to facilitate communication between client and server. It serves as a common language that enables data interchange across different platforms and programming languages.
- **Configuration Files**: Its readability and simple syntax make JSON a popular choice for configuration files in various software applications, frameworks, and tools.
- **Data Storage**: Some NoSQL databases, like MongoDB, use JSON (or a binary equivalent, BSON) for storing documents, making it a natural choice for data persistence in certain applications.
- **Cross-Language Support**: JSON's language-agnostic nature allows it to be used in virtually any programming environment, making it a versatile choice for data interchange in multi-language development projects.

### Motivating Factors:

- **Human Readable**: JSON's syntax is clear and straightforward, making it easy to read and write by humans, which is great for debugging and manual editing.
- **Lightweight**: Its simplicity results in smaller file sizes compared to other formats like XML, leading to faster data transmission over networks.
- **Structured Data**: JSON can represent complex data structures, including nested arrays and objects, allowing for a rich expression of hierarchical data.
- **Widely Supported**: Virtually all programming languages have libraries or built-in support for JSON, making it a universal choice for data interchange.

### When JSON Might Not Be the Best Solution:

- **Binary Data**: JSON is not suited for binary data. While it's possible to encode binary data as strings (e.g., base64), it's inefficient and inflates the data size.
- **Very Large Datasets**: For extremely large datasets, JSON's text-based nature can lead to performance bottlenecks in parsing and serialization. In such cases, binary formats like Protocol Buffers or Avro might be more efficient.
- **Complex Documents**: If your data involves a lot of document markup (e.g., rich text formatting), formats like XML might be more appropriate due to their ability to better handle document-centric data.
- **Data Integrity**: JSON lacks features like comments (which can be important for configuration files) and must be handled with additional tools or conventions. Also, JSON doesn't natively support data types like dates; they need to be encoded as strings and parsed back, which can lead to issues if not handled carefully.

In summary, JSON shines for its simplicity, readability, and wide support across platforms and languages, making it an excellent choice for data interchange in most web-based applications and services. However, for specialized needs like handling binary data or very large datasets, other formats might be more suitable.

Below is an example of using c++ to "create" a json object 

```cpp

## Json Intro


```cpp
#include <iostream>
#include "json.hpp"

using namespace std;
using nlohmann::json;

int main() {
    // Creating a JSON object
    json myJson;
    myJson["name"] = "John Doe";
    myJson["age"] = 30;
    myJson["is_student"] = false;
    myJson["skills"] = {"C++", "Python", "JavaScript"};

    // Serialization
    // Allows to be stored in a file, then read back into a json object
    string serializedString = myJson.dump();
    cout << "Serialized JSON: " << serializedString << endl;
    cout<<endl;
    // Deserialization
    // Turns a string into a json object
    json deserializedJson = json::parse(serializedString);
    cout << "Deserialized JSON: " << deserializedJson.dump(4) << endl;

    return 0;
}
```
#### OutPut

(It's syntax highlighted in a terminal ... unless you implement it.)

```json
Serialized JSON: {"age":30,"is_student":false,"name":"John Doe","skills":["C++","Python","JavaScript"]}

Deserialized JSON: {
    "age": 30,
    "is_student": false,
    "name": "John Doe",
    "skills": [
        "C++",
        "Python",
        "JavaScript"
    ]
}
```


## Json File Load

Loading a JSON file like the one you described using nlohmann's JSON library in C++ is straightforward. The library provides a simple and intuitive way to parse a JSON file and convert its contents into a `json` object, which can then be used just like a regular C++ object.

1. **Include the Header**: Make sure you include the `json.hpp` header in your source file.
2. **Read the File**: Open the JSON file using an `std::ifstream` object.
3. **Parse the File**: Use the `json::parse()` function to parse the file's contents into a `json` object.

Here's a sample code snippet that demonstrates these steps:

```cpp
#include <iostream>
#include <fstream>
#include "json.hpp" // Make sure this points to the correct path of json.hpp

using json = nlohmann::json;

int main() {
    // Path to your JSON file
    std::string filePath = "path/to/your/file.json";

    // Open the file stream
    std::ifstream fileStream(filePath);
    
    if (!fileStream.is_open()) {
        std::cerr << "Failed to open file: " << filePath << std::endl;
        return 1;
    }

    // Parse the JSON file
    json myJson;
    try {
        fileStream >> myJson;
    } catch (json::parse_error& e) {
        std::cerr << "Parse error: " << e.what() << std::endl;
        // Handle errors (e.g., file not found, invalid JSON format)
        return 1;
    }

    // Close the file stream
    fileStream.close();

    // Now you can access your JSON data
    // For example, to print the definition of "abatvoix"
    std::cout << "abatvoix: " << myJson["abatvoix"] << std::endl;

    return 0;
}
```

This code opens the specified JSON file, parses its contents into a `json` object, and then you can access any value using the key, similar to how you would with a `std::map` or `std::unordered_map`.

Make sure the file path is correct and points to your JSON file. Also, handle any potential exceptions, especially `json::parse_error`, which can occur if the file content is not valid JSON.

Using nlohmann's JSON library like this can greatly simplify the process of working with JSON in C++, making it accessible even for those who are relatively new to the language.


## Example Problem

Iterating over a JSON object in C++ using nlohmann's JSON library to look for partial matches in keys is a bit unconventional but certainly doable. You would typically use a loop to go through each key-value pair in the JSON object and then apply some string matching logic to find the keys that partially match a given pattern.

Here's an example of how you might do this:

1. **Loop Through the JSON Object**: Use a range-based `for` loop or an iterator to go through all the key-value pairs in the JSON object.
2. **Match Keys**: Use string manipulation functions to check if the current key contains the desired substring (the partial match you're looking for).

Below is a sample code snippet that demonstrates this approach:

```cpp
#include <iostream>
#include <fstream>
#include "json.hpp" // Make sure this points to the correct path of json.hpp

using json = nlohmann::json;

int main() {
    // Load your JSON object as shown in previous examples
    std::string filePath = "path/to/your/file.json";
    std::ifstream fileStream(filePath);
    json myJson;
    if (fileStream.is_open()) {
        fileStream >> myJson;
        fileStream.close();
    } else {
        std::cerr << "Failed to open file: " << filePath << std::endl;
        return 1;
    }

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
```

In this example, `partialKey` is the substring you're looking for in the keys of your JSON object. The `find` method of `std::string` is used to check if the substring exists in the current key. If `find` returns `std::string::npos`, it means the substring was not found. Otherwise, it indicates a partial match, and you can then process the key-value pair as needed.

Keep in mind that this approach might not be the most efficient for large JSON objects or complex matching logic since it requires scanning through all keys. If you find yourself frequently needing to perform such operations, it might be worth considering if a different data structure or storage format could better suit your needs.

