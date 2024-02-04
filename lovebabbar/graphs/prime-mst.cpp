#include <bits/stdc++.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    // Create adj list
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // Create 3 DS
    vector<int> key(n + 1);
    vector<bool> mst(n + 1);
    vector<int> parent(n + 1);

    for (int i = 0; i <= n; i++)
    { // initialize the DS
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    // Let's start the algo
    key[1] = 0;     // source node is 1 so it takes 0 distance to reach 1
    parent[1] = -1; // parent unknown so mark it as -1

    for (int i = 1; i < n; i++)
    {                       // loop for all edges
        int mini = INT_MAX; // for comparision
        int u;
        // finding min node
        for (int v = 1; v <= n; v++)
        { // O(n^2), if we use min heap then we can take min value in O(1)
            if (mst[v] == false && key[v] < mini)
            { // if min heap we would get O(nlogn) TC
                u = v;
                mini = key[v];
            }
        }

        // mark min node as true
        mst[u] = true;

        // check its adj nodes
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if (mst[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;
    for (int i = 2; i <= n; i++)
    { // we start from 2 because 1's parent is -1
        result.push_back({{parent[i], i}, key[i]});
    }
    return result;
}
