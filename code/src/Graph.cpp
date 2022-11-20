//Graphs Class

#include "/workspaces/CS225/NotSkyScanner-main/code/src/airport.h"
#include "/workspaces/CS225/NotSkyScanner-main/code/src/Routes.h"
#include "/workspaces/CS225/NotSkyScanner-main/code/src/Graph.h"
#include <math.h> 
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <fstream>
#include <bits/stdc++.h>


using namespace std;


//construct the vertices 
//such that each airport object is connected with its ID

void addEdge(vector <pair<int, long double> > adj, int source_number, int destination_number, long double distance)
{
    adj[source_number] = (make_pair(destination_number, distance));
}
void addAllEdges(){
//open file
//i = 0

    for(int i = 0; i<src_id.size(); i++){
    int source_number = stoi(src_id[i]); //gives the index of the source airport as in the airport vector (i is the index per line)
    int dest_number = stoi(dest_id[i]);//gives the index of the destination as in the airport vector (i is the index per line)
    long double distance = dist_vect[i];//distance between the airports (i is index per line)
    addEdge(adj, src_id, dest_id, distance);
    }
}

void printGraph(vector<pair<int,long double> > adj[], int V)
{
    for (int i = 0; i < V; i++)
    {
        cout << "source airport " << i << " is connected to \n";
        for (auto it = adj[i].begin(); it!=adj[i].end(); it++)
        {
            int v = it->first;
            long double w = it->second;
            cout << "\tdestination " << v << " with distance"
                 << w << "\n";
        }
        cout << "\n";
    }
}

// void listAdjacentNodes(vector<pair<int,long double> > adj[], int m){

//     printf("%d", m);
//     for(int j = 0; j < adj[m].size(); ++j){
//         printf(" -> %d (w:%d)", adj[m][j].first, adj[m][j].second);
//     }

// }

vector<Airport> Parser::setVector() {
    std::ifstream airportdata("/workspaces/CS225/NotSkyScanner-main/NotSkyScanner/data/airports.dat");
    string line;
    
    vector<Airport> ans;
    for (int i = 0; i < 14101; i++) {
        ans.push_back(Airport());
    }
    while (std::getline(airportdata, line)) {
        stringstream ss(line);
        stringstream ss2(line);
        vector<string> v;
        vector<string> v2;
          
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
   

        // for (int i = 0; i < v.size(); i++) {
        //     cout << v[i] << "  ";
        // }
   //     cout << "done" << endl;
        Airport temp;
   //     cout << v[1] << " " << v[2] << " " << v[4] << " " << v[7] << " " << v[8] << endl;

        if (isdigit(atoi(v[8].c_str())) && isdigit(atoi(v[7].c_str())) ) {  
          //  cout << "done1" << endl;
                temp.setLon(stod(v[7]));
                temp.setLat(stod(v[8]));
                string str = v[4];
                str.erase(std::remove(str.begin(),str.end(),'\"'),str.end());
                temp.setIATA(str);
                str = v[2];
                str.erase(std::remove(str.begin(),str.end(),'\"'),str.end());
                temp.setCity(str);
                str = v[1];
                str.erase(std::remove(str.begin(),str.end(),'\"'),str.end());
                temp.setName(str); 
                ans[stoi(v[0])] = temp;  
        } else {
          //  cout << "done2" << endl;
            while (ss2.good()) {
            string substr;
            getline(ss2, substr, ',');
            v2.push_back(substr);
            }

                temp.setLon(stod(v2[7]));
                temp.setLat(stod(v2[8]));
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
        //ans.push_back(temp); 
    }
    cout << ans.size() << endl;
    return ans;
}






