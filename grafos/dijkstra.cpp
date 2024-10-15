#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>


using namespace std;

#define INF 0x3F3F3F3F

map<string, vector<pair<string, int> > > graph;
map<string, int> distances;


void dijkstra(string src){
    priority_queue<pair<int, string>, vector<pair<int, string> >, greater<pair<int, string> > > pq;
    for(auto d: graph){
        distances[d.first] = INF;
    }
    distances[src] = 0;
    pq.push(make_pair(distances[src], src));
    while(!pq.empty()){
        string u = pq.top().second;
        pq.pop();
        for(auto pair: graph[u]){
            if(pair.second + distances[u] < distances[pair.first]){
                distances[pair.first] = pair.second + distances[u];
                pq.push(make_pair(distances[pair.first], pair.first));
            }
        }
    }
}

int main(){


    graph["Alpha"].push_back(make_pair("Beta", 7));
    graph["Alpha"].push_back(make_pair("Lambda", 2));
    graph["Lambda"].push_back(make_pair("Alpha", 2));
    graph["Lambda"].push_back(make_pair("Beta", 1));
    graph["Beta"].push_back(make_pair("Alpha", 7));
    graph["Beta"].push_back(make_pair("Lambda", 1));
    graph["Beta"].push_back(make_pair("Omega", 4));
    graph["Beta"].push_back(make_pair("Sigma", 10));
    graph["Omega"].push_back(make_pair("Beta", 4));
    graph["Sigma"].push_back(make_pair("Beta", 10));
    graph["Sigma"].push_back(make_pair("Delta", 1));
    graph["Delta"].push_back(make_pair("Psi", 3));
    graph["Delta"].push_back(make_pair("Zeta", 1));
    graph["Delta"].push_back(make_pair("Sigma", 1));
    graph["Psi"].push_back(make_pair("Delta", 1));
    graph["Psi"].push_back(make_pair("Zeta", 1));
    graph["Zeta"].push_back(make_pair("Delta", 1));
    graph["Zeta"].push_back(make_pair("Psi", 1));

    dijkstra("Alpha");
    cout << "As menores distancias para os seguintes vertices partindo do verticie Alpha sao: " << endl;
    for(auto p: distances){
        cout << p.first << " -> " << p.second << endl;
    }




    return 0; 
}