#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<int> &disc, vector<int> &low, unordered_map<int, bool>& vis, unordered_map<int, list<int>>& adj, vector<int>& ap, int &timer) {
    vis[node] = true;//mark node as visited
    disc[node] = low[node] = timer++;//mark disc and low = timer, after that inceemnt timer
    int child = 0;//intiialize child as 0
    for(auto neighbour: adj[node]) {
        if(neighbour == parent)
            continue;//ignore if neighbour
        if(!vis[neighbour]) {
            dfs(neighbour, node, disc, low, vis, adj, ap, timer);//do dfs
            low[node] = min(low[node], low[neighbour]);//check current low since in dfs low of subgraph(child low updated so updated current node low) may have been decreased for that child node
            //Check Articulation point
            if(low[neighbour] >= disc[node] && parent != -1) {
                ap[node] = 1;//there is one more path to reach this neighbour node
            }
            child++;//since not visited so this is a child node
        } else {
            low[node] = min(low[node], disc[neighbour]);//child node connected to ancestor node so another path exist to reach child node 
        }
    }
    if(parent == -1 && child > 1) {
        ap[node] = 1;
    }
}

int main () {
    int n = 5;
    int e = 5;
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(3, 4));
    edges.push_back(make_pair(0, 4));
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(1, 2));

    //adj list
    unordered_map<int, list<int>> adj;

    for(int i = 0; i < edges.size(); i++) {
        int u =edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;//this will keep increasing by 1 for each node
    vector<int> disc(n);
    vector<int> low(n);
    unordered_map<int, bool> vis;
    vector<int> ap(n, 0);

    for(int i = 0; i < n; i++) {//initializing disc and low with -1
        disc[i] = -1;
        low[i] = -1;
    }

    //dfs
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i, -1, disc, low, vis, adj, ap, timer);
        }
    }

    //print articulation points
    cout << "Articulation points are as follows:"<< endl;
    for(int i = 0; i < n; i++) {
        if(ap[i] != 0) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}