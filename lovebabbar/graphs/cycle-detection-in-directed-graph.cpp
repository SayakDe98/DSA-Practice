#include <bits/stdc++.h>
bool isCyclicDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> &adj)
{
    // mark current node as visited
    visited[node] = 1;
    // mark current node as dfsVisited
    dfsVisited[node] = 1;

    // Run a loop over all neighbours of node
    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            bool cyclePresent = isCyclicDFS(neighbour, visited, dfsVisited, adj);
            if (cyclePresent)
                return true; // recursively find if cycle present
        }
        else if (dfsVisited[neighbour])
        {
            return true; // if dfsVisited[neighbour] = true and visited[neighbour] = true, cycle found
        }
    }
    dfsVisited[node] = false; // as we don't have any more neighbours to visit so mark this node as dfs unvisited
    return false;             // no cycle found
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    // Write your code here.
    // Create adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        // This is directed graph so only one direction neighbour
        adj[u].push_back(v);
    }

    // Create visited and dfsVisited DS
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    // Loop over all the disconnected components
    for (int i = 1; i <= n; i++)
    { // in question it is told we start from node 1 to node n
        if (!visited[i])
        {
            bool cyclePresent = isCyclicDFS(i, visited, dfsVisited, adj);
            if (cyclePresent)
                return true;
        }
    }
    return false; // cycle not present
}