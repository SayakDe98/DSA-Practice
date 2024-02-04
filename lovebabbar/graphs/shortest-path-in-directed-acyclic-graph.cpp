#include<bits/stdc++.h>
using namespace std;

class Graph {//create class graph
    public:
    unordered_map<int, list<pair<int, int>>> adj;//adjacency list

    void addEdge(int u, int v, int weight) {//method to add edge to graph
        pair<int, int> p = make_pair(v, weight);//create a pair for edge to which we want to connect and weight
        adj[u].push_back(p);//directed graph(one way directed) so edge is from u to v and not from v to u
    }//T.c.:O(N)

    void printAdj() {//prints adj list
        for(auto i: adj) {
            cout << i.first << " -> ";
            for(auto j: i.second)
                cout << "(" << j.first << ", " << j.second << ")" << endl;
            cout << endl;
        }
    }

    void dfs(int node, unordered_map<int, bool>& vis, stack<int>& topo) {//topological sort using dfs
        vis[node] = true;
        for(auto neighbor: adj[node]) {
            if(!vis[neighbor.first])
                dfs(neighbor.first, vis, topo);
        }
        topo.push(node);
    }

    void getShortestPath(int src, vector<int>& dist, stack<int>& topo) {
        dist[src] = 0; // source distance will be 0 because we start from src(source) and shortest path to src node is 0
        while (!topo.empty())
        {
            int top = topo.top();//store top of stack in variable
            topo.pop();//pop the top of stack

            if(dist[top] != INT_MAX) {//if an edge exists between src and topo
                for(auto neighbour: adj[top]) {
                    if(dist[top] + neighbour.second < dist[neighbour.first]) //updating minimum distance
                        dist[neighbour.first] = dist[top] + neighbour.second;
                }
            }
        }
    }
};

int main () {
    Graph g;
    //add edges to graph. First value is the vertex from where edge starts,
    //second value is the vertex till where the edge exists and last parameter is the weight of the edge 
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
    cout << "Printing adj list:" << endl;
    g.printAdj();

    int n = 6;
 
    //topological sort
    unordered_map<int, bool> visited;//visited DS
    stack<int> s;//DS for dfs
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            g.dfs(i, visited, s);
        }
    }
    int src = 1;//source node/vertex
    vector<int> dist(n);//distance is of size n
    for(int i = 0; i < n; i++)
        dist[i] = INT_MAX;//assuming no edge exists between src and node i
    g.getShortestPath(src, dist, s);

    cout << "Answer is: " << endl;

    for(auto i: dist) 
        cout << i << " ";//Printing distance
    cout << endl;
    return 0;
}