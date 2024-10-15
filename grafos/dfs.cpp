#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <stack>

using namespace std;

map<string, vector<string> > graph;

vector<string> DFS(string src){
    set<string> visited;
    vector<string> res;
    stack<string> st;
    st.push(src);
    res.push_back(src);
    while(!st.empty()){
        string u = st.top();
        st.pop();
        if(u != src){
            res.push_back(u);
        }
        for(string s: graph[u]){
            if(visited.count(s) == 0){
                st.push(s);
                visited.insert(s);
            }
        }
    }
    return res;
}

int main(){


    graph["Alpha"].push_back("Beta");
    graph["Alpha"].push_back("Lambda");
    graph["Lambda"].push_back("Alpha");
    graph["Lambda"].push_back("Beta");
    graph["Beta"].push_back("Alpha");
    graph["Beta"].push_back("Lambda");
    graph["Beta"].push_back("Omega");
    graph["Beta"].push_back("Sigma");
    graph["Omega"].push_back("Beta");
    graph["Sigma"].push_back("Beta");
    graph["Sigma"].push_back("Delta");
    graph["Delta"].push_back("Psi");
    graph["Delta"].push_back("Zeta");
    graph["Delta"].push_back("Sigma");
    graph["Psi"].push_back("Delta");
    graph["Psi"].push_back("Zeta");
    graph["Zeta"].push_back("Delta");
    graph["Zeta"].push_back("Psi");

    vector<string> res = DFS("Alpha");
    for(int i = 0; i < res.size(); ++i){
        cout << res[i] << endl;
    }



    return 0; 
}