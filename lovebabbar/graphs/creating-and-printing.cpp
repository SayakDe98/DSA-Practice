vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<int> ans[n]; // stores neighbours(edges which are neighbours)
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0]; // get edge u
        int v = edges[i][1]; // get edge v
        // undirected graph so u and v both will be neighbour of each other
        ans[u].push_back(v);
        ans[v].push_back(u);
    }

    vector<vector<int>> adj(n); // stores answer
    for (int i = 0; i < n; i++)
    {                        // it runs for all the nodes
        adj[i].push_back(i); // answer is formatted this way

        for (int j = 0; j < ans[i].size(); j++)
        { // add the neighbours to adj array
            adj[i].push_back(ans[i][j]);
        }
    }
    return adj;
}