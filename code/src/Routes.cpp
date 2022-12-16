//#include "airport_graph.h"
#include "Routes.h"
#include <cmath> 
#include <sstream>
#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

/*
Default Routes Constructor
*/
Routes::Routes() {
    airports_ = setVector("../data/airports.dat");
    std::ifstream routesdata("../data/routes.dat");
    std::vector<int> src_id;
    std::vector<int> dest_id;
    std::vector<long double> dist_vect;
    std::string line; 
    while (std::getline(routesdata, line))
    {
        // Line contains string of length > 0 then save it in vector
        if(line.size() > 0){
            stringstream ss(line);
            vector<string> v;
            while(ss.good()) {
            string substr;
            getline(ss, substr, ',');
            v.push_back(substr);
        }
        //if \N exists instead of source number or destination number skip that line
        if ((v[3] == "\\N") || (v[5] == "\\N")) continue;
        int source_number = std::stoi(v[3]);
        int dest_number = std::stoi(v[5]);
        src_id.push_back(source_number);
        dest_id.push_back(dest_number);
        double dist = distance(source_number, dest_number);
        //std::cout << source_number << " " << dest_number << " " << dist << std::endl;
        dist_vect.push_back(dist);
        }
    }
    src_id_vect_ = src_id;
    dest_id_vect_ = dest_id;
    dist_vect_ = dist_vect;
}

/*
Parametrized Routes Constructor
airportsFile is the input file which contains all the airports
routesFile is the input file which contains all the airport routes
*/
Routes::Routes(string airportsFile,string routesFile) {
    airports_ = setVector(airportsFile);
    std::ifstream routesdata(routesFile);
    std::vector<int> src_id;
    std::vector<int> dest_id;
    std::vector<long double> dist_vect;
    std::string line; 
    while (std::getline(routesdata, line))
    {
        // Line contains string of length > 0 then save it in vector
        if(line.size() > 0){
            stringstream ss(line);
            vector<string> v;
            while(ss.good()) {
            string substr;
            getline(ss, substr, ',');
            v.push_back(substr);
        }
        //if \N exists instead of source number or destination number skip that line
        if ((v[3] == "\\N") || (v[5] == "\\N")) continue;
        int source_number = std::stoi(v[3]);
        int dest_number = std::stoi(v[5]);
        src_id.push_back(source_number);
        dest_id.push_back(dest_number);
        double dist = distance(source_number, dest_number);
        //std::cout << source_number << " " << dest_number << " " << dist << std::endl;
        dist_vect.push_back(dist);
        }
    }
    src_id_vect_ = src_id;
    dest_id_vect_ = dest_id;
    dist_vect_ = dist_vect;
}

/*
Calculates the distance travelled along the circumference along the earth
source_number is the OpenFlights ID for the Source Airport
dest_number is the OpenFlights ID for the Destination Airport
*/
double Routes::distance(int source_number, int dest_number){
    long double source_lat = airports_[source_number].getLat();
    long double source_long = airports_[source_number].getLon();
    long double dest_lat = airports_[dest_number].getLat();
    long double dest_long = airports_[dest_number].getLon();

    // converting the angles stored in degres into radians
    source_lat *= (3.14/180);
    source_long *= (3.14/180);
    dest_lat *= (3.14/180);
    dest_long *= (3.14/180);

    long double d_long = dest_long - source_long;
    long double d_lat = dest_lat - source_lat;
 
    long double ans = pow(sin(d_lat / 2), 2) + cos(source_lat) * cos(dest_lat) * pow(sin(d_long / 2), 2);
 
    ans = 2 * asin(sqrt(ans));
 
    // Radius of Earth in
    // Kilometers, R = 6371
    // Use R = 3956 for miles
    long double R = 6371;
     
    // Calculate the result
    long double distance = ans * R;
 
    return distance;
}

/*
Reads a csv file and converts its content into a vector of airports
The vector of airports is essentially a node list
input is the name of the inputfile
*/
vector<Airport> Routes::setVector(string input) {
    std::ifstream airportdata(input);
    string line;
    
    //creates a vector of unknown airports, since the OpenFlights ID is not continous from 1 to 14110
    vector<Airport> ans;
    for (int i = 0; i < 14111; i++) {
        ans.push_back(Airport());
    }
    
    //parses through the file line by line
    while (std::getline(airportdata, line)) {
        stringstream ss(line);
        stringstream ss2(line);
        vector<string> v;
        vector<string> v2;

        while (ss2.good()) {
        string substr;
        getline(ss2, substr, ',');
        v2.push_back(substr);
        };
        
        Airport temp;
        
        /*
        first case: This is the general case for most lines, 
        data is seperated on basis of ',' and then '"' are
        cleaned out of the data
        */
        try
{
                temp.setLon(stod(v2[6]));
                temp.setLat(stod(v2[7]));
                string str = v2[4];
                str.erase(std::remove(str.begin(),str.end(),'\"'),str.end());
                temp.setIATA(str);
                str = v2[2];
                str.erase(std::remove(str.begin(),str.end(),'\"'),str.end());
                temp.setCity(str);
                str = v2[1];
                str.erase(std::remove(str.begin(),str.end(),'\"'),str.end());
                temp.setName(str);   
                ans[stoi(v2[0])] = temp;
}
/*
Case 2: Some airports have a ',' in their names
(eg - "Harstad/Narvik Airport, Evenes")
so we created a special parsing for that
*/
catch (const std::invalid_argument&)
{
     string substr; 
        getline(ss, substr, ',');
        v.push_back(substr);
        getline(ss, substr, '\"');
        getline(ss, substr, '\"');
        v.push_back(substr);
        getline(ss, substr, '\"');
        getline(ss, substr, '\"');
        v.push_back(substr);
         while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            v.push_back(substr);
        }

                temp.setLon(stod(v[7]));
                temp.setLat(stod(v[8]));
                string str = v[5];
                str.erase(std::remove(str.begin(),str.end(),'\"'),str.end());
                temp.setIATA(str);
                str = v[2];
                str.erase(std::remove(str.begin(),str.end(),'\"'),str.end());
                temp.setCity(str);
                str = v[1];
                str.erase(std::remove(str.begin(),str.end(),'\"'),str.end());
                temp.setName(str); 
                ans[stoi(v[0])] = temp;         
            
}
    }
    return ans;
}


// Getter for the Source ID vector
std::vector<int> Routes::GetSourceNumbers() {return src_id_vect_;}

// Getter for the Destination ID vector
std::vector<int> Routes::GetDestinationNumbers() {return dest_id_vect_;}

// Getter for the Distance vector
std::vector<long double> Routes::GetDistances() {return dist_vect_;}

// Getter for the Airports vector
std::vector<Airport> Routes::GetAirports() {return airports_;}
