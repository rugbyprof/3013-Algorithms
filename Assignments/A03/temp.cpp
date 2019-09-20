//https://stackoverflow.com/questions/55116344/how-to-setup-vs-code-for-c-14-c-17
//https://github.com/nlohmann/json

#include <fstream>
#include <iostream>
#include "json_helper.cpp"

using namespace std;



int main(int argc, char **argv) {

    JsonHelper jh("input_file.json");

    jh.pushBack("{\"name\":\"terry\",\"age\":50}");
    jh.saveFile("temp.json");

    return 0;
}