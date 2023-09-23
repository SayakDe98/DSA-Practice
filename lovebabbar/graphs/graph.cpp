#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;

template <typename T > // making the data type generic

class graph {
    
    public:
        unordered_map<T, list<T> > adj;
    
    void addEdge (T u, T v, bool direction) {
        // direction = 0 -> undirected
        // directed = 1 -> directed

        // create an edge from u to v
        adj[u].push_back(v);
        if (direction == 0) { // undirected graph
            adj[v].push_back(u);
        }
    }

    void printAdjacencyList () {
        for (auto i: adj) {
            cout << i.first << "->";
            for (auto j: i.second) {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
 
};

int main () {

    int n;
    cout << "Enter the number of nodes: " << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges: " << endl;
    cin >> m;

    graph<int> g;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0); // undirected graph with edges u and v
    }

    // print the graph created:
    g.printAdjacencyList();
    return 0;
}

// To run this code go to graph directory and run command: g++ graph.cpp -o main && ./main
// Enter number of nodes: 5 Press enter
// Enter number od edges: 6 Press enter
// 0 1 Press enter
// 1 2 Press enter
// 2 3 Press enter
// 3 1 Press enter
// 4 0 Press enter
// Press enter to get answer