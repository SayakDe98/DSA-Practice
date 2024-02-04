#include <bits/stdc++.h>
void topo(int node, unordered_map<int, list<int>> &adj, vector<bool> &visited, stack<int> &s)
{
    visited[node] = 1; // mark node as visited

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            topo(neighbour, adj, visited, s);
        }
    }
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // Write your code here

    // Create adj list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0]; // first vertex
        int v = edges[i][1]; // second vertex

        adj[u].push_back(v);
    }

    // Create visited DS
    vector<bool> visited(v);

    stack<int> s;
    // Loop over all the disconnected components for dfs topological sort utility function
    for (int i = 0; i < v; i++)
    { // we are starting from 0th node(see in picture)
        if (!visited[i])
        {
            topo(i, adj, visited, s);
        }
    }

    // Create answer DS
    vector<int> ans;

    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}