#include <airport.h>
#include "vector"

using namespace std;

Airport::Airport() {
    name = "UNKNOWN";
    city = "UNKNOWN";
    IATA = "UNKNOWN";
    lon = 0;
    lat = 0;

}

string Airport:: getName() {
    return name;
}
string Airport::getCity() {
    return city;
}
double Airport::getLat() {
    return lat;
}
double Airport:: getLon() {
    return lon;
}
string Airport::getIATA() {
    return IATA;
}
// double Airport::getAlt() {
//     return alt;
// }

void Airport::setName(string input) {
    name = input;
}
void Airport::setCity(string input) {
    city = input;
}
void Airport::setIATA(string input) {
    IATA = input;
}
void Airport::setLon(double input) {
    lon = input;
}
void Airport::setLat(double input) {
    lat = input;
}
// void Airport::setAlt(double input) {
//     alt = input;
// }

// unordered_map<int, Airport> setMap(string input){
//     std::ifstream aiportdata(filename);
//     string line;
//     unordered_map<int, Airport> ans;
//     while (std::getline(airportdata, line)) {
//         Aiport temp = setMapHelper(line);
//         ans[Airport.]
        
//     }
// }  

vector<Airport> setVector(string input) {
    std::ifstream aiportdata(filename);
    string line;
    vector<Airport> ans;
    ans.push_back(Airport());
    while (std::getline(airportdata, line)) {
        Aiport temp = setVectorHelper(line);
        ans.push_back(temp);
    }
}

Airport setVectorHelper(string line) {
    int counter = 0;
    char character;
    string word = "";
    Airport soln = new Airport();

    for(unsigned i = 0; i < line.size(), i++) {
        character = line[i];
        if (character = ",") {
            if (counter = 1) {
                soln.name = word;
                word = "";
            } else if (counter = 2){
                soln.city = word;
                word = "";
            } else if (counter = 4) {
                soln.IATA = word;
                word = "";
            } else of (counter = 6) {
                soln.lon = word;
                word = "";
            } else if (counter = 7) {
                soln.lat = word;
                word = "";
            } else {
                word = "";
            }

            counter++;
        } else if (character = '"') {
            i++;
        } else {
            word += character;
        }
    }
}