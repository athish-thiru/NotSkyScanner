#include "airport.h"
#include <iostream>

using namespace std;

/*
Creates a Default Airport where the values are set to unknown and 0
This is because the graph implementation requires the presence of empty airports
for the non-existent source numbers in the OpenFlights dataset
*/
Airport::Airport() {
    name = "UNKNOWN";
    city = "UNKNOWN";
    IATA = "UNKNOWN";
    lon = 0;
    lat = 0;

}

// Getter for airport name
string Airport:: getName() {
    return name;
}

// Getter for airport city
string Airport::getCity() {
    return city;
}

// Getter for airport Latitude
double Airport::getLat() {
    return lat;
}

// Getter for airport Longitude
double Airport:: getLon() {
    return lon;
}

// Getter for airport short name
string Airport::getIATA() {
    return IATA;
}

// Setter for airport name
void Airport::setName(string input) {
    name = input;
}

// Setter for airport city
void Airport::setCity(string input) {
    city = input;
}

// Setter for airport Latitude
void Airport::setIATA(string input) {
    IATA = input;
}

// Setter for airport Longitude
void Airport::setLon(double input) {
    lon = input;
}

// Setter for airport Latitude
void Airport::setLat(double input) {
    lat = input;
}

// Prints out airport information to standard out
void Airport::printAirport() {
    cout << "The Current Airport is " << name << " located in " << city << " which is latitude = " << lat << " and longitude = " << lon << " The IATA Code is " << IATA << endl;
}