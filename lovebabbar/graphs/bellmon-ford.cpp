vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<int> dist(n + 1, 1e8);
    dist[src] = 0;
    for (int i = 1; i < n; i++)
    {
        // travserse on edge list
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] != 1e9 && (dist[u] + wt) < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }
    return dist;
    // check for -ve cycle, the graph dosent contain -ve cycle stll showing code for understanding
    //  bool flag = 0;
    //     for(int j = 0; j < m; j++) {
    //          int u = edges[j][0];
    //          int v = edges[j][1];
    //          int wt = edges[j][2];

    //         if(dist[u] != 1e9 && (dist[u] + wt) < dist[v]) {
    //             flag = true;
    //         }
    //     }
    // if(flag == 0) {
    //     return dist;
    // }
    // return -1;
}