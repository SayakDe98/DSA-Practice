#include <bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    // Write your code here.
    // Create an Adjacency List
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int weight = vec[i][2];

        // Create neighbours
        adj[u].push_back(make_pair(v, weight));
        adj[v].push_back(make_pair(u, weight));
    }

    // Create distance array
    vector<int> dist(vertices);
    for (int i = 0; i < vertices; i++)
    {
        dist[i] = INT_MAX; // initialize with INT_MAX
    }
    // Update distance of source node to 0
    dist[source] = 0;
    // Create a set(node dist, node)
    set<pair<int, int>> st;
    st.insert(make_pair(0, source)); // insert the source node

    while (!st.empty())
    {
        auto top = *(st.begin());
        int nodeDistance = top.first;
        int topNode = top.second;

        // remove top node
        st.erase(st.begin());

        // traverse neighbours
        for (auto neighbour : adj[topNode])
        {
            if (nodeDistance + neighbour.second < dist[neighbour.first])
            {
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));

                if (record != st.end()) // remove the record if found in set
                    st.erase(record);
                dist[neighbour.first] = nodeDistance + neighbour.second;
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
    return dist;
}
