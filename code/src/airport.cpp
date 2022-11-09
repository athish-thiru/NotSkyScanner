#include <airport.h>

using namespace std;

string getName() {
    return name;
}
string getCity() {
    return city;
}
double getLat() {
    return lat;
}
double getLon() {
    return lon;
}
string getIATA() {
    return IATA;
}
double getAlt() {
    return alt;
}

void setName(string input) {
    name = input;
}
void setCity(string input) {
    city = input;
}
void setIATA(string input) {
    IATA = input;
}
void setLon(double input) {
    lon = input;
}
void setLat(double input) {
    lat = input;
}
void setAlt(double input) {
    alt = input;
}