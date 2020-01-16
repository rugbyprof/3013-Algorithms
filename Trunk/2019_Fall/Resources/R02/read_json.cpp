#include <iostream>
#include <fstream>
//https://stackoverflow.com/questions/55116344/how-to-setup-vs-code-for-c-14-c-17
//https://github.com/nlohmann/json
#include "json.hpp"

using namespace std;

using json = nlohmann::json;

int main(int argc,char **argv){

    json data;

    std::ifstream i("cities.json");
    
    i >> data;

    //std::cout << data.dump(4) << std::endl;

    for (json::iterator it = data.begin(); it != data.end(); ++it) {
        //std::cout << it.key() << " : \n";
        for (auto& element : it.value()) {
            std::cout << element << '\n';
        }

    }
   
    return 0;
}