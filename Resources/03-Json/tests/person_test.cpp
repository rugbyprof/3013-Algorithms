#include "../json.hpp"
#include <fstream>
#include <iostream>

using namespace std;
using namespace nlohmann;

/*
int id
string first_name
string last_name
string email
string address
string city
string state
double latitude
double longitude
string car
string car_model
string car_color
string pet
string job_title
string phone_number
vector <string> stocks

1, 'Hestia', 'McCathie', 'hmccathie0@state.gov', '14351 Lukken Court', 'Boston', 'MA', 42.3231, -71.0846, 'Dodge', 'Neon', 'Mauv', 'Plover, three-banded', 'Research Associate', '(978) 1569024', {'stock1':'RNWK','stock2':'FOMX','stock3':'NMZ','stock4':'PEB^C','stock5':'TPIV','stock6':'TRUE','stock7':'CNCO'}
*/

int main() {

    std::ifstream i("../data/random_person_data_1.json");
    json j;
    i >> j;

    for (auto &[key, value] : j.items()) {
        std::cout << key << " : " << value << "\n";
        for (auto &[key2, value2] : value.items()) {
            std::cout << key2 << " : " << value2 << "\n";
        }
    }
}