#include <bits/stdc++.h>
void dfs(int node, int parent, int &timer, vector<int> &discovery, vector<int> &low, vector<vector<int>> &result, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited)
{
    visited[node] = true;
    discovery[node] = low[node] = timer++;

    for (auto neighbour : adj[node])
    {
        if (neighbour == parent)
            continue;
        if (!visited[neighbour])
        {
            dfs(neighbour, node, timer, discovery, low, result, adj, visited);
            low[node] = min(low[node], low[neighbour]); // neighbour may be connected by back edge then update low so update own low
            // check edge is bridge or not
            if (low[neighbour] > discovery[node])
            {
                vector<int> ans;
                // bridge present so push in result
                ans.push_back(node);
                ans.push_back(neighbour);
                result.push_back(ans);
            }
        }
        else
        {
            // node already visited and not parent
            // Back Edge
            low[node] = min(low[node], discovery[neighbour]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    // Write your code here
    // Create adj list
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> discovery(v); // discovery DS
    vector<int> low(v);       // Earliest time
    int parent = -1;
    unordered_map<int, bool> visited;

    for (int i = 0; i < v; i++)
    {
        discovery[i] = -1;
        low[i] = -1;
    }

    vector<vector<int>> result;
    // dfs
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
            dfs(i, parent, timer, discovery, low, result, adj, visited);
    }
    return result;
}